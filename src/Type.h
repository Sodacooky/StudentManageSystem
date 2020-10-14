#pragma once

#include <string>
#include <vector>

/*
考试成绩，六门，
前三门为：语文 数学 英语
后三门根据文理的不同，为政史地或者物化生
*/
struct ExamScore
{
	//分数
	double dScore[6] = { 0.0,0.0,0.0,0.0,0.0,0.0 };
	//总分，若不计算可以忽略
	double dTotal = 0.0;
	//排名，若不使用可以忽略
	int dRank = 0;
};

//学生
struct Student
{
	//学号
	unsigned int unId;
	//
	std::string strName;
	//这个学生的几场考试成绩
	std::vector<ExamScore> vecExamScores;
};

//班级
struct Class
{
	//班级前缀号
	unsigned int unPrefix = 0;
	//总考试数
	unsigned int unExamAmount = 0;
	//班级人数
	unsigned int unStuAmount = 0;
	//班级类别，是否为理科班
	bool bIsSciClass = false;
};