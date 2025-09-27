#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SetupConsole.h"
#include <fstream>
#include <unordered_map>
#include <chrono>
#include <conio.h>
#include <iostream>
#include <regex>

using namespace std;
using namespace chrono;

class File
{
public:
	static string DateTime();

	void CreateFileErrors(SetupConsole& setupConsole);
	void ReadFileError(SetupConsole& setupConsole, const string& key) const;

	void FileLog(SetupConsole& setupConsole, const string& inputChoice);

	void Read(SetupConsole& setupConsole);

	[[nodiscard]] string GetPathErrorsFolder() const noexcept { return pathErrorsFolder; }
	[[nodiscard]] string GetPathLogsFolder() const noexcept { return pathLogsFolder; }

	void SetPathChapter(string pathChapter) { this->pathChapter = move(pathChapter); }

private:
	void CreateFileLog(SetupConsole& setupConsole, const string& inputChoice);
	void AddToFileLog(const string& inputChoice) const;

	string errorFolderName = "Errors";
	string logsFolderName = "Logs";

	string pathErrorsFolder = "";
	string pathLogsFolder = "";

	string errorsFileName = "Errors.txt";
	string logsFileName = "Logs_";

	string pathChapter = "";
	string contentChapter = "";

	int chapterNumber = 0;
	string chapterName = "";
	int startTrustPoint = 0;
	int startSceneNumber = 0;

	bool startTrustSet = false;

	unordered_map<string, string> errors
	{
		{"BadFile", "The File is not a Text File!"},
		{"FileEmpty", "The File Chapter is Empty!"},
		{"NoSceneExist", "The Scene doesn't Exist!"},
		{"NoFile", "Need to have a File!"},
		{"NoChapterExist", "The Chapter doesn't Exist!"},
		{"ChapterNumber", "The Chapter Number Header is not a Number!"},
		{"TrustNumber", "The Trust Number Header is not a Number!"},
		{"SceneNumber", "The Scene Number Header is not a Number!"},
		{"HeaderCorrupt", "The Header is Corrupt!"},
	};
};