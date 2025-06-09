#pragma once
#include <string>
#include <ostream>

/*

Written by Aeyth8

https://github.com/Aeyth8

Copyright (C) 2025 Aeyth8

*/

// Filesystem [FS] is the main class for making files/folders relative to path of the DLL.
class FS
{
private:


	const std::string RelativePath;



public:


	// Main constructor for a static instance.
	FS(const std::string& RelativePath) : RelativePath(RelativePath) {};

	const std::string& GetRelativePath() const;
	const std::wstring GetRelativePathW() const;

	// Creates a named subfolder in the relative path unless overridden.
	bool CreateSubfolder(const std::string& FolderName, const std::string& Path = "");
	bool Create_File(const std::string& FileName, const std::string& Path = "");
	//std::ofstream& CreateFile(const std::string& FileName, const std::string& Path = "");

};