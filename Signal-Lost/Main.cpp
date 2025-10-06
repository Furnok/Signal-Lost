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
        std::string path = argv[1];

        while (1)
        {
            if (interfaceMainMenu.GetDisplay())
            {
				//interfaceMainMenu.DisplayMainMenu(utils, setupConsole);
            }

            file.Read(setupConsole, interfaceGame, path);

            if (interfaceGame.GetDisplay())
            {
				//interfaceGame.DisplayTransitionChapter(utils, setupConsole, file);
            }

			interfaceGame.DisplayInterfaceGame(utils, setupConsole);

            while (1)
            {
                interfaceGame.DisplayText(utils, setupConsole, file);
            }
        }
    }




    std::cout << "\nPress Enter to exit...\n";
    std::cin.get();

    return 0;
}