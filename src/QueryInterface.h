#pragma once
#include<iostream>
#include <sstream>
#include <iomanip>
#include<string>
#include<vector>
#include "TextChooser.h"
#include"DataOperator.h"

//查询界面
//操作完会返回
void QueryInterface();
static void RenderStudentData(Student& stu, std::string& strPrintContent);
