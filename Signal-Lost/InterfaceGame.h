#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SetupConsole.h"
#include "Utils.h"
#include "File.h"

class InterfaceGame
{
public:
	void DisplayTransitionChapter(Utils& utils, SetupConsole& setupConsole, const File& file);

	void DisplayInterfaceGame(Utils& utils);

	[[nodiscard]] bool GetDisplay() const noexcept { return this->display; }

private:
	static constexpr std::string_view textChapter = "CHAPTER-";

	bool display = true;
};