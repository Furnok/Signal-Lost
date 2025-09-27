#include "Main.h"
#include "SetupConsole.h"
#include "File.h"

int main(int argc, char* argv[])
{
    SetupConsole setupConsole;
    File file;

    setupConsole.InitConsole();

    file.CreateFileErrors(setupConsole);

    if (argc < 2)
    {
        file.ReadFileError(setupConsole, "NoFile");
    }
    else
    {
        file.SetPathChapter(argv[1]);

        file.Read(setupConsole);
    }




    cout << "\nPress Enter to exit...\n";
    cin.get();

    return 0;
}