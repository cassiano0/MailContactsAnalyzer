#include "DirectoryManager.h"

DirectoryManager::DirectoryManager(std::string directoryRoot)
{
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));
	hFind = FindFirstFile(szDir, &ffd);
	
	if (hFind == INVALID_HANDLE_VALUE) {
		this->flag = 1;
	}
	else {

	}
}


DirectoryManager::~DirectoryManager()
{
}
