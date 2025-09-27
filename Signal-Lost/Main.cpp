#include "Main.h"
#include "SetupConsole.h"
#include "File.h"

int main(int argc, char* argv[])
{
    // Class Initialisation
    SetupConsole setupConsole;
    File file;

    // Setup Console
    setupConsole.InitConsole();

    // Create Files Errors
    file.CreateFileErrors(setupConsole);

    // No File
    if (argv[1] == nullptr)
    {
        // Read the File Errors
        file.ReadFileError(setupConsole, "NoFile");
    }
    else
    {
        // Path to Chapter Initialisation
        file.SetPathChapter(argv[1]);

        // Read the Chapter
        file.Read(setupConsole);
    }




    cout << "\nPress Enter to exit...\n";
    cin.get();

    return 0;
}