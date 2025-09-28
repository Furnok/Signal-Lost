#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <string>
#include <string_view>
#include <array>
#include <filesystem>
#include <iostream>

using namespace std;

class SetupConsole
{
public:
    void InitConsole();

    void ResizeConsole(HANDLE out, int w, int h) const;
    void SetFontSize(HANDLE out, int size);
    void SetTextColor(int indexColor) const;
    void CenterWindow(HWND window, int screenW, int screenH) const;

    [[nodiscard]] string GetPathGameFolder() const noexcept { return this->pathGameFolder; }
	[[nodiscard]] bool GetSoundActivated() const noexcept { return this->soundActivated; }
    [[nodiscard]] int GetFontSize() const noexcept { return this->textFontSize; }

    void SetSoundActivated(bool value) { this->soundActivated = move(value); }

private:
	void SetupPath();
    void SetupName() const;
    void CheckInstance() const;
    void DefineConsole(HWND window);

    static constexpr wstring_view appName = L"Signal Lost";
    static constexpr wstring_view fontName = L"Lucida Console";

	string pathGameFolder = "";
	bool soundActivated = true;
    int textFontSize = 0;

    struct ConsoleSettings
    {
        int width = 121;
        int height = 41;
    };

    struct ScreenFont 
    { 
        int minWidth = 0;
        int fontSize = 0;
    };

    static constexpr auto fontMap = to_array<ScreenFont>
    ({
        {3840, 34},
        {2560, 30},
        {1920, 26},
        {1680, 22},
        {1280, 18},
        {0, 14},
    });
};