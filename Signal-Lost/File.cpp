#include "File.h"

/// <summary>
/// Get the Date and the Time
/// </summary>
/// <returns></returns>
string File::DateTime()
{
	const auto now = system_clock::now();

	const time_t now_time_t = system_clock::to_time_t(now);

	tm local{};
	localtime_s(&local, &now_time_t);

	char buffer[20];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d_%H-%M-%S", &local);

	return buffer;
}

/// <summary>
/// Create the File Errors
/// </summary>
/// <param name="setupConsole"></param>
void File::CreateFileErrors(SetupConsole& setupConsole)
{
	filesystem::path path = filesystem::path(setupConsole.GetPathGameFolder()) / errorFolderName;
	this->pathErrorsFolder = path.string() + '\\';

	if (!filesystem::exists(path))
	{
		filesystem::create_directories(path);
	}

	const filesystem::path errorFile = path / this->errorsFileName;

	if (!filesystem::exists(errorFile))
	{
		ofstream outfile(errorFile, ios::out);

		for (auto& [key, msg] : errors)
		{
			outfile << key << '=' << msg << endl;
		}

		outfile.close();
	}
}

/// <summary>
/// Read the File Errors
/// </summary>
/// <param name="setupConsole"></param>
/// <param name="key"></param>
void File::ReadFileError(SetupConsole& setupConsole, const string& key) const
{
	system("cls");

	setupConsole.SetTextColor(4);

	const filesystem::path path = filesystem::path(GetPathErrorsFolder()) / this->errorsFileName;

	ifstream infile(path, ios::in);

	if (!infile)
	{
		cout << "Error: Unable to Open the Errors File!" << endl;
	}
	else
	{
		string line;

		while (getline(infile, line)) 
		{
			if (auto pos = line.find('='); pos != string::npos) 
			{
				if (line.substr(0, pos) == key) 
				{
					cout << line.substr(pos + 1) << endl;

					infile.close();

					setupConsole.SetTextColor(7);

					(void)_getch();

					exit(EXIT_SUCCESS);
				}
			}
		}

		cout << "Error: Unable to Find the Error!" << endl;
	}

	infile.close();

	setupConsole.SetTextColor(7);

	(void)_getch();

	exit(EXIT_SUCCESS);
}

/// <summary>
/// Logs Manager for the Logs File
/// </summary>
/// <param name="setupConsole"></param>
/// <param name="inputChoice"></param>
void File::FileLog(SetupConsole& setupConsole, const string& inputChoice)
{
	if (this->pathLogsFolder.empty())
	{
		CreateFileLog(setupConsole, inputChoice);
	}
	else
	{
		AddToFileLog(inputChoice);
	}
}

/// <summary>
/// Create the File Logs
/// </summary>
/// <param name="setupConsole"></param>
/// <param name="inputChoice"></param>
void File::CreateFileLog(SetupConsole& setupConsole, const string& inputChoice)
{
	filesystem::path path = filesystem::path(setupConsole.GetPathGameFolder()) / this->logsFolderName;
	this->pathLogsFolder = path.string() + '\\';

	if (!filesystem::exists(path))
	{
		filesystem::create_directories(path);
	}

	this->logsFileName += DateTime() + ".txt";

	ofstream outfile(path / this->logsFileName, ios::out);

	//outfile << "Chapter " << chapter << ", " << "Scene " << scene << ", " << "Input Choice " << input << endl;

	outfile.close();
}

/// <summary>
/// Add to the File Logs
/// </summary>
/// <param name="inputChoice"></param>
void File::AddToFileLog(const string& inputChoice) const
{
	filesystem::path path = filesystem::path(GetPathLogsFolder()) / this->logsFileName;

	ofstream outfile(path, ios::app);

	//outfile << "Chapter " << chapter << ", " << "Scene " << scene << ", " << "Input Choice " << input << endl;

	outfile.close();
}

/// <summary>
/// Read the Chapter File
/// </summary>
/// <param name="setupConsole"></param>
void File::Read(SetupConsole& setupConsole, char* pathChapter)
{
	this->pathChapter = pathChapter;

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

	if (filesystem::path(this->pathChapter).extension() != ".txt")
	{
		ReadFileError(setupConsole, "BadFile");
	}

	if (filesystem::file_size(this->pathChapter) == 0) 
	{
		ReadFileError(setupConsole, "FileEmpty");
	}

	ifstream infile(this->pathChapter, ios::in);

	while (getline(infile, contentLine))
	{
		this->contentChapter += contentLine;

		if (!headerRead)
		{
			headerRead = true;

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

	for (auto& [key, found] : keyFound) 
	{
		if (!found) 
		{
			ReadFileError(setupConsole, "HeaderCorrupt");
		}
	}

	infile.close();
}