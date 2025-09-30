#include "InterfaceGame.h"

#include <thread>
#include <chrono>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std::chrono;

/// <summary>
/// Display the Transition to a Chapter
/// </summary>
/// <param name="utils"></param>
/// <param name="setupConsole"></param>
/// <param name="file"></param>
void InterfaceGame::DisplayTransitionChapter(Utils& utils, SetupConsole& setupConsole, const File& file)
{
	utils.ClearConsole();

	this->display = false;
	constexpr auto delayStart = 200ms;
	constexpr auto delayTitle = 500ms;
	constexpr auto delayLetter = 100ms;
	constexpr auto delayTransition = 2s;
	const int letterSize = 5;
	const int spaceLetter = 2;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	const int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	const int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	const std::string chapterName = file.GetChapterName();
	const std::string title = std::string(this->textChapter) + std::to_string(file.GetChapterNumber());
	const int titleWidth = static_cast<int>(((title.size() - 1) * (letterSize + spaceLetter)) + letterSize);
	int posX = (consoleWidth - titleWidth) / 2;;
	const int posY = ((consoleHeight - letterSize) / 2) - spaceLetter;

	setupConsole.SetTextColor(2);
	std::this_thread::sleep_for(delayStart);

	for (char ch : title)
	{
		utils.DrawAscii(ch, posX, posY);

		posX += letterSize + spaceLetter;;
		std::this_thread::sleep_for(delayLetter);
	}

	setupConsole.SetTextColor(7);
	std::this_thread::sleep_for(delayTitle);

	const int nameX = (consoleWidth - static_cast<int>(chapterName.size())) / 2;
	const int nameY = (consoleHeight / 2) + spaceLetter;

	utils.PosCursor(nameX, nameY);
	std::cout << file.GetChapterName() << '\n';

	std::this_thread::sleep_for(delayTransition);
}

/// <summary>
/// Display the Game UI
/// </summary>
/// <param name="utils"></param>
void InterfaceGame::DisplayInterfaceGame(Utils& utils)
{
	utils.ClearConsole();

	std::cout << "Hello" << '\n';
}
