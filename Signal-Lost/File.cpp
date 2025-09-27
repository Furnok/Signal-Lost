#include "File.h"

string File::DateTime()
{
	// Get the Date and the Time
	const auto now = system_clock::now();

	// Convert Time Point to Time_t Object
	const time_t now_time_t = system_clock::to_time_t(now);

	// Convert Time_t Object to a Local Time Struct
	tm local{};
	localtime_s(&local, &now_time_t);

	// Format the Date and the Time
	char buffer[20];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d_%H-%M-%S", &local);

	return buffer;
}

void File::CreateFileErrors(SetupConsole& setupConsole)
{
	// Initialisation
	filesystem::path path = filesystem::path(setupConsole.GetPathGameFolder()) / errorFolderName;
	this->pathErrorsFolder = path.string() + '\\';

	// Check Folder Exist
	if (!filesystem::exists(path))
	{
		// Create the Folder
		filesystem::create_directories(path);
	}

	const filesystem::path errorFile = path / this->errorsFileName;

	// Check File Exist
	if (!filesystem::exists(errorFile))
	{
		// Open File in Write-Only
		ofstream outfile(errorFile, ios::out);

		// Create All Errors
		for (auto& [key, msg] : errors)
		{
			outfile << key << '=' << msg << endl;
		}

		// Close
		outfile.close();
	}
}

void File::ReadFileError(SetupConsole& setupConsole, const string& key) const
{
	// Clean Console
	system("cls");

	setupConsole.SetTextColor(4);

	// Initialisation
	const filesystem::path path = filesystem::path(GetPathErrorsFolder()) / this->errorsFileName;

	// Open File in Read-Only
	ifstream infile(path, ios::in);

	// Check File Exist
	if (!infile)
	{
		cout << "Error: Unable to Open the Errors File!" << endl;
	}
	else
	{
		string line;

		// Read Line by Line to Find the Key
		while (getline(infile, line)) 
		{
			if (auto pos = line.find('='); pos != string::npos) 
			{
				if (line.substr(0, pos) == key) 
				{
					cout << line.substr(pos + 1) << endl;

					// Close
					infile.close();

					setupConsole.SetTextColor(7);

					(void)_getch();

					exit(EXIT_SUCCESS);
				}
			}
		}

		cout << "Error: Unable to Find the Error!" << endl;
	}

	// Close
	infile.close();

	setupConsole.SetTextColor(7);

	(void)_getch();

	exit(EXIT_SUCCESS);
}

void File::FileLog(SetupConsole& setupConsole, const string& inputChoice)
{
	// Check File Exist
	if (this->pathLogsFolder.empty())
	{
		// Create the File Log
		CreateFileLog(setupConsole, inputChoice);
	}
	else
	{
		// Add to the File Log
		AddToFileLog(inputChoice);
	}
}

void File::CreateFileLog(SetupConsole& setupConsole, const string& inputChoice)
{
	// Initialisation
	filesystem::path path = filesystem::path(setupConsole.GetPathGameFolder()) / this->logsFolderName;
	this->pathLogsFolder = path.string() + '\\';

	// Check Folder Exist
	if (!filesystem::exists(path))
	{
		// Create the Folder
		filesystem::create_directories(path);
	}

	// Add a Name and Date to the File
	this->logsFileName += DateTime() + ".txt";

	// Open File in Write-Only
	ofstream outfile(path / this->logsFileName, ios::out);

	//outfile << "Chapter " << chapter << ", " << "Scene " << scene << ", " << "Input Choice " << input << endl;

	// Close
	outfile.close();
}

void File::AddToFileLog(const string& inputChoice) const
{
	// Initialisation
	filesystem::path path = filesystem::path(GetPathLogsFolder()) / this->logsFileName;

	// Open File in Write-Only
	ofstream outfile(path, ios::app);

	//outfile << "Chapter " << chapter << ", " << "Scene " << scene << ", " << "Input Choice " << input << endl;

	// Close
	outfile.close();
}

void File::Read(SetupConsole& setupConsole)
{
	// Initialisation
	string contentLine = "";
	bool headerRead = false;

	regex pairRegex(R"(\[([^\]=]+)=([^\]]+)\])");
	const vector<string> requiredKeys = { "Chapter", "Name", "Trust", "StartScene" };
	unordered_map<string, bool> keyFound;
	for (auto& key : requiredKeys)
	{
		keyFound[key] = false;
	}

	this->contentChapter.clear();

	this->chapterNumber = 0;
	this->chapterName.clear();
	this->startTrustPoint = 0;
	this->startSceneNumber = 0;

	// Check is Text File
	if (filesystem::path(this->pathChapter).extension() != ".txt")
	{
		ReadFileError(setupConsole, "BadFile");
	}

	// Check is Empty File
	if (filesystem::file_size(this->pathChapter) == 0) 
	{
		ReadFileError(setupConsole, "FileEmpty");
	}

	// Open the File
	ifstream infile(this->pathChapter, ios::in);

	// Read Line by Line
	while (getline(infile, contentLine))
	{
		// Add to the Content
		this->contentChapter += contentLine;

		// First Line of the Chapter
		if (!headerRead)
		{
			headerRead = true;

			// Read All Pairs Key=Value
			for (smatch match; regex_search(contentLine, match, pairRegex); contentLine = match.suffix())
			{
				const string key = match[1];
				const string value = match[2];

				auto safeInt = [&](const char* errKey)
				{
					try
					{
						return stoi(value);
					}
					catch (...)
					{
						ReadFileError(setupConsole, errKey); return 0;
					}
				};

				if (key == "Chapter")
				{
					chapterNumber = max(0, safeInt("ChapterNumber"));
					keyFound[key] = true;
				}
				else if (key == "Name")
				{
					chapterName = value;
					keyFound[key] = true;
				}
				else if (key == "Trust")
				{
					startTrustPoint = clamp(safeInt("TrustNumber"), 0, 100);
					keyFound[key] = true;
				}
				else if (key == "StartScene")
				{
					startSceneNumber = max(0, safeInt("SceneNumber"));
					keyFound[key] = true;
				}
			}
		}
	}

	// Check All Required Keys are Found
	for (auto& [key, found] : keyFound) 
	{
		if (!found) 
		{
			ReadFileError(setupConsole, "HeaderCorrupt");
		}
	}

	cout << "Chapter = " << this->chapterNumber << ", Name = " << this->chapterName << ", Trust = " << this->startTrustPoint << ", StartScene = " << this->startSceneNumber << endl;

	cout << "Content = " << this->contentChapter << endl;

	// Close the File
	infile.close();
}