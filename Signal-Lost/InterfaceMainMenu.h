#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SetupConsole.h"
#include "Utils.h"

class InterfaceMainMenu
{
public:
	void ShowMainMenu(Utils& utils, SetupConsole& setupConsole);
	
	[[nodiscard]] bool GetShowMainMenu() const noexcept { return this->showMainMenu; }

private:
	void UpdateSettingSoundActivated(Utils& utils, SetupConsole& setupConsole, int right, int top);
	void UpdateSettingFontSize(Utils& utils, SetupConsole& setupConsole, int right, int top);
	void ShowSettings(Utils& utils, SetupConsole& setupConsole);

	void ShowCredits(Utils& utils, SetupConsole& setupConsole);

	bool showMainMenu = true;
};