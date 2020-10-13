#pragma once

#include <string>
#include <fstream>

#include "Type.h"
#include "Tool.h"

//读取一个学生的数据
//stuId学生学号
bool LoadStudentData(unsigned int stuId, Student* stu_out);

//读取一个班级的属性
bool LoadClassAttr(unsigned int classPrefix, Class* class_out);