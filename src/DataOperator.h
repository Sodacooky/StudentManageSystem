#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "Type.h"
#include "Tool.h"

//读取一个学生的数据
//stuId学生学号
bool LoadStudentData(unsigned int stuId, Student& stu_out);

//读取一个班的所有学生数据
//返回读入的学生数量(vector的size
int LoadAllStuInClass(unsigned int classPrefix, std::vector<Student>& stus);

//读取一个班级的属性
bool LoadClassAttr(unsigned int classPrefix, Class& class_out);

//学生是否存在（实际上就是LoadStudentData的返回值
bool IsStudentExist(unsigned int stuId);

//学生是否为理科生（默认学生存在
bool IsSciClassStudent(unsigned int stuId);

//为一个学生写入一次新的考试成绩
bool WriteNewScoreToStudent(unsigned int stuId, const ExamScore& score);

//写入一个学生
//如果学生本来不存在则创建新文件，否则覆盖
void WriteStudent(unsigned int stuId, const Student& student);

//创建年级
void CreateGrade(unsigned int gradeId);

//创建班级
//要求完整的班级前缀，如果年级不存在则自动新建
void CreateClass(unsigned int classPrefix);

//设置班级属性
//要求完整的班级前缀，是否是理科班，考试总数
void SetClassAttr(unsigned int classPrefix, bool isSciClass, unsigned int examAmount);