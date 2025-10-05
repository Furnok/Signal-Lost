#include "File.h"

#include <filesystem>
#include <fstream>
#include <conio.h>
#include <regex>

/// <summary>
/// Get the Date and the Time
/// </summary>
/// <returns></returns>
std::string File::DateTime()
{
	const auto now = std::chrono::system_clock::now();

	const time_t now_time_t = std::chrono::system_clock::to_time_t(now);

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
	std::filesystem::path path = std::filesystem::path(setupConsole.GetPathGameFolder()) / errorFolderName;
	this->pathErrorsFolder = path.string() + '\\';

	if (!std::filesystem::exists(path))
	{
		std::filesystem::create_directories(path);
	}

	const std::filesystem::path errorFile = path / this->errorsFileName;

	if (!std::filesystem::exists(errorFile))
	{
		std::ofstream outfile(errorFile, std::ios::out);

		for (auto& [key, msg] : errors)
		{
			outfile << key << '=' << msg << std::endl;
		}

		outfile.close();
	}
}

/// <summary>
/// Read the File Errors
/// </summary>
/// <param name="setupConsole"></param>
/// <param name="key"></param>
void File::ReadFileError(SetupConsole& setupConsole, const std::string& key) const
{
	system("cls");

	setupConsole.SetTextColor(4);

	const std::filesystem::path path = std::filesystem::path(GetPathErrorsFolder()) / this->errorsFileName;

	std::ifstream infile(path, std::ios::in);

	if (!infile)
	{
		std::cout << "Error: Unable to Open the Errors File!" << std::endl;
	}
	else
	{
		std::string line;

		while (getline(infile, line)) 
		{
			if (auto pos = line.find('='); pos != std::string::npos)
			{
				if (line.substr(0, pos) == key) 
				{
					std::cout << line.substr(pos + 1) << std::endl;

					infile.close();

					setupConsole.SetTextColor(7);

					(void)_getch();

					exit(EXIT_SUCCESS);
				}
			}
		}

		std::cout << "Error: Unable to Find the Error!" << std::endl;
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
void File::FileLog(SetupConsole& setupConsole, const std::string& inputChoice)
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
/// Read the Chapter File
/// </summary>
/// <param name="setupConsole"></param>
void File::Read(SetupConsole& setupConsole, char* pathChapter)
{
	this->pathChapter = pathChapter;

	std::string contentLine = "";
	bool headerRead = false;

	std::regex pairRegex(R"(\[([^\]=]+)=([^\]]+)\])");
	const std::vector<std::string> requiredKeys = { "Chapter", "Name", "Connexion", "Trust", "StartScene" };
	std::unordered_map<std::string, bool> keyFound;
	for (auto& key : requiredKeys)
	{
		keyFound[key] = false;
	}

	this->contentChapter.clear();

	this->chapterNumber = 0;
	this->chapterName.clear();
	this->startSceneNumber = 0;

	if (std::filesystem::path(this->pathChapter).extension() != ".txt")
	{
		ReadFileError(setupConsole, "BadFile");
	}

	if (std::filesystem::file_size(this->pathChapter) == 0)
	{
		ReadFileError(setupConsole, "FileEmpty");
	}

	std::ifstream infile(this->pathChapter, std::ios::in);

	while (getline(infile, contentLine))
	{
		this->contentChapter += contentLine;

		if (!headerRead)
		{
			headerRead = true;

			for (std::smatch match; regex_search(contentLine, match, pairRegex); contentLine = match.suffix())
			{
				const std::string key = match[1];
				const std::string value = match[2];

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
					this->chapterNumber = std::clamp(safeInt("ChapterNumber"), 0, 999999999);
					keyFound[key] = true;
				}
				else if (key == "Name")
				{
					this->chapterName = value.substr(0, 117);
					keyFound[key] = true;
				}
				else if (key == "Connexion")
				{
					if (!initialise)
					{
						this->connectionPoint = std::clamp(safeInt("Connection"), 0, 4);
					}

					keyFound[key] = true;
				}
				else if (key == "Trust")
				{
					if (!initialise)
					{
						this->trustPoint = (std::clamp(safeInt("TrustNumber"), 0, 100) / 25) * 25;
					}

					keyFound[key] = true;
				}
				else if (key == "StartScene")
				{
					this->startSceneNumber = max(0, safeInt("SceneNumber"));
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

	initialise = true;

	infile.close();
}

/// <summary>
/// Create the File Logs
/// </summary>
/// <param name="setupConsole"></param>
/// <param name="inputChoice"></param>
void File::CreateFileLog(SetupConsole& setupConsole, const std::string& inputChoice)
{
	std::filesystem::path path = std::filesystem::path(setupConsole.GetPathGameFolder()) / this->logsFolderName;
	this->pathLogsFolder = path.string() + '\\';

	if (!std::filesystem::exists(path))
	{
		std::filesystem::create_directories(path);
	}

	this->logsFileName += DateTime() + ".txt";

	std::ofstream outfile(path / this->logsFileName, std::ios::out);

	//outfile << "Chapter " << chapter << ", " << "Scene " << scene << ", " << "Input Choice " << input << endl;

	outfile.close();
}

/// <summary>
/// Add to the File Logs
/// </summary>
/// <param name="inputChoice"></param>
void File::AddToFileLog(const std::string& inputChoice) const
{
	std::filesystem::path path = std::filesystem::path(GetPathLogsFolder()) / this->logsFileName;

	std::ofstream outfile(path, std::ios::app);

	//outfile << "Chapter " << chapter << ", " << "Scene " << scene << ", " << "Input Choice " << input << endl;

	outfile.close();
}