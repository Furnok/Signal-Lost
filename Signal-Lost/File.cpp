#include "File.h"

string File::DateTime()
{
	// Get the Date and the Time
	auto now = system_clock::now();

	// Convert Time Point to Time_t Object
	time_t now_time_t = system_clock::to_time_t(now);

	// Convert Time_t Object to a Local Time Struct
	tm* local_time = localtime(&now_time_t);

	// Format the Date and the Time
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d_%H-%M-%S", local_time);

	return buffer;
}

void File::CreateFileErrors(SetupConsole& setupConsole)
{
	// Initialisation
	string path = setupConsole.GetPathGameFolder() + string(this->errorFolderName.begin(), this->errorFolderName.end()) + "\\";
	this->pathErrorsFolder = path;

	// Check Folder Exist
	if (!filesystem::exists(path))
	{
		// Create the Folder
		filesystem::create_directories(path);
	}

	// Check File Exist
	if (!filesystem::exists(path + this->errorsFileName))
	{
		// Open File in Write-Only
		ofstream outfile(path + this->errorsFileName, ios::out);

		// Create All Errors
		for (const auto& [key, message] : errors)
		{
			outfile << key << "=" << message << endl;
		}

		// Close
		outfile.close();
	}
}

void File::ReadFileError(SetupConsole& setupConsole, const string& key) const
{
	// Initialisation
	string path = GetPathErrorsFolder() + this->errorsFileName;

	// Open File in Read-Only
	ifstream infile(path, ios::in);

	setupConsole.SetTextColor(4);

	// Check File Exist
	if (!infile)
	{
		cout << "Error: Unable to Open the Errors File." << endl;
	}
	else
	{
		string line;

		// Read Line by Line
		while (getline(infile, line)) 
		{
			size_t pos = line.find('=');

			if (pos != string::npos) 
			{
				string fileKey = line.substr(0, pos);
				string message = line.substr(pos + 1);

				// Find the Key
				if (fileKey == key)
				{
					cout << message << endl;

					setupConsole.SetTextColor(7);

					// Close
					infile.close();
					return;
				}
			}
		}

		cout << "Error: Unable to Find the Error." << endl;

		// Close
		infile.close();
	}

	setupConsole.SetTextColor(7);
}

void File::FileLog(SetupConsole& setupConsole, string inputChoice)
{
	// Check File Exist
	if (this->pathLogsFolder == "")
	{
		// Create the File Log
		CreateFileLog(setupConsole, inputChoice);
	}
	else
	{
		// Add to the File Log
		AddToFileLog(setupConsole, inputChoice);
	}
}

void File::CreateFileLog(SetupConsole& setupConsole, string inputChoice)
{
	// Initialisation
	string path = setupConsole.GetPathGameFolder() + string(this->logsFolderName.begin(), this->logsFolderName.end()) + "\\";
	this->pathLogsFolder = path;

	// Check Folder Exist
	if (!filesystem::exists(path))
	{
		// Create the Folder
		filesystem::create_directories(path);
	}

	// Add a Name and Date to the File
	this->logsFileName = this->logsFileName + DateTime() + ".txt";

	// Open File in Write-Only
	ofstream outfile(path + this->logsFileName, ios::out);

	//outfile << "Chapter " << chapter << ", " << "Scene " << scene << ", " << "Input Choice " << input << endl;

	// Close
	outfile.close();
}

void File::AddToFileLog(SetupConsole& setupConsole, string inputChoice) const
{
	// Initialisation
	string path = GetPathLogsFolder() + this->logsFileName;

	// Open File in Write-Only
	ofstream outfile(path, ios::app);

	//outfile << "Chapter " << chapter << ", " << "Scene " << scene << ", " << "Input Choice " << input << endl;

	// Close
	outfile.close();
}

string File::Read(string pathChapter) const
{

}