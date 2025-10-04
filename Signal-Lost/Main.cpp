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

    if (argc < 0)
    {
        //file.ReadFileError(setupConsole, "NoFile");
    }
    else
    {
        //std::string path = argv[1];

        while (1)
        {
            //file.Read(setupConsole, path);

            if (interfaceMainMenu.GetDisplay())
            {
				//interfaceMainMenu.DisplayMainMenu(utils, setupConsole);
            }

            if (interfaceGame.GetDisplay())
            {
				//interfaceGame.DisplayTransitionChapter(utils, setupConsole, file);
            }

			interfaceGame.DisplayInterfaceGame(utils, setupConsole, file);

            while (!1)
            {
                
            }
        }
    }




    std::cout << "\nPress Enter to exit...\n";
    std::cin.get();

    return 0;
}