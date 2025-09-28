#include "Utils.h"

void Utils::PosCursor(int posX, int posY) const
{
	COORD pos = { SHORT(posX), SHORT(posY) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Utils::DrawDigit(int number, int posX, int posY) const
{
	switch (number)
	{
		case 0:
		{
			NumberZero(posX, posY);
			break;
		}
		case 1:
		{
			NumberOne(posX, posY);
			break;
		}
		case 2:
		{
			NumberTwo(posX, posY);
			break;
		}
		case 3:
		{
			NumberThree(posX, posY);
			break;
		}
		case 4:
		{
			NumberFour(posX, posY);
			break;
		}
		case 5:
		{
			NumberFive(posX, posY);
			break;
		}
		case 6:
		{
			NumberSix(posX, posY);
			break;
		}
		case 7:
		{
			NumberSeven(posX, posY);
			break;
		}
		case 8:
		{
			NumberEight(posX, posY);
			break;
		}
		case 9:
		{
			NumberNine(posX, posY);
			break;
		}
		default:
		{
			break;
		}
	}
}

void Utils::DrawLetter(char letter, int posX, int posY) const
{
	switch (letter)
	{
		case '-':
		{
			LetterHyphen(posX, posY);
			break;
		}
		case ' ':
		{
			LetterSpace(posX, posY);
			break;
		}
		case 'A':
		{
			LetterA(posX, posY);
			break;
		}
		case 'B':
		{
			LetterB(posX, posY);
			break;
		}
		case 'C':
		{
			LetterC(posX, posY);
			break;
		}
		case 'D':
		{
			LetterD(posX, posY);
			break;
		}
		case 'E':
		{
			LetterE(posX, posY);
			break;
		}
		case 'F':
		{
			LetterF(posX, posY);
			break;
		}
		case 'G':
		{
			LetterG(posX, posY);
			break;
		}
		case 'H':
		{
			LetterH(posX, posY);
			break;
		}
		case 'I':
		{
			LetterI(posX, posY);
			break;
		}
		case 'J':
		{
			LetterJ(posX, posY);
			break;
		}
		case 'K':
		{
			LetterK(posX, posY);
			break;
		}
		case 'L':
		{
			LetterL(posX, posY);
			break;
		}
		case 'M':
		{
			LetterM(posX, posY);
			break;
		}
		case 'N':
		{
			LetterN(posX, posY);
			break;
		}
		case 'O':
		{
			LetterO(posX, posY);
			break;
		}
		case 'P':
		{
			LetterP(posX, posY);
			break;
		}
		case 'Q':
		{
			LetterQ(posX, posY);
			break;
		}
		case 'R':
		{
			LetterR(posX, posY);
			break;
		}
		case 'S':
		{
			LetterS(posX, posY);
			break;
		}
		case 'T':
		{
			LetterT(posX, posY);
			break;
		}
		case 'U':
		{
			LetterU(posX, posY);
			break;
		}
		case 'V':
		{
			LetterV(posX, posY);
			break;
		}
		case 'W':
		{
			LetterW(posX, posY);
			break;
		}
		case 'X':
		{
			LetterS(posX, posY);
			break;
		}
		case 'Y':
		{
			LetterY(posX, posY);
			break;
		}
		case 'Z':
		{
			LetterZ(posX, posY);
			break;
		}
		default:
		{
			break;
		}
	}
}

void Utils::NumberZero(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << " " << char(223) << char(223) << char(223) << " " << endl;
}

void Utils::NumberOne(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << " " << char(220) << " " << " " << endl;
	PosCursor(x, y + 1);
	cout << char(220) << char(223) << char(219) << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 3);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << char(223) << char(223) << char(223) << char(223) << char(223) << endl;
}

void Utils::NumberTwo(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << " " << " " << " " << char(219) << " " << endl;
	PosCursor(x, y + 3);
	cout << " " << char(220) << char(223) << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << char(223) << char(223) << char(223) << char(223) << char(223) << endl;
}

void Utils::NumberThree(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << " " << " " << " " << char(219) << " " << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << " " << char(223) << char(223) << char(223) << " " << endl;
}

void Utils::NumberFour(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << " " << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << " " << char(220) << char(223) << char(219) << " " << endl;
	PosCursor(x, y + 2);
	cout << char(220) << char(223) << " " << char(219) << " " << endl;
	PosCursor(x, y + 3);
	cout << char(219) << char(220) << char(220) << char(219) << char(220) << endl;
	PosCursor(x, y + 4);
	cout << " " << " " << " " << char(223) << " " << endl;
}

void Utils::NumberFive(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << char(219) << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 3);
	cout << " " << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << char(223) << char(223) << char(223) << char(223) << " " << endl;
}

