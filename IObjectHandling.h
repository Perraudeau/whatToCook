#ifndef OBJECTHANDLING_H
#define OBJECTHANDLING_H

#include "include.h"

class IObjectHandling
{
public:
	virtual void add() = 0;
	virtual void remove() = 0;
};

#endif // OBJECTHANDLING_H