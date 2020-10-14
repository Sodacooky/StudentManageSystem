#include "Count.h"

using namespace std;

double CountTotalOfExam(ExamScore& exam)
{
	double ret = 0.0;

	for (auto single_score : exam.dScore)
	{
		ret += single_score;
	}

	exam.dTotal = ret;

	return ret;
}

double CountTotalAverage(Student& stu)
{
	double ret = 0.0;

	for (auto& exam : stu.vecExamScores)
	{
		if (exam.dTotal != 0)
		{
			ret += exam.dTotal;
		}
		else
		{
			ret += CountTotalOfExam(exam);
		}
	}

	return ret;
}
