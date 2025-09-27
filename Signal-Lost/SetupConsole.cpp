#include "SetupConsole.h"

/// <summary>
/// Setup the Path of the Game
/// </summary>
void SetupConsole::SetupPath()
{
	wchar_t buffer[MAX_PATH];
	GetModuleFileNameW(nullptr, buffer, MAX_PATH);

	filesystem::path exePath = buffer;
	wstring pathFolder = exePath.parent_path().wstring() + L'\\';
	this->pathGameFolder = string(pathFolder.begin(), pathFolder.end());
}

/// <summary>
/// Setup the Name of the Console
/// </summary>
void SetupConsole::SetupName() const
{
	SetConsoleTitleW(appName.data());
}

/// <summary>
/// Check if the Instance is Already Running
/// </summary>
void SetupConsole::CheckInstance() const
{
	HANDLE mutex = CreateMutexW(nullptr, TRUE, appName.data());

	if (!mutex || GetLastError() == ERROR_ALREADY_EXISTS)
	{
		if (mutex)
		{
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
void SetupConsole::CenterWindow(HWND window, int screenWidth, int screenHeight) const
{
	RECT consoleRect{};
	GetWindowRect(window, &consoleRect);

	int x = (screenWidth - (consoleRect.right - consoleRect.left)) / 2;
	int y = (screenHeight - (consoleRect.bottom - consoleRect.top)) / 2;

	SetWindowPos(window, nullptr, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

/// <summary>
/// Size the Console
/// </summary>
/// <param name="outHandle"></param>
/// <param name="width"></param>
/// <param name="height"></param>
void SetupConsole::ResizeConsole(HANDLE outHandle, int width, int height) const
{
	COORD buffer 
	{ 
		static_cast<SHORT>(width), static_cast<SHORT>(height),
	};

	SetConsoleScreenBufferSize(outHandle, buffer);

	SMALL_RECT rect
	{ 
		0,
		0,
		static_cast<SHORT>(width - 1),
		static_cast<SHORT>(height - 1),
	};

	SetConsoleWindowInfo(outHandle, TRUE, &rect);
}

/// <summary>
/// Set the Font of the Console
/// </summary>
/// <param name="outHandle"></param>
/// <param name="size"></param>
void SetupConsole::SetFontSize(HANDLE outHandle, int size) const
{
	CONSOLE_FONT_INFOEX info
	{ 
		sizeof info,
	};

	if (GetCurrentConsoleFontEx(outHandle, FALSE, &info)) 
	{
		info.dwFontSize.Y = static_cast<SHORT>(size);
		wcscpy_s(info.FaceName, fontName.data());
		SetCurrentConsoleFontEx(outHandle, FALSE, &info);
	}
}

/// <summary>
/// Set the Text Color of the Console
/// </summary>
/// <param name="indexColor"></param>
void SetupConsole::SetTextColor(int indexColor) const
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(consoleHandle, indexColor);
}

/// <summary>
/// Set the Console
/// </summary>
void SetupConsole::DefineConsole(HWND window) const
{
	HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	DWORD inMode{};
	GetConsoleMode(in, &inMode);
	SetConsoleMode(in, inMode & ~ENABLE_PROCESSED_INPUT);

	RECT desk{};
	GetWindowRect(GetDesktopWindow(), &desk);
	int screenW = desk.right - desk.left;
	int screenH = desk.bottom - desk.top;

	ConsoleSettings consoleSettings{};
	ResizeConsole(out, consoleSettings.width, consoleSettings.height);

	for (const auto& entry : fontMap) 
	{
		if (screenW >= entry.minWidth) 
		{
			SetFontSize(out, entry.fontSize);
			break;
		}
	}

	Sleep(1);

	CenterWindow(window, screenW, screenH);

	CONSOLE_CURSOR_INFO ci
	{ 
		1,
		FALSE,
	};

	SetConsoleCursorInfo(out, &ci);

	LONG style = GetWindowLongW(window, GWL_STYLE);
	style &= ~(WS_MAXIMIZEBOX | WS_SIZEBOX);
	SetWindowLongW(window, GWL_STYLE, style);

	DWORD flags{};
	GetConsoleMode(in, &flags);
	SetConsoleMode(in, flags & ENABLE_EXTENDED_FLAGS);
}

/// <summary>
/// Initialise the Console
/// </summary>
void SetupConsole::InitConsole()
{
	HWND window = GetConsoleWindow();

	ShowWindow(window, SW_HIDE);

	SetupPath();

	SetupName();

	CheckInstance();

	DefineConsole(window);

	ShowWindow(window, SW_SHOW);
}