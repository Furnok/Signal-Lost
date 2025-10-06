#include "InterfaceGame.h"

#include <thread>
#include <chrono>
#include <string>
#include <iostream>
#include <windows.h>
#include <regex>

using namespace std::chrono;

/// <summary>
/// Display the Transition to a Chapter
/// </summary>
/// <param name="utils"></param>
/// <param name="setupConsole"></param>
/// <param name="file"></param>
void InterfaceGame::DisplayTransitionChapter(Utils& utils, SetupConsole& setupConsole)
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

	const std::string chapterName = this->chapterName;
	const std::string title = std::string(this->textChapter) + std::to_string(this->chapterNumber);
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
	std::cout << this->chapterName << '\n';

	std::this_thread::sleep_for(delayTransition);
}

/// <summary>
/// Display the Game UI
/// </summary>
/// <param name="utils"></param>
void InterfaceGame::DisplayInterfaceGame(Utils& utils, SetupConsole& setupConsole)
{
	utils.ClearConsole();

	constexpr auto delay = 200ms;

	std::this_thread::sleep_for(delay);

	DisplayHeader(utils, setupConsole);

	utils.DrawBox(2, 27, 96, 13);
}

/// <summary>
/// Display the Connexion Barre
/// </summary>
/// <param name="utils"></param>
/// <param name="setupConsole"></param>
/// <param name="file"></param>
void InterfaceGame::DisplayConnectionBarre(Utils& utils, SetupConsole& setupConsole)
{
	setupConsole.SetTextColor(1);

	const int posX = 2;
	const int posY = 1;

	int connectionPoint = this->connectionPoint;

	utils.DrawConnection(connectionPoint, posX, posY);

	setupConsole.SetTextColor(7);
}

/// <summary>
/// Display the Trust Barre
/// </summary>
/// <param name="utils"></param>
/// <param name="setupConsole"></param>
/// <param name="file"></param>
void InterfaceGame::DisplayTrustBarre(Utils& utils, SetupConsole& setupConsole)
{
	setupConsole.SetTextColor(1);

	const int posX = 53;
	const int posY = 2;

	int trustPoint = this->trustPoint;

	utils.DrawTrustBarre(trustPoint, posX, posY);

	setupConsole.SetTextColor(7);
}

/// <summary>
/// Display the Trust Percentage
/// </summary>
/// <param name="utils"></param>
/// <param name="setupConsole"></param>
/// <param name="file"></param>
void InterfaceGame::DisplayTrustPercentage(Utils& utils, SetupConsole& setupConsole)
{
	setupConsole.SetTextColor(2);

	int posX = 93;
	const int posY = 1;

	int trustPoint = this->trustPoint;

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

struct Choice 
{
	bool isDefault = false;
	int nextScene = 0;
	int nextChapter = 0;
	int trustNeed = 0;
	int trustAdd = 0;
	std::string text = "";
};

struct Scene 
{
	int number = 0;
	bool beepBack = false;
	int connexion = 0;
	int timer = 0;
	std::string content = "";
	std::vector<Choice> choices;
};

std::string extractTag(const std::string& text, const std::string& tag) 
{
	size_t pos = text.find("[" + tag + "=");
	if (pos == std::string::npos) return "";

	size_t start = pos + tag.size() + 2;
	while (start < text.size() && (text[start] == '\n' || text[start] == '\r' || text[start] == ' ')) start++;

	int bracketCount = 0;
	size_t i = start;
	for (; i < text.size(); ++i) {
		if (text[i] == '[') bracketCount++;
		else if (text[i] == ']') {
			if (bracketCount == 0) break;
			bracketCount--;
		}
	}

	return text.substr(start, i - start);
}

std::vector<Choice> parseChoices(const std::string& text)
{
	std::vector<Choice> choices;
	size_t pos = 0;

	while ((pos = text.find("[Choice", pos)) != std::string::npos)
	{
		size_t start = pos;
		int bracketCount = 0;
		size_t i = pos;

		for (; i < text.size(); ++i) {
			if (text[i] == '[') bracketCount++;
			else if (text[i] == ']') bracketCount--;
			if (bracketCount == 0) break;
		}

		std::string choiceText = text.substr(start, i - start + 1);

		Choice c;

		size_t defPos = choiceText.find("[Default=");
		if (defPos != std::string::npos) {
			size_t end = choiceText.find(']', defPos);
			std::string value = choiceText.substr(defPos + 9, end - defPos - 9);
			c.isDefault = (value == "True" || value == "true");
		}

		size_t nextPos = choiceText.find("[NextScene=");
		if (nextPos != std::string::npos) {
			size_t end = choiceText.find(']', nextPos);
			std::string value = choiceText.substr(nextPos + 11, end - nextPos - 11);
			c.nextScene = std::stoi(value);
		}

		size_t contentPos = choiceText.find("[Content=");
		if (contentPos != std::string::npos) {
			size_t end = choiceText.find(']', contentPos);
			c.text = choiceText.substr(contentPos + 9, end - contentPos - 9);
		}

		choices.push_back(c);
		pos = i + 1;
	}

	return choices;
}

std::vector<Scene> ParseScenes(const std::string& fileContent)
{
	std::vector<Scene> scenes;
	size_t pos = 0;

	while ((pos = fileContent.find("[Scene=", pos)) != std::string::npos) 
	{
		size_t start = pos;
		int bracketCount = 0;
		size_t i = pos;

		for (; i < fileContent.size(); ++i) 
		{
			if (fileContent[i] == '[') bracketCount++;
			else if (fileContent[i] == ']') bracketCount--;
			if (bracketCount == 0) break;
		}

		std::string sceneText = fileContent.substr(start, i - start + 1);

		// Extract scene number
		size_t eq = sceneText.find('=');
		size_t firstBracket = sceneText.find('[');
		Scene scene;
		scene.number = std::stoi(sceneText.substr(eq + 1, firstBracket - eq - 1));

		// Extract Beep
		std::string beepValue = extractTag(sceneText, "BeepBack");
		scene.beepBack = (beepValue == "True" || beepValue == "true");

		// Extract Connexion
		std::string connValue = extractTag(sceneText, "Connexion");
		if (!connValue.empty()) scene.connexion = std::stoi(connValue);

		// Extract Timer
		std::string timerValue = extractTag(sceneText, "Timer");
		if (!timerValue.empty()) scene.timer = std::stoi(timerValue);

		// Extract Content
		std::string contentValue = extractTag(sceneText, "Content");
		scene.content = contentValue;

		// Extract Choices
		std::string choicesValue = extractTag(sceneText, "Choices");
		scene.choices = parseChoices(choicesValue);

		scenes.push_back(scene);
		pos = i + 1;
	}

	return scenes;
}

const void InterfaceGame::DisplayText(Utils& utils, SetupConsole& setupConsole, const File& file)
{
	utils.PosCursor(0, 8);

	std::vector<Scene> scenes = ParseScenes(file.GetContentChapter());

	Scene s = scenes[0];

	std::cout << "=== Scene " << s.number << " ===\n";
	std::cout << "Beep: " << (s.beepBack ? "Yes" : "No") << "\n";
	std::cout << "Connexion: " << s.connexion << "\n";
	std::cout << "Timer: " << s.timer << "\n";
	std::cout << "Content:\n" << s.content << "\n";
	std::cout << "Choices:\n";

	for (auto& c : s.choices) 
	{
		std::cout << (c.isDefault ? "> " : "  ");
		std::cout << c.text << "  -> Scene " << c.nextScene << "\n";
	}

	std::cout << "====================================\n\n";

	constexpr auto delayTransition = 60min;
	std::this_thread::sleep_for(delayTransition);
}

bool InterfaceGame::Timer(Utils& utils, SetupConsole& setupConsole)
{
	bool result = false;

	TimerShow(utils, setupConsole);

	if (!this->noBeepSound && setupConsole.GetSoundActivated())
	{
		Beep(500, 300);
	}

	setupConsole.SetTextColor(7);

	if (this->timer <= 0)
	{
		result = true;
		this->noBeepSound = false;
	}

	return result;
}

void InterfaceGame::TimerShow(Utils& utils, SetupConsole& setupConsole)
{
	int posX = 100;
	const int posY = 31;

	int timer = this->timer;

	if (timer <= 10)
	{
		setupConsole.SetTextColor(4);
	}
	else
	{
		setupConsole.SetTextColor(7);
	}

	int hundreds = timer / 100;
	int tens = (timer / 10) % 10;
	int ones = timer % 10;

	utils.DrawAscii('0' + hundreds, posX, posY);

	posX += 7;

	utils.DrawAscii('0' + tens, posX, posY);

	posX += 7;

	utils.DrawAscii('0' + ones, posX, posY);
}

/// <summary>
/// Display the Header
/// </summary>
/// <param name="utils"></param>
/// <param name="setupConsole"></param>
/// <param name="file"></param>
void InterfaceGame::DisplayHeader(Utils& utils, SetupConsole& setupConsole)
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

	DisplayConnectionBarre(utils, setupConsole);

	setupConsole.SetTextColor(2);

	utils.DrawGameTitle(trustTitle, 17, 1);

	setupConsole.SetTextColor(7);

	utils.DrawBox(52, 1, 39, 5);

	DisplayTrustBarre(utils, setupConsole);

	DisplayTrustPercentage(utils, setupConsole);
}