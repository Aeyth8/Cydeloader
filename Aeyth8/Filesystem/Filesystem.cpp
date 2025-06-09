#include "Filesystem.h"
#include <Windows.h>

/*

Written by Aeyth8

https://github.com/Aeyth8

Copyright (C) 2025 Aeyth8

*/





/*
		Private
*/





/*
		Public
*/


const std::string& FS::GetRelativePath() const
{
	return this->RelativePath;
}

const std::wstring FS::GetRelativePathW() const
{
	return std::wstring(this->RelativePath.begin(), this->RelativePath.end());
}

bool FS::CreateSubfolder(const std::string& FolderName, const std::string& Path)
{
	const std::string& FolderPath = Path.empty() ? this->RelativePath : Path;

	if (!CreateDirectoryA((FolderPath + FolderName).c_str(), 0))
	{
		// This ensures that if the subfolder already exists it still returns true.
		return GetLastError() == ERROR_ALREADY_EXISTS;
	}

	return true;
}

bool FS::Create_File(const std::string& FileName, const std::string& Path)
{
	const std::string& FolderPath = Path.empty() ? this->RelativePath : Path;

	DWORD Result = GetFileAttributesA((FolderPath + FileName).c_str());

	if (Result == INVALID_FILE_ATTRIBUTES)
	{
		return CreateFileA((FolderPath + FileName).c_str(), GENERIC_ALL, 0, 0, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0) != INVALID_HANDLE_VALUE;
	}

	return false;
}