void Utils::NumberSix(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << " " << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << " " << char(219) << " " << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << char(219) << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << " " << char(223) << char(223) << char(223) << " " << endl;
}

void Utils::NumberSeven(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << endl;
	PosCursor(x, y + 1);
	cout << " " << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << " " << " " << " " << char(219) << " " << endl;
	PosCursor(x, y + 3);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << " " << " " << char(223) << " " << " " << endl;
}

void Utils::NumberEight(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << char(220) << char(220) << char(220) << char(219) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << " " << char(223) << char(223) << char(223) << " " << endl;
}

void Utils::NumberNine(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << char(220) << char(220) << char(220) << char(219) << endl;
	PosCursor(x, y + 3);
	cout << " " << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << char(223) << char(223) << char(223) << char(223) << " " << endl;
}

void Utils::LetterHyphen(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << " " << " " << " " << " " << endl;
	PosCursor(x, y + 1);
	cout << " " << " " << " " << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << endl;
	PosCursor(x, y + 3);
	cout << " " << " " << " " << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << " " << " " << " " << " " << " " << endl;
}

void Utils::LetterSpace(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << " " << " " << " " << " " << endl;
	PosCursor(x, y + 1);
	cout << " " << " " << " " << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << " " << " " << " " << " " << " " << endl;
	PosCursor(x, y + 3);
	cout << " " << " " << " " << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << " " << " " << " " << " " << " " << endl;
}

void Utils::LetterA(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << " " << char(220) << " " << " " << endl;
	PosCursor(x, y + 1);
	cout << " " << char(219) << " " << char(219) << " " << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << char(223) << char(223) << char(223) << char(219) << endl;
	PosCursor(x, y + 4);
	cout << char(223) << " " << " " << " " << char(223) << endl;
}

void Utils::LetterB(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << char(220) << char(220) << char(220) << char(223) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << char(223) << char(223) << char(223) << char(223) << " " << endl;
}

void Utils::LetterC(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << char(220) << char(220) << char(220) << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << " " << " " << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << " " << char(223) << char(223) << char(223) << char(223) << endl;
}

void Utils::LetterD(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << char(223) << char(223) << char(223) << char(223) << " " << endl;
}

void Utils::LetterE(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << char(219) << char(220) << char(220) << char(220) << char(220) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << char(223) << char(223) << char(223) << char(223) << char(223) << endl;
}

void Utils::LetterF(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << char(219) << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << char(223) << " " << " " << " " << " " << endl;
}

void Utils::LetterG(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(223) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << " " << char(223) << char(223) << char(223) << " " << endl;
}

void Utils::LetterH(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << " " << " " << " " << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << char(220) << char(220) << char(220) << char(219) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << char(223) << " " << " " << " " << char(223) << endl;
}

void Utils::LetterI(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << endl;
	PosCursor(x, y + 1);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 3);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << char(223) << char(223) << char(223) << char(223) << char(223) << endl;
}

void Utils::LetterJ(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << endl;
	PosCursor(x, y + 1);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << " " << char(223) << char(223) << " " << " " << endl;
}

void Utils::LetterK(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << " " << " " << " " << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << char(220) << char(223) << " " << endl;
	PosCursor(x, y + 2);
	cout << char(219) << char(219) << " " << " " << " " << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << char(223) << char(220) << " " << endl;
	PosCursor(x, y + 4);
	cout << char(223) << " " << " " << " " << char(223) << endl;
}

