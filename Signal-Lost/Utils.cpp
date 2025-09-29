#include "Utils.h"

#include <windows.h>
#include <iostream>

void Utils::PosCursor(int posX, int posY) const
{
	COORD pos = { SHORT(posX), SHORT(posY) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Utils::DrawBox(int left, int top, int width, int height) const
{
	PosCursor(left, top);
	for (int i = 0; i < width; ++i)
	{
		std::cout << ((i == 0 || i == width - 1) ? char(219) : char(223));
	}

	for (int y = 1; y < height - 1; ++y)
	{
		PosCursor(left, top + y);
		std::cout << char(219);
		PosCursor(left + width - 1, top + y);
		std::cout << char(219);
	}

	PosCursor(left, top + height - 1);
	for (int i = 0; i < width; ++i)
	{
		std::cout << ((i == 0 || i == width - 1) ? char(219) : char(220));
	}
}

void Utils::DrawAscii(char ch, int posX, int posY) const
{
	UINT originalOutputCP = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);

    ch = std::toupper(static_cast<unsigned char>(ch));

    auto it = ascii.find(ch);
    if (it != ascii.end())
    {
        for (size_t i = 0; i < it->second.size(); ++i)
        {
            PosCursor(posX, posY + static_cast<int>(i));
            std::cout << it->second[i];
        }
    }

	SetConsoleOutputCP(originalOutputCP);
}