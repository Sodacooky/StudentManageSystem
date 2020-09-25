#pragma once

#include <string>
#include "List.h"

/*
	科目数量、内容不固定的成绩存放
*/

//单科不固定成绩（自定义名称的成绩
struct SingleScore
{
	//科目名
	std::string strSubjectName;
	//
	double dScore;
};

//成绩"包"
struct Score
{
	//（用于匹配的）学生ID
	unsigned long ulStudentID;
	//各种成绩的链表
	Node* pListScore;
};

//初始化一个分数
Score NewScore();

//对成绩包内的成绩求平均分
double CountAverage(Score* score);

//对成绩包的成绩求绩点
double CountGPA(Score* score);