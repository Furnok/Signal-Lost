#include "Main.h"
#include "SetupConsole.h"
#include "File.h"
#include "InterfaceMainMenu.h"
#include "Utils.h"

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
	Utils utils;

    setupConsole.InitConsole();

    file.CreateFileErrors(setupConsole);

    if (argc < 0)
    {
        file.ReadFileError(setupConsole, "NoFile");
    }
    else
    {
        //file.SetPathChapter(argv[1]);

        while (1)
        {
            //file.Read(setupConsole);

            if (interfaceMainMenu.GetShowMainMenu())
            {
				interfaceMainMenu.ShowMainMenu(utils, setupConsole);
            }
        }
    }




    cout << "\nPress Enter to exit...\n";
    cin.get();

    return 0;
}