#include "Main.h"

/// <summary>
/// Main Function
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int argc, char* argv[])
{
    SetupConsole setupConsole;
    File file;
	InterfaceMainMenu interfaceMainMenu;
	InterfaceGame interfaceGame;
	Utils utils;

    setupConsole.InitConsole();

    file.CreateFileErrors(setupConsole);

    if (argc < 2)
    {
        file.ReadFileError(setupConsole, "NoFile");
    }
    else
    {
        while (1)
        {
            file.Read(setupConsole, argv[1]);

            if (interfaceMainMenu.GetShowMainMenu())
            {
				//interfaceMainMenu.ShowMainMenu(utils, setupConsole);
            }

            if (interfaceGame.GetNewChapter())
            {
				interfaceGame.ShowTransitionChapter(utils, setupConsole, file);
            }

            system("cls");
        }
    }




    cout << "\nPress Enter to exit...\n";
    cin.get();

    return 0;
}