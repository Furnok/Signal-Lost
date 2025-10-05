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
void InterfaceGame::DisplayInterfaceGame(Utils& utils, SetupConsole& setupConsole, const File& file)
{
	utils.ClearConsole();

	constexpr auto delay = 200ms;

	std::this_thread::sleep_for(delay);

	DisplayHeader(utils, setupConsole, file);

	utils.DrawBox(2, 27, 96, 13);

	constexpr auto delayTransition = 60min;
	std::this_thread::sleep_for(delayTransition);
}

/// <summary>
/// Display the Connexion Barre
/// </summary>
/// <param name="utils"></param>
/// <param name="setupConsole"></param>
/// <param name="file"></param>
void InterfaceGame::DisplayConnectionBarre(Utils& utils, SetupConsole& setupConsole, const File& file)
{
	setupConsole.SetTextColor(1);

	const int posX = 2;
	const int posY = 1;

	int connectionPoint = file.GetConnectionPoint();

	utils.DrawConnection(connectionPoint, posX, posY);

	setupConsole.SetTextColor(7);
}

/// <summary>
/// Display the Trust Barre
/// </summary>
/// <param name="utils"></param>
/// <param name="setupConsole"></param>
/// <param name="file"></param>
void InterfaceGame::DisplayTrustBarre(Utils& utils, SetupConsole& setupConsole, const File& file)
{
	setupConsole.SetTextColor(1);

	const int posX = 53;
	const int posY = 2;

	int trustPoint = file.GetTrustPoint();

	utils.DrawTrustBarre(trustPoint, posX, posY);

	setupConsole.SetTextColor(7);
}

/// <summary>
/// Display the Trust Percentage
/// </summary>
/// <param name="utils"></param>
/// <param name="setupConsole"></param>
/// <param name="file"></param>
void InterfaceGame::DisplayTrustPercentage(Utils& utils, SetupConsole& setupConsole, const File& file)
{
	setupConsole.SetTextColor(2);

	int posX = 93;
	const int posY = 1;

	int trustPoint = file.GetTrustPoint();

	int hundreds = trustPoint / 100;
	int tens = (trustPoint / 10) % 10;
	int ones = trustPoint % 10;

	utils.DrawAscii('0' + hundreds, posX, posY);

	posX += 7;

	utils.DrawAscii('0' + tens, posX, posY);

	posX += 7;

	utils.DrawAscii('0' + ones, posX, posY);

	posX += 7;

	utils.DrawAscii('%', posX, posY);

	setupConsole.SetTextColor(7);
}

/// <summary>
/// Display the Header
/// </summary>
/// <param name="utils"></param>
/// <param name="setupConsole"></param>
/// <param name="file"></param>
void InterfaceGame::DisplayHeader(Utils& utils, SetupConsole& setupConsole, const File& file)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	const int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	int posX = 0;
	int posY = 7;

	for (int i = 0; i < consoleWidth; i++)
	{
		utils.PosCursor(posX + i, posY);
		std::cout << char(223) << "\n";
	}

	posX += 14;

	for (int i = 0; i < posY; i++)
	{
		utils.PosCursor(posX, i);
		std::cout << char(219) << "\n";
	}

	DisplayConnectionBarre(utils, setupConsole, file);

	setupConsole.SetTextColor(2);

	utils.DrawGameTitle(trustTitle, 17, 1);

	setupConsole.SetTextColor(7);

	utils.DrawBox(52, 1, 39, 5);

	DisplayTrustBarre(utils, setupConsole, file);

	DisplayTrustPercentage(utils, setupConsole, file);
}