#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SetupConsole.h"
#include "Utils.h"
#include "File.h"

class InterfaceGame
{
public:
	void ShowTransitionChapter(Utils& utils, SetupConsole& setupConsole, File& file);

	void DisplayInterfaceGame();

	[[nodiscard]] bool GetNewChapter() const noexcept { return this->newChapter; }

private:
	bool newChapter = true;
};