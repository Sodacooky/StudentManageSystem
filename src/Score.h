#pragma once

#include <string>

/*
	科目数量、内容不固定的成绩存放
*/

//单科不固定成绩（自定义名称的成绩
struct SingleScore
{
	std::string strSubjectName;
	double dScore;
};

//成绩"包"
struct Score
{

};