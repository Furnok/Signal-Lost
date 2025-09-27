#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SetupConsole.h"
#include <fstream>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace chrono;

class File
{
public:
	static string DateTime();
	void CreateFileErrors(SetupConsole& setupConsole);
	void ReadFileError(SetupConsole& setupConsole, const string& name) const;
	void FileLog(SetupConsole& setupConsole, string inputChoice);
	void CreateFileLog(SetupConsole& setupConsole, string inputChoice);
	void AddToFileLog(SetupConsole& setupConsole, string inputChoice) const;
	string Read(string pathChapter) const;

	string GetPathErrorsFolder() const { return pathErrorsFolder; }
	string GetPathLogsFolder() const { return pathLogsFolder; }

private:
	string errorFolderName = "Errors";
	string logsFolderName = "Logs";

	string pathErrorsFolder = "";
	string pathLogsFolder = "";

	string errorsFileName = "Errors.txt";
	string logsFileName = "Logs_";

	unordered_map<string, string> errors
	{
		{"BadFile", "Bad File!"},
		{"FileEmpty", "File Empty!"},
		{"NoSceneExist", "Scene Doesn't Exist!"},
		{"NoFile", "No File Exist!"},
		{"NoChapterExist", "Chapter Doesn't Exist!"},
	};
};