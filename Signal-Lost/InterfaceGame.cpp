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

	int posX = 2;
	const int posY = 5;

	int connectionPoint = file.GetConnectionPoint();

	for (int i = 0; i < 4; i++)
	{
		int barHeight = (i + 1);

		for (int y = 0; y < barHeight; y++)
		{
			utils.PosCursor(posX, posY - y);

			if (i < connectionPoint)
			{
				std::cout << char(219) << '\n';
			}
			else
			{
				std::cout << " " << '\n';
			}
		}

		posX += 3;
	}

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

	for (int i = 0; i < 36; i++)
	{
		utils.PosCursor(54 + i, 2);
		std::cout << " " << "\n";
	}

	for (int i = 0; i < 36; i++)
	{
		utils.PosCursor(54 + i, 3);
		std::cout << " " << "\n";
	}

	for (int i = 0; i < 36; i++)
	{
		utils.PosCursor(54 + i, 4);
		std::cout << " " << "\n";
	}

	for (int i = 0; i < (100 / 100.0) * 36; i++)
	{
		utils.PosCursor(54 + i, 2);
		std::cout << char(219) << "\n";
	}

	for (int i = 0; i < (100 / 100.0) * 36; i++)
	{
		utils.PosCursor(54 + i, 3);
		std::cout << char(219) << "\n";
	}

	for (int i = 0; i < (100 / 100.0) * 36; i++)
	{
		utils.PosCursor(54 + i, 4);
		std::cout << char(219) << "\n";
	}

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

	int digit1 = 93;
	int digit2 = 100;
	int digit3 = 107;
	int digit4 = 114;

	utils.DrawAscii('0', digit1, 1);
	utils.DrawAscii('0', digit2, 1);
	utils.DrawAscii('0', digit3, 1);
	utils.DrawAscii('%', digit4, 1);

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

	posX += 15;

	for (int i = 0; i < posY; i++)
	{
		utils.PosCursor(posX, i);
		std::cout << char(219) << "\n";
	}

	DisplayConnectionBarre(utils, setupConsole, file);

	setupConsole.SetTextColor(2);

	utils.DrawGameTitle(trustTitle, 18, 1);

	setupConsole.SetTextColor(7);

	utils.DrawBox(53, 1, 38, 5);

	DisplayTrustBarre(utils, setupConsole, file);

	DisplayTrustPercentage(utils, setupConsole, file);
}