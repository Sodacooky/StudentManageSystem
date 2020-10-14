#pragma once

#include <iostream>
#include <vector>
#include "Type.h"

//计算（一个学生）某场考试的总分
double CountTotalOfExam(ExamScore& exam);

//计算一个学生所有考试的总分的平均分
double CountTotalAverage(Student& stu);

//计算一个班的总分平均分
//传入一个班的学生数组
double CountClassAverage(std::vector<Student>& students);