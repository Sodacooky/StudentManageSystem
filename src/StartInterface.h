#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "TextChooser.h"

//返回功能序号
int StartInterface()
{
	using namespace std;

	//开头的文本
	string head;
	head.append("------------------------------------------------\n");
	head.append("\t欢迎使用学生成绩管理系统\n");
	head.append("\t请使用方向键选择，回车键确定\n");
	head.append("------------------------------------------------\n");

	//功能列表
	vector<string> funcList;
	funcList.push_back("查询/修改指定学生成绩");
	funcList.push_back("录入成绩");
	funcList.push_back("查看排名");

	return TextChooserEnter(funcList, head);
}