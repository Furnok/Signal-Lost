#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <string>
#include <string_view>
#include <array>
#include <filesystem>

using namespace std;

class SetupConsole
{
public:
    void InitConsole();

    void ResizeConsole(HANDLE out, int w, int h) const;
    void SetFontSize(HANDLE out, int size) const;
    void SetTextColor(int indexColor) const;
    void CenterWindow(HWND window, int screenW, int screenH) const;

    [[nodiscard]] string GetPathGameFolder() const noexcept { return pathGameFolder; }

private:
	void SetupPath();
    void SetupName() const;
    void CheckInstance() const;
    void DefineConsole(HWND window) const;

    static constexpr wstring_view appName = L"Signal Lost";
    static constexpr wstring_view fontName = L"Clarendon";

	string pathGameFolder = "";

    struct ConsoleSettings
    {
        int width = 120;
        int height = 40;
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