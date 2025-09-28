#include "InterfaceMainMenu.h"

void InterfaceMainMenu::ShowMainMenu(Utils& utils, SetupConsole& setupConsole)
{
	system("cls");

	this->showMainMenu = false;

	constexpr auto delay = 200ms;
	constexpr auto delayLetter = 100ms;

	this_thread::sleep_for(delay);

	setupConsole.SetTextColor(2);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	const int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	const int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	const string letters = "--SIGNAL LOST--";
	const int glyphCount = static_cast<int>(letters.size());
	const int titleWidth = ((glyphCount - 1) * 7) + 5;
	const int titleHeight = 5;

	int posX = (consoleWidth - titleWidth) / 2;
	int posY = 4;

	for (char ch : letters)
	{
		utils.DrawLetter(ch, posX, posY);

		posX += 7;
		this_thread::sleep_for(delayLetter);
	}

	setupConsole.SetTextColor(7);
	this_thread::sleep_for(delay);

	const int boxWidth = 21;
	const int boxHeight = 11;
	const int boxLeft = (consoleWidth - boxWidth) / 2;
	const int boxTop = (consoleHeight - boxHeight) / 2;

	DrawBox(utils, boxLeft, boxTop, boxWidth, boxHeight);

	setupConsole.SetTextColor(1);
	this_thread::sleep_for(delay);

	vector<string> menuItems =
	{
		"1 - Start",
		"2 - Settings",
		"3 - Credits",
		"4 - Quit"
	};

	for (int i = 0; i < menuItems.size(); ++i)
	{
		int textX = boxLeft + 4;
		int textY = boxTop + 2;
		utils.PosCursor(textX, textY + i * 2);
		cout << menuItems[i] << endl;
	}

	setupConsole.SetTextColor(7);

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	char inputChoice = _getch();

	switch (inputChoice)
	{
		case '1':
		{
			return;
		}
		case '2':
		{
			ShowSettings(utils, setupConsole);
			break;
		}
		case '3':
		{
			ShowCredits(utils, setupConsole);
			break;
		}
		case '4':
		{
			utils.PosCursor(0, 30);
			exit(EXIT_SUCCESS);
		}
		default:
		{
			break;
		}
	}
}

void InterfaceMainMenu::DrawBox(Utils& utils, int left, int top, int width, int height) const
{
	utils.PosCursor(left, top);
	for (int i = 0; i < width; ++i)
	{
		cout << ((i == 0 || i == width - 1) ? char(219) : char(223));
	}

	for (int y = 1; y < height - 1; ++y)
	{
		utils.PosCursor(left, top + y);
		cout << char(219);
		utils.PosCursor(left + width - 1, top + y);
		cout << char(219);
	}

	utils.PosCursor(left, top + height - 1);
	for (int i = 0; i < width; ++i)
	{
		cout << ((i == 0 || i == width - 1) ? char(219) : char(220));
	}
}

void InterfaceMainMenu::UpdateSettingSoundActivated(Utils& utils, SetupConsole& setupConsole, int right, int top)
{
	setupConsole.SetTextColor(2);

	utils.PosCursor(right, top);

	cout << (setupConsole.GetSoundActivated() ? "ON " : "OFF");

	setupConsole.SetTextColor(7);
}

void InterfaceMainMenu::UpdateSettingFontSize(Utils& utils, SetupConsole& setupConsole, int right, int top)
{
	setupConsole.SetTextColor(2);

	utils.PosCursor(right, top);
	cout << setupConsole.GetFontSize() << "px" << endl;

	setupConsole.SetTextColor(7);
}

