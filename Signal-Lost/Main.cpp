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

    cout << "\nPress Enter to exit...\n";
    cin.get();

    return 0;
}