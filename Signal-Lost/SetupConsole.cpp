#include "Main.h"

constexpr wstring_view appName = L"Signal Lost";
constexpr wstring_view fontName = L"Clarendon";

struct ConsoleSettings 
{
	int width = 120;
	int height = 40;
};

struct ScreenFont 
{
	int minWidth = 0;
	int fontSize = 0;
};

constexpr auto fontMap = to_array<ScreenFont>(
{ 
	{3840, 34},
	{2560, 30},
	{1920, 26},
	{1680, 22},
	{1280, 18},
	{0, 14},
});

/// <summary>
/// Setup the Name of the Console
/// </summary>
static void SetupName()
{
	// Name of the Console
	SetConsoleTitleW(appName.data());
}

/// <summary>
/// Check if the Instance is Already Running
/// </summary>
static void CheckInstance()
{
	// Instance Running
	HANDLE mutex = CreateMutexW(nullptr, TRUE, appName.data());

	// Check the Creation Failed
	if (!mutex || GetLastError() == ERROR_ALREADY_EXISTS)
	{
		if (mutex)
		{
			// Close the Window
			CloseHandle(mutex);
		}

		exit(EXIT_SUCCESS);
	}
}

/// <summary>
/// Set the Position of the Console on the Desktop
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
static void SetConsoleWindowPosition(HWND window, int screenWidth, int screenHeight)
{
	// Get the Console Window Size
	RECT consoleRect{};
	GetWindowRect(window, &consoleRect);

	// Calculate
	int x = (screenWidth - (consoleRect.right - consoleRect.left)) / 2;
	int y = (screenHeight - (consoleRect.bottom - consoleRect.top)) / 2;

	// Set the Position
	SetWindowPos(window, nullptr, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

/// <summary>
/// Size the Console
/// </summary>
/// <param name="outHandle"></param>
/// <param name="width"></param>
/// <param name="height"></param>
static void ResizeConsole(HANDLE outHandle, int width, int height)
{
	COORD buffer 
	{ 
		static_cast<SHORT>(width), static_cast<SHORT>(height),
	};

	// Set the Screen Buffer Size
	SetConsoleScreenBufferSize(outHandle, buffer);

	SMALL_RECT rect
	{ 
		0,
		0,
		static_cast<SHORT>(width - 1),
		static_cast<SHORT>(height - 1),
	};

	// Set the Window Size
	SetConsoleWindowInfo(outHandle, TRUE, &rect);
}

/// <summary>
/// Set the Font of the Console
/// </summary>
/// <param name="outHandle"></param>
/// <param name="size"></param>
static void SetConsoleFontSize(HANDLE outHandle, int size)
{
	CONSOLE_FONT_INFOEX info
	{ 
		sizeof info,
	};

	// Get the Current Font
	if (GetCurrentConsoleFontEx(outHandle, FALSE, &info)) 
	{
		// Set the Font
		info.dwFontSize.Y = static_cast<SHORT>(size);
		wcscpy_s(info.FaceName, fontName.data());
		SetCurrentConsoleFontEx(outHandle, FALSE, &info);
	}
}

/// <summary>
/// Set the Console
/// </summary>
static void DefineConsole(HWND window)
{
	// Get the Handles
	HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	// Desactivated F11
	DWORD inMode{};
	GetConsoleMode(in, &inMode);
	SetConsoleMode(in, inMode & ~ENABLE_PROCESSED_INPUT);

	// Resize the Console
	RECT desk{};
	GetWindowRect(GetDesktopWindow(), &desk);
	int screenW = desk.right - desk.left;
	int screenH = desk.bottom - desk.top;

	ConsoleSettings consoleSettings;
	ResizeConsole(out, consoleSettings.width, consoleSettings.height);

	// Set the Font Size by the Screen Width
	for (const auto& entry : fontMap) 
	{
		if (screenW >= entry.minWidth) 
		{
			SetConsoleFontSize(out, entry.fontSize);
			break;
		}
	}

	// Wait for the Resize and the Font to Apply
	Sleep(1);

	// Center the Console
	SetConsoleWindowPosition(window, screenW, screenH);

	// Hide the Cursor
	CONSOLE_CURSOR_INFO ci
	{ 
		1,
		FALSE,
	};

	SetConsoleCursorInfo(out, &ci);

	// Disable the Resize
	LONG style = GetWindowLongW(window, GWL_STYLE);
	style &= ~(WS_MAXIMIZEBOX | WS_SIZEBOX);
	SetWindowLongW(window, GWL_STYLE, style);

	// Disable thr Mouse Paused
	DWORD flags{};
	GetConsoleMode(in, &flags);
	SetConsoleMode(in, flags & ENABLE_EXTENDED_FLAGS);
}

/// <summary>
/// Initialise the Console
/// </summary>
void InitConsole()
{
	HWND window = GetConsoleWindow();

	ShowWindow(window, SW_HIDE);

	SetupName();

	CheckInstance();

	DefineConsole(window);

	ShowWindow(window, SW_SHOW);
}