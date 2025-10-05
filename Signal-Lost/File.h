#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SetupConsole.h"

#include <iostream>
#include <unordered_map>

class File
{
public:
	static std::string DateTime();

	void CreateFileErrors(SetupConsole& setupConsole);
	void ReadFileError(SetupConsole& setupConsole, const std::string& key) const;

	void FileLog(SetupConsole& setupConsole, const std::string& inputChoice);

	void Read(SetupConsole& setupConsole, char* pathChapter);

	[[nodiscard]] std::string GetPathErrorsFolder() const noexcept { return this->pathErrorsFolder; }
	[[nodiscard]] std::string GetPathLogsFolder() const noexcept { return this->pathLogsFolder; }
	[[nodiscard]] int GetChapterNumber() const noexcept { return this->chapterNumber; }
	[[nodiscard]] std::string GetChapterName() const noexcept { return this->chapterName; }
	[[nodiscard]] int GetConnectionPoint() const noexcept { return this->connectionPoint; }
	[[nodiscard]] int GetTrustPoint() const noexcept { return this->trustPoint; }
	[[nodiscard]] int GetStartSceneNumber() const noexcept { return this->startSceneNumber; }

private:
	void CreateFileLog(SetupConsole& setupConsole, const std::string& inputChoice);
	void AddToFileLog(const std::string& inputChoice) const;

	std::string errorFolderName = "Errors";
	std::string logsFolderName = "Logs";

	std::string pathErrorsFolder = "";
	std::string pathLogsFolder = "";

	std::string errorsFileName = "Errors.txt";
	std::string logsFileName = "Logs_";

	std::string pathChapter = "";
	std::string contentChapter = "";

	int chapterNumber = 0;
	std::string chapterName = "Empty";

	int connectionPoint = 0;
	int trustPoint = 0;
	int startSceneNumber = 0;
	int scene = 0;

	bool initialise = false;

	std::unordered_map<std::string, std::string> errors
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