#include "DataOperator.h"

//是否班级前缀合法
static bool IsLegalClassPrefix(unsigned int classPrefix);

static bool IsLegalClassPrefix(unsigned int classPrefix)
{
	if (classPrefix > 1000 && classPrefix < 10000)
	{
		return true;
	}
	return false;
}

