#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SetupConsole.h"
#include "Utils.h"
#include "File.h"

class InterfaceGame
{
public:
	void DisplayTransitionChapter(Utils& utils, SetupConsole& setupConsole, const File& file);

	void DisplayInterfaceGame(Utils& utils, SetupConsole& setupConsole, const File& file);

	void DisplayConnectionBarre(Utils& utils, SetupConsole& setupConsole, const File& file);
	void DisplayTrustBarre(Utils& utils, SetupConsole& setupConsole, const File& file);
	void DisplayTrustPercentage(Utils& utils, SetupConsole& setupConsole, const File& file);

	[[nodiscard]] bool GetDisplay() const noexcept { return this->display; }

private:
	void DisplayHeader(Utils& utils, SetupConsole& setupConsole, const File& file);

	static constexpr std::string_view textChapter = "CHAPTER-";
	static constexpr std::string_view trustTitle = "TRUST";

	bool display = true;
};