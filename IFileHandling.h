#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "include.h"

// This class provides interface for saving loading and removing of receip or ingredients
class IFileHandling
{
public:
	virtual void Save() = 0;
	virtual void Load() = 0;
	virtual void Remove() = 0;
};

#endif // FILEHANDLING_H