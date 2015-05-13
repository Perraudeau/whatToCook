#ifndef COMPARABLE_H
#define COMPARABLE_H

#include "include.h"

// This class provides interface for compare receip and ingredients
class IComparable
{
public:
	virtual bool operator ==(const IComparable&) = 0; //use to compare ingredients or receipes
};

#endif // COMPARABLE_H