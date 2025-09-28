#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SetupConsole.h"
#include "Utils.h"
#include "File.h"

using namespace std;

class InterfaceGame
{
public:
	void TakeNumber(Utils& utils, int number, int posX, int posY);
	void ShowTransitionChapter(Utils& utils, SetupConsole& setupConsole, File& file);

	[[nodiscard]] bool GetNewChapter() const noexcept { return this->newChapter; }

private:
	bool newChapter = true;
};