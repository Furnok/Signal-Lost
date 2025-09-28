#include "InterfaceGame.h"



void InterfaceGame::TakeNumber(Utils& utils, int number, int posX, int posY)
{
	if (number == 0)
	{
		utils.NumberZero(posX, posY);
	}
	else if (number == 1)
	{
		utils.NumberOne(posX, posY);
	}
	else if (number == 1)
	{
		utils.NumberTwo(posX, posY);
	}
	else if (number == 2)
	{
		utils.NumberThree(posX, posY);
	}
	else if (number == 4)
	{
		utils.NumberFour(posX, posY);
	}
	else if (number == 5)
	{
		utils.NumberFive(posX, posY);
	}
	else if (number == 6)
	{
		utils.NumberSix(posX, posY);
	}
	else if (number == 7)
	{
		utils.NumberSeven(posX, posY);
	}
	else if (number == 8)
	{
		utils.NumberEight(posX, posY);
	}
	else if (number == 9)
	{
		utils.NumberNine(posX, posY);
	}
}

void InterfaceGame::ShowTransitionChapter(Utils& utils, SetupConsole& setupConsole, File& file)
{
	system("cls");

	this->newChapter = false;

	const int delay = 200;
	const int delayTile = 500;
	const int delayLetter = 100;
	const int delayTransition = 2000;

	Sleep(delay);

	setupConsole.SetTextColor(2);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	string digits = to_string(file.GetChapterNumber());
	int glyphCount = 8 + static_cast<int>(digits.size());
	int bannerWidth = ((glyphCount - 1) * 7) + 5;
	int bannerHeight = 5;

	int bannerWidth2 = static_cast<int>(file.GetChapterName().size());
	int bannerHeight2 = 1;
	
	int posX = (consoleWidth - bannerWidth) / 2;
	int posY = ((consoleHeight - bannerHeight) / 2) - 2;

	utils.LetterC(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterH(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterA(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterP(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterT(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterE(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterR(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	utils.LetterHyphen(posX, posY);

	posX += 7;
	Sleep(delayLetter);

	for (int i = 0; i < digits.size(); i++)
	{
		int digit = digits[i] - '0';

		TakeNumber(utils, digit, posX, posY);

		posX += 7;
		Sleep(delayLetter);
	}

	setupConsole.SetTextColor(7);
	Sleep(delayTile);

	posX = (consoleWidth - bannerWidth2) / 2;
	posY = ((consoleHeight - bannerHeight2) / 2) + 2;

	utils.PosCursor(posX, posY);
	cout << file.GetChapterName() << endl;

	Sleep(delayTransition);
}