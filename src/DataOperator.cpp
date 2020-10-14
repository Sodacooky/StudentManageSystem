﻿#include "DataOperator.h"

//是否班级前缀合法
static bool IsLegalClassPrefix(unsigned int classPrefix);

//将班级前缀分割为年级号和班号（用于目录读取），注意班号是只有一位
//默认前缀合法
static void SeparateClassPrefix(unsigned int classPrefix, unsigned int& gradeId_out, unsigned int& classId_out);

//将班号或者年级号或者班内学号等两位数的号转化为字符串，如果只有一位数则补0
static std::string CodeToString(unsigned int code);

//计算目录下有多少个学生文件
static int CountStudentAmount(const std::string& path, unsigned int classPrefix);

//用班级前缀生成路径名称
static std::string ClassPrefixToPath(unsigned int classPrefix);

static std::string ClassPrefixToPath(unsigned int classPrefix)
{
	unsigned int gradeId = 0, classId = 0;
	SeparateClassPrefix(classPrefix, gradeId, classId);

	std::string path = "data/"
		+ CodeToString(gradeId) + "/"
		+ CodeToString(classId) + "/";

	return path;
}

static int CountStudentAmount(const std::string& path, unsigned int classPrefix)
{
	int amount = 0;

	std::string search_line = path + "/" + std::to_string(classPrefix) + "*";

	//来自Tool.h中io.h
	_finddata_t fileInfo;
	auto findHandle = _findfirst(search_line.c_str(), &fileInfo);
	if (findHandle == -1)
	{
		return 0;
	}

	while (true)
	{
		if (fileInfo.attrib != _A_SUBDIR)
		{
			amount++;
		}
		if (_findnext(findHandle, &fileInfo) == -1)
		{
			_findclose(findHandle);
			return amount;
		}
	}

	//不可能从这里return的
	return 0;
}

static std::string CodeToString(unsigned int code)
{
	if (code > 100) return "error";

	std::string ret = std::to_string(code);

	if (code < 10)
	{
		ret.insert(ret.begin(), '0');
	}

	return ret;
}

static void SeparateClassPrefix(unsigned int classPrefix, unsigned int& gradeId_out, unsigned int& classId_out)
{
	//假如为1902
	//则为19
	gradeId_out = classPrefix / 100;
	//同上假设则为1902-(19*100=1900)=2
	classId_out = classPrefix - ((classPrefix / 100) * 100);
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

bool LoadStudentData(unsigned int stuId, Student& stu_out)
{
	unsigned int classPrefix = stuId / 100;

	std::string filename = ClassPrefixToPath(classPrefix) + std::to_string(stuId) + ".txt";
	if (!IsFileExist(filename))
	{
		return false;
	}

	stu_out.unId = stuId;

	std::ifstream file(filename);
	file >> stu_out.strName;

	//读取成绩
	stu_out.vecExamScores.clear();

	ExamScore tmpExamScore;

	while (file.peek() != EOF)
	{
		for (int index = 0; index != 6; index++)
		{
			file >> tmpExamScore.dScore[index];
		}
		stu_out.vecExamScores.push_back(tmpExamScore);
	}

	file.close();
	return true;
}

int LoadAllStuInClass(unsigned int classPrefix, std::vector<Student>& stus)
{
	return 0;
}

bool LoadClassAttr(unsigned int classPrefix, Class & class_out)
{
	if (!IsLegalClassPrefix(classPrefix))
	{
		return false;
	}

	//制作路径字符串
	std::string path = ClassPrefixToPath(classPrefix);
	if (!IsPathExist(path))
	{
		return false;
	}

	//读取班级学生数
	class_out.unStuAmount = CountStudentAmount(path, classPrefix);

	//班级属性文件路径
	std::string filename = path + "/info.txt";
	if (!IsFileExist(filename))
	{
		return false;
	}

	class_out.unPrefix = classPrefix;

	//读取属性文件
	int temp = 0;
	std::ifstream file(filename);

	//文理科数据
	file >> temp;
	class_out.bIsSciClass = temp == 1 ? true : false;

	//总考试数
	file >> class_out.unExamAmount;

	file.close();
	return true;
}

bool IsStudentExist(unsigned int stuId)
{
	unsigned int classPrefix = stuId / 100;

	std::string filename = ClassPrefixToPath(classPrefix) + std::to_string(stuId) + ".txt";
	if (!IsFileExist(filename))
	{
		return false;
	}
	return true;
}

bool IsSciClassStudent(unsigned int stuId)
{
	Class class_attr;

	LoadClassAttr(stuId / 100, class_attr);

	return class_attr.bIsSciClass;
}

bool WriteNewScoreToStudent(unsigned int stuId, const ExamScore& score)
{
	//首先这个学生存不存在
	if (!IsStudentExist(stuId))
	{
		return false;
	}

//首先读取进来
	Student stu;
	LoadStudentData(stuId, stu);

	//然后将成绩加上
	stu.vecExamScores.push_back(score);

	//写回去
	WriteStudent(stuId, stu);

	return true;
}

void WriteStudent(unsigned int stuId, const Student& student)
{
	using namespace std;


}
