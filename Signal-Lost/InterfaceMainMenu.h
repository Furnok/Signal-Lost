#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SetupConsole.h"
#include "Utils.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>

using namespace std;

class InterfaceMainMenu
{
public:
	void ShowMainMenu(Utils& utils, SetupConsole& setupConsole);
	
	[[nodiscard]] bool GetShowMainMenu() const noexcept { return this->showMainMenu; }

private:
	void DrawBox(Utils& utils, int left, int top, int width, int height) const;

	void UpdateSettingSoundActivated(Utils& utils, SetupConsole& setupConsole, int right, int top);
	void UpdateSettingFontSize(Utils& utils, SetupConsole& setupConsole, int right, int top);
	void ShowSettings(Utils& utils, SetupConsole& setupConsole);

	void ShowCredits(Utils& utils, SetupConsole& setupConsole);

	bool showMainMenu = true;
};