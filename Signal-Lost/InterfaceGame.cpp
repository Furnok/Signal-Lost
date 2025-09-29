#include "InterfaceGame.h"

#include <thread>
#include <chrono>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std::chrono_literals;

void InterfaceGame::ShowTransitionChapter(Utils& utils, SetupConsole& setupConsole, File& file)
{
	system("cls");

	this->newChapter = false;

	constexpr auto delayStart = 200ms;
	constexpr auto delayTitle = 500ms;
	constexpr auto delayLetter = 100ms;
	constexpr auto delayTransition = 2s;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	const int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	const int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	const std::string letters = "CHAPTER-";
	const std::string digits = std::to_string(file.GetChapterNumber());
	const std::string all = letters + digits;
	const int glyphCount = static_cast<int>(all.size());
	const int chapterWidth = ((glyphCount - 1) * 7) + 5;
	const int chapterHeight = 5;

	int chapterNameWidth = static_cast<int>(file.GetChapterName().size());
	int chapterNameHeight = 1;

	int posX = (consoleWidth - chapterWidth) / 2;
	int posY = ((consoleHeight - chapterHeight) / 2) - 2;

	setupConsole.SetTextColor(2);
	std::this_thread::sleep_for(delayStart);

	for (char ch : all)
	{
		utils.DrawAscii(ch, posX, posY);

		posX += 7;
		std::this_thread::sleep_for(delayLetter);
	}

	posX = (consoleWidth - chapterNameWidth) / 2;
	posY = ((consoleHeight - chapterNameHeight) / 2) + 2;

	setupConsole.SetTextColor(7);
	std::this_thread::sleep_for(delayTitle);

	utils.PosCursor(posX, posY);
	std::cout << file.GetChapterName() << std::endl;

	std::this_thread::sleep_for(delayTransition);
}

void InterfaceGame::DisplayInterfaceGame()
{
	system("cls");
}
