#pragma once

#include "revolution.h"

class UserFile;

class SaveDataHandleSequence {
public:
	UserFile* getCurrentUserFile();
	void restoreUserFileConfigData(UserFile*, int);

	void backupCurrentGameData();
};
