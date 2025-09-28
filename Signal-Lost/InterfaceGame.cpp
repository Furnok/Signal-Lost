#include "InterfaceGame.h"

void InterfaceGame::ShowTransitionChapter(Utils& utils, SetupConsole& setupConsole, File& file)
{
	system("cls");

	this->newChapter = false;

	constexpr auto delay = 200ms;
	constexpr auto delayTile = 500ms;
	constexpr auto delayLetter = 100ms;
	constexpr auto delayTransition = 2s;

	this_thread::sleep_for(delay);

	setupConsole.SetTextColor(2);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	const int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	const int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	const string letters = "CHAPTER-";
	const string digits = to_string(file.GetChapterNumber());
	const int glyphCount = static_cast<int>(letters.size()) + static_cast<int>(digits.size());
	const int chapterWidth = ((glyphCount - 1) * 7) + 5;
	const int chapterHeight = 5;

	int chapterNameWidth = static_cast<int>(file.GetChapterName().size());
	int chapterNameHeight = 1;
	
	int posX = (consoleWidth - chapterWidth) / 2;
	int posY = ((consoleHeight - chapterHeight) / 2) - 2;

	for (char ch : letters)
	{
		utils.DrawLetter(ch, posX, posY);

		posX += 7;
		this_thread::sleep_for(delayLetter);
	}

	for (char c : digits)
	{
		utils.DrawDigit(c - '0', posX, posY);

		posX += 7;

		this_thread::sleep_for(delayLetter);
	}

	setupConsole.SetTextColor(7);
	this_thread::sleep_for(delayTile);

	posX = (consoleWidth - chapterNameWidth) / 2;
	posY = ((consoleHeight - chapterNameHeight) / 2) + 2;

	utils.PosCursor(posX, posY);
	cout << file.GetChapterName() << endl;

	this_thread::sleep_for(delayTransition);
}

void InterfaceGame::DisplayInterfaceGame()
{
	system("cls");
}