void InterfaceMainMenu::ShowSettings(Utils& utils, SetupConsole& setupConsole)
{
	system("cls");

	constexpr auto delay = 200ms;
	constexpr auto delayLetter = 100ms;

	this_thread::sleep_for(delay);

	setupConsole.SetTextColor(2);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	const int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	const int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	const string letters = "SETTINGS";
	const int glyphCount = static_cast<int>(letters.size());
	const int titleWidth = ((glyphCount - 1) * 7) + 5;
	const int titleHeight = 5;

	int posX = (consoleWidth - titleWidth) / 2;
	int posY = 4;

	for (char ch : letters)
	{
		utils.DrawLetter(ch, posX, posY);

		posX += 7;
		this_thread::sleep_for(delayLetter);
	}

	setupConsole.SetTextColor(7);
	this_thread::sleep_for(delay);

	const int boxWidth = 26;
	const int boxHeight = 9;
	const int boxLeft = (consoleWidth - boxWidth) / 2;
	const int boxTop = (consoleHeight - boxHeight) / 2;

	DrawBox(utils, boxLeft, boxTop, boxWidth, boxHeight);

	setupConsole.SetTextColor(1);
	this_thread::sleep_for(delay);

	vector<string> menuItems =
	{
		"1 - Sound:",
		"2 - FontSize:",
		"3 - Back",
	};

	for (int i = 0; i < menuItems.size(); ++i)
	{
		int textX = boxLeft + 4;
		int textY = boxTop + 2;
		utils.PosCursor(textX, textY + i * 2);
		cout << menuItems[i] << endl;
	}

	setupConsole.SetTextColor(7);

	UpdateSettingSoundActivated(utils, setupConsole, boxLeft + boxWidth - 8, boxTop + 2);
	UpdateSettingFontSize(utils, setupConsole, boxLeft + boxWidth - 8, boxTop + 4);

	const vector<int> FONT_SIZES = { 14, 18, 22, 26, 30, 34 };
	bool exitSettings = false;

	while (!exitSettings)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

		char inputChoice = _getch();

		switch (inputChoice)
		{
			case '1':
			{
				setupConsole.SetSoundActivated(!setupConsole.GetSoundActivated());
				UpdateSettingSoundActivated(utils, setupConsole, boxLeft + boxWidth - 8, boxTop + 2);

				break;
			}
			case '2': 
			{
				HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
				int currentSize = setupConsole.GetFontSize();
				auto it = find(FONT_SIZES.begin(), FONT_SIZES.end(), currentSize);

				if (it != FONT_SIZES.end())
				{
					setupConsole.SetFontSize(out, *(++it == FONT_SIZES.end() ? FONT_SIZES.begin() : it));
				}

				UpdateSettingFontSize(utils, setupConsole, boxLeft + boxWidth - 8, boxTop + 4);

				break;
			}
			case '3': 
			{
				ShowMainMenu(utils, setupConsole);
				exitSettings = true;

				break;
			}
			default:
			{
				break;
			}
		}
	}

	ShowMainMenu(utils, setupConsole);
}

void InterfaceMainMenu::ShowCredits(Utils& utils, SetupConsole& setupConsole)
{
	system("cls");

	constexpr auto delay = 200ms;
	constexpr auto delayLetter = 100ms;
	constexpr auto delayCredits = 10s;

	this_thread::sleep_for(delay);

	setupConsole.SetTextColor(2);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	const int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	const int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	const string letters = "CREDITS";
	const int glyphCount = static_cast<int>(letters.size());
	const int titleWidth = ((glyphCount - 1) * 7) + 5;
	const int titleHeight = 5;

	int posX = (consoleWidth - titleWidth) / 2;
	int posY = 4;

	for (char ch : letters)
	{
		utils.DrawLetter(ch, posX, posY);

		posX += 7;
		this_thread::sleep_for(delayLetter);
	}

	setupConsole.SetTextColor(7);
	this_thread::sleep_for(delay);

	const int boxWidth = 62;
	const int boxHeight = 17;
	const int boxLeft = (consoleWidth - boxWidth) / 2;
	const int boxTop = (consoleHeight - boxHeight) / 2;

	DrawBox(utils, boxLeft, boxTop, boxWidth, boxHeight);

	setupConsole.SetTextColor(1);
	this_thread::sleep_for(delay);

	struct CreditEntry 
	{
		string role;
		string name;
	};

	vector<CreditEntry> menuItems = 
	{
		{"Project Manager & Lead Game Designer:", "Baptiste PERRIN"},
		{"Game Designer:", "Loic VAREILLES"},
		{""},
		{"Lead Game Programmer:", "Killian FURNO"},
		{"Game Programmer:", "Adrien LECHAT"},
		{"Game Programmer:", "Hortense MARIE"},
		{"Game Programmer:", "Florian MARTINS"},
	};

	size_t maxRoleLen = 0;
	for (auto& c : menuItems)
	{
		maxRoleLen = max(maxRoleLen, c.role.size());
	}

	for (size_t i = 0; i < menuItems.size(); ++i) 
	{
		utils.PosCursor(boxLeft + 4, boxTop + 2 + static_cast<int>(i) * 2);

		setupConsole.SetTextColor(1);
		cout << left << setw(static_cast<int>(maxRoleLen) + 2) << menuItems[i].role;

		setupConsole.SetTextColor(2);
		cout << menuItems[i].name << endl;
	}

	setupConsole.SetTextColor(7);

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	auto waited = 0ms;
	constexpr auto delayWait = 20ms;
	while (waited < delayCredits)
	{
		if (_kbhit()) 
		{
			(void)_getch();
			break;
		}

		this_thread::sleep_for(delayWait);

		waited += delayWait;
	}

	ShowMainMenu(utils, setupConsole);
}