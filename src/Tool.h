#pragma once

#include <io.h>

#include <string>

//测试指定文件是否存在
bool IsFileExist(const std::string& filename);

//测试指定目录是否存在
bool IsPathExist(const std::string& filename);

//一段字符串转换成无符号整数
//假定输入是规范的，全是数字，非数字将会被跳过
unsigned int StringToUInt(const std::string& str);

//将浮点数转换为后面没有多余0的字符串
std::string DoubleToValidString(double x);

//用于mkdir
//把 "/" 斜杠全部换成 "\" 斜杠
void TransSlash(std::string& str);