#include "InterfaceMainMenu.h"

void InterfaceMainMenu::ShowMainMenu(Utils& utils, SetupConsole& setupConsole)
{
	system("cls");

	const int delay = 200;
	const int delayLetter = 100;

	Sleep(delay);

	setupConsole.SetTextColor(2);

	int posX = 9;
	int posY = 4;

	utils.LetterHyphen(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterHyphen(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterS(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterI(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterG(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterN(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterA(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterL(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterSpace(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterL(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterO(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterS(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterT(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterHyphen(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterHyphen(posX, posY);

	setupConsole.SetTextColor(7);
	Sleep(delay);

	utils.PosCursor(50, 17);
	for (int i = 0; i < 21; i++)
	{
		if (i == 0 || i == 20)
		{
			cout << char(219);
		}
		else
		{
			cout << char(223);
		}
	}

	for (int i = 0; i < 9; i++)
	{
		utils.PosCursor(50, 18 + i);
		cout << char(219);
	}

	for (int i = 0; i < 9; i++)
	{
		utils.PosCursor(70, 18 + i);
		cout << char(219);
	}

	utils.PosCursor(50, 27);
	for (int i = 0; i < 21; i++)
	{
		if (i == 0 || i == 20)
		{
			cout << char(219);
		}
		else
		{
			cout << char(220);
		}
	}

	setupConsole.SetTextColor(1);
	Sleep(delay);

	utils.PosCursor(54, 19);
	cout << "1 - Start" << endl;
	utils.PosCursor(54, 21);
	cout << "2 - Settings" << endl;
	utils.PosCursor(54, 23);
	cout << "3 - Credits" << endl;
	utils.PosCursor(54, 25);
	cout << "4 - Quit" << endl;

	setupConsole.SetTextColor(7);

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	char inputChoice = _getch();

	if (inputChoice == '1')
	{
		return;
	}
	else if (inputChoice == '2')
	{
		ShowSettings(utils, setupConsole);
	}
	else if (inputChoice == '3')
	{
		ShowCredits(utils, setupConsole);
	}
	else if (inputChoice == '4')
	{
		utils.PosCursor(0, 30);
		exit(EXIT_SUCCESS);
	}
}

void InterfaceMainMenu::UpdateSettingSoundActivated(Utils& utils, SetupConsole& setupConsole)
{
	setupConsole.SetTextColor(2);

	utils.PosCursor(66, 19);
	if (setupConsole.GetSoundActivated())
	{
		cout << "ON " << endl;
	}
	else
	{
		cout << "OFF" << endl;
	}

	setupConsole.SetTextColor(7);
}

void InterfaceMainMenu::UpdateSettingFontSize(Utils& utils, SetupConsole& setupConsole)
{
	setupConsole.SetTextColor(2);

	utils.PosCursor(66, 21);
	cout << setupConsole.GetFontSize() << "px" << endl;

	setupConsole.SetTextColor(7);
}

void InterfaceMainMenu::ShowSettings(Utils& utils, SetupConsole& setupConsole)
{
	system("cls");

	const int delay = 200;
	const int delayLetter = 100;

	Sleep(delay);

	setupConsole.SetTextColor(2);

	int posX = 34;
	int posY = 4;

	utils.LetterS(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterE(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterT(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterT(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterI(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterN(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterG(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterS(posX, posY);

	setupConsole.SetTextColor(7);
	Sleep(delay);

	utils.PosCursor(47, 17);
	for (int i = 0; i < 27; i++)
	{
		if (i == 0 || i == 26)
		{
			cout << char(219);
		}
		else
		{
			cout << char(223);
		}
	}

	for (int i = 0; i < 8; i++)
	{
		utils.PosCursor(47, 18 + i);
		cout << char(219);
	}

	for (int i = 0; i < 8; i++)
	{
		utils.PosCursor(73, 18 + i);
		cout << char(219);
	}

	utils.PosCursor(47, 25);
	for (int i = 0; i < 27; i++)
	{
		if (i == 0 || i == 26)
		{
			cout << char(219);
		}
		else
		{
			cout << char(220);
		}
	}

	setupConsole.SetTextColor(1);
	Sleep(delay);

	utils.PosCursor(51, 19);
	cout << "1 - Sound" << endl;
	utils.PosCursor(51, 21);
	cout << "2 - Font Size" << endl;
	utils.PosCursor(51, 23);
	cout << "3 - Back" << endl;

	setupConsole.SetTextColor(7);

	UpdateSettingSoundActivated(utils, setupConsole);
	UpdateSettingFontSize(utils, setupConsole);

	while (1)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

		char inputChoice = _getch();

		if (inputChoice == '1')
		{
			if (setupConsole.GetSoundActivated())
			{
				setupConsole.SetSoundActivated(false);
			}
			else
			{
				setupConsole.SetSoundActivated(true);
			}

			UpdateSettingSoundActivated(utils, setupConsole);
		}
		else if (inputChoice == '2')
		{
			if (setupConsole.GetFontSize() == 14)
			{
				HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
				setupConsole.SetFontSize(out, 18);
			}
			else if (setupConsole.GetFontSize() == 18)
			{
				HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
				setupConsole.SetFontSize(out, 22);
			}
			else if (setupConsole.GetFontSize() == 22)
			{
				HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
				setupConsole.SetFontSize(out, 26);
			}
			else if (setupConsole.GetFontSize() == 26)
			{
				HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
				setupConsole.SetFontSize(out, 30);
			}
			else if (setupConsole.GetFontSize() == 30)
			{
				HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
				setupConsole.SetFontSize(out, 34);
			}
			else if (setupConsole.GetFontSize() == 34)
			{
				HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
				setupConsole.SetFontSize(out, 14);
			}

			UpdateSettingFontSize(utils, setupConsole);
		}
		else if (inputChoice == '3')
		{
			break;
		}
	}

	ShowMainMenu(utils, setupConsole);
}

void InterfaceMainMenu::ShowCredits(Utils& utils, SetupConsole& setupConsole)
{
	system("cls");

	const int delay = 200;
	const int delayLetter = 100;
	const int delayCredits = 10000;

	Sleep(delay);

	setupConsole.SetTextColor(2);

	int posX = 37;
	int posY = 4;

	utils.LetterC(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterR(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterE(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterD(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterI(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterT(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterS(posX, posY);

	setupConsole.SetTextColor(7);
	Sleep(delay);

	utils.PosCursor(30, 17);
	for (int i = 0; i < 61; i++)
	{
		if (i == 0 || i == 60)
		{
			cout << char(219);
		}
		else
		{
			cout << char(223);
		}
	}

	for (int i = 0; i < 9; i++)
	{
		utils.PosCursor(30, 18 + i);
		cout << char(219);
	}

	for (int i = 0; i < 9; i++)
	{
		utils.PosCursor(90, 18 + i);
		cout << char(219);
	}

	utils.PosCursor(30, 27);
	for (int i = 0; i < 61; i++)
	{
		if (i == 0 || i == 60)
		{
			cout << char(219);
		}
		else
		{
			cout << char(220);
		}
	}

	setupConsole.SetTextColor(1);
	Sleep(delay);

	utils.PosCursor(34, 19);
	cout << "Project Manager & Lead Game Designer: Baptiste PERRIN";
	utils.PosCursor(34, 20);
	cout << "Game Designer:                        Loic VAREILLES" << endl;
	utils.PosCursor(34, 22);
	cout << "Lead Game Programmer:                 Killian FURNO" << endl;
	utils.PosCursor(34, 23);
	cout << "Game Programmer:                      Adrien LECHAT" << endl;
	utils.PosCursor(34, 24);
	cout << "Game Programmer:                      Hortense MARIE" << endl;
	utils.PosCursor(34, 25);
	cout << "Game Programmer:                      Florian MARTINS" << endl;

	setupConsole.SetTextColor(7);

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	int waited = 0;
	const int delayWait = 20;
	while (waited < delayCredits)
	{
		if (_kbhit()) 
		{
			(void)_getch();
			break;
		}

		Sleep(delayWait);

		waited += delayWait;
	}

	ShowMainMenu(utils, setupConsole);
}