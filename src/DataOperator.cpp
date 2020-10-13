#include "DataOperator.h"

//是否班级前缀合法
static bool IsLegalClassPrefix(unsigned int classPrefix);

//将班级前缀分割为年级号和班号（用于目录读取
//默认前缀合法
static void SeparateClassPrefix(unsigned int classPrefix, unsigned int gradeId_out,unsigned int classId_out);

static void SeparateClassPrefix(unsigned int classPrefix, unsigned int gradeId_out, unsigned int classId_out)
{

}

static bool IsLegalClassPrefix(unsigned int classPrefix)
{
	//年届+班级号，如1901
	if (classPrefix > 1000 && classPrefix < 10000)
	{
		return true;
	}
	return false;
}

bool LoadClassAttr(unsigned int classPrefix, Class* class_out)
{
	if(IsLegalClassPrefix(classPrefix))
	{

	}
}

