#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SetupConsole.h"
#include "Utils.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class InterfaceMainMenu
{
public:
	void ShowMainMenu(Utils& utils, SetupConsole& setupConsole);
	
	[[nodiscard]] bool GetShowMainMenu() const noexcept { return this->showMainMenu; }

private:
	void UpdateSettingSoundActivated(Utils& utils, SetupConsole& setupConsole);
	void UpdateSettingFontSize(Utils& utils, SetupConsole& setupConsole);
	void ShowSettings(Utils& utils, SetupConsole& setupConsole);

	void ShowCredits(Utils& utils, SetupConsole& setupConsole);

	bool showMainMenu = true;
};