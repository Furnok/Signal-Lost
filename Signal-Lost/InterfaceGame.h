#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SetupConsole.h"
#include "Utils.h"
#include "File.h"

class File;

class InterfaceGame
{
public:
	void DisplayTransitionChapter(Utils& utils, SetupConsole& setupConsole);

	void DisplayInterfaceGame(Utils& utils, SetupConsole& setupConsole);

	void DisplayConnectionBarre(Utils& utils, SetupConsole& setupConsole);
	void DisplayTrustBarre(Utils& utils, SetupConsole& setupConsole);
	void DisplayTrustPercentage(Utils& utils, SetupConsole& setupConsole);

	const void DisplayText(Utils& utils, SetupConsole& setupConsole, const File& file);

	bool Timer(Utils& utils, SetupConsole& setupConsole);
	void TimerShow(Utils& utils, SetupConsole& setupConsole);

	[[nodiscard]] int GetChapterNumber() const noexcept { return this->chapterNumber; }
	[[nodiscard]] std::string GetChapterName() const noexcept { return this->chapterName; }
	[[nodiscard]] int GetConnectionPoint() const noexcept { return this->connectionPoint; }
	[[nodiscard]] int GetTrustPoint() const noexcept { return this->trustPoint; }
	[[nodiscard]] int GetScene() const noexcept { return this->scene; }

	[[nodiscard]] bool GetDisplay() const noexcept { return this->display; }

	void SetChapterNumber(int value) { this->chapterNumber = std::move(value); }
	void SetChapterName(std::string value) { this->chapterName = std::move(value); }
	void SetConnectionPoint(int value) { this->connectionPoint = std::move(value); }
	void SetTrustPoint(int value) { this->trustPoint = std::move(value); }
	void SetScene(int value) { this->scene = std::move(value); }

private:
	void DisplayHeader(Utils& utils, SetupConsole& setupConsole);

	static constexpr std::string_view textChapter = "CHAPTER-";
	static constexpr std::string_view trustTitle = "TRUST";

	int chapterNumber = 0;
	std::string chapterName = "Empty";
	int connectionPoint = 0;
	int trustPoint = 0;
	int scene = 0;
	int timer = 0;
	bool noBeepSound = false;

	bool display = true;
};