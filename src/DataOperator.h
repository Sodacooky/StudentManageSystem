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