#pragma once
#include <string>
#include <strsafe.h>
#include <windows.h>

#include <dirent.h>

#pragma comment(lib, "User32.lib")
class DirectoryManager
{
protected:
	HANDLE hFind = INVALID_HANDLE_VALUE;
	TCHAR szDir[MAX_PATH];
	WIN32_FIND_DATA ffd;
	TCHAR *childs;
public:
	int flag = 0x0; // 1 - Directory list fail
	DirectoryManager(std::string directoryRoot);
	~DirectoryManager();
};

