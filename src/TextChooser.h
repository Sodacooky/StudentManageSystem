#pragma once

#include <conio.h>//_getch()
#include <stdio.h>//system()

#include <iostream>
#include <vector>
#include <string>

//使用std::vector<std::string>创建一个选择器并进入
//std::string strTips为显示在列表上的提示文本
//返回选择的序号
int TextChooserEnter(std::vector<std::string>& content, const std::string& strTips);