void Utils::LetterL(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << " " << " " << " " << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << " " << " " << " " << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << char(223) << char(223) << char(223) << char(223) << char(223) << endl;
}

void Utils::LetterM(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << " " << " " << " " << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(219) << char(219) << " " << char(219) << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << char(219) << " " << char(219) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << char(223) << " " << " " << " " << char(223) << endl;
}

void Utils::LetterN(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << " " << " " << " " << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(219) << char(219) << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << char(219) << " " << char(219) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << char(219) << char(219) << endl;
	PosCursor(x, y + 4);
	cout << char(223) << " " << " " << " " << char(223) << endl;
}

void Utils::LetterO(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << " " << char(223) << char(223) << char(223) << " " << endl;
}

void Utils::LetterP(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << char(220) << char(220) << char(220) << char(223) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << char(223) << " " << " " << " " << " " << endl;
}

void Utils::LetterQ(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << char(223) << char(220) << char(219) << endl;
	PosCursor(x, y + 4);
	cout << " " << char(223) << char(223) << char(223) << char(220) << endl;
}

void Utils::LetterR(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << char(220) << char(220) << char(220) << char(223) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << char(223) << char(220) << "" << endl;
	PosCursor(x, y + 4);
	cout << char(223) << " " << " " << " " << char(223) << endl;
}

void Utils::LetterS(int x, int y) const
{
	PosCursor(x, y);
	cout << " " << char(220) << char(220) << char(220) << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << char(223) << char(220) << char(220) << char(220) << " " << endl;
	PosCursor(x, y + 3);
	cout << " " << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << char(223) << char(223) << char(223) << char(223) << " " << endl;
}

void Utils::LetterT(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << endl;
	PosCursor(x, y + 1);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 2);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 3);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << " " << " " << char(223) << " " << " " << endl;
}

void Utils::LetterU(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << " " << " " << " " << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 3);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << " " << char(223) << char(223) << char(223) << " " << endl;
}

void Utils::LetterV(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << " " << " " << " " << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 3);
	cout << " " << char(219) << " " << char(219) << " " << endl;
	PosCursor(x, y + 4);
	cout << " " << " " << char(223) << " " << " " << endl;
}

void Utils::LetterW(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << " " << " " << " " << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 2);
	cout << char(219) << " " << " " << " " << char(219) << endl;
	PosCursor(x, y + 3);
	cout << char(219) <<" " << char(219) << " " << char(219) << endl;
	PosCursor(x, y + 4);
	cout << " " << char(223) << " " << char(223) << " " << endl;
}

void Utils::LetterX(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << " " << " " << " " << char(220) << endl;
	PosCursor(x, y + 1);
	cout << " " << char(219) << " " << char(219) << " " << endl;
	PosCursor(x, y + 2);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 3);
	cout << " " << char(219) << " " << char(219) << " " << endl;
	PosCursor(x, y + 4);
	cout << char(223) << " " << " " << " " << char(223) << endl;
}

void Utils::LetterY(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << " " << " " << " " << char(220) << endl;
	PosCursor(x, y + 1);
	cout << char(223) << char(220) << " " << char(220) << char(223) << endl;
	PosCursor(x, y + 2);
	cout << " " << char(223) << char(220) << char(223) << " " << endl;
	PosCursor(x, y + 3);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << " " << " " << char(223) << " " << " " << endl;
}

void Utils::LetterZ(int x, int y) const
{
	PosCursor(x, y);
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << endl;
	PosCursor(x, y + 1);
	cout << " " << " " << " " << char(220) << char(223) << endl;
	PosCursor(x, y + 2);
	cout << " " << " " << char(219) << " " << " " << endl;
	PosCursor(x, y + 3);
	cout << char(220) << char(223) << " " << " " << " " << endl;
	PosCursor(x, y + 4);
	cout << char(223) << char(223) << char(223) << char(223) << char(223) << endl;
}
