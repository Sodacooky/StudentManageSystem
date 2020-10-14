#include <iostream>
#include "Type.h"
using namespace std;


/*
countTotalPoints		计算某场考试的总分
countEryTotalPoints		计算每场考试的总分
countAverageScore		计算某场考试的平均分
countEryAverageScore	计算每场考试的平均分
a代表第几场考试
*/

double countTotalPoints(Student* stu, int a) {		
	double sum = 0;
	for (int i = 0; i <= 5; i++) {
		sum += stu->vecExamScores[a].dScore[i];
	}
	return sum;
}

double countEryTotalPoints(Student* stu, int a) {
	int sum = 0;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= 5; j++) {
			sum += stu->vecExamScores[a].dScore[i];
		}
	}
	return sum;
}

double countAverageScore(Student* stu, int a) {
	double sum = 0;
	double avrscore = 0;
	for (int i = 0; i <= 5; i++) {
		sum += stu->vecExamScores[a].dScore[i];
	}
	avrscore = sum / 6.0;
	return avrscore;
}

double countEryAverageScore(Student* stu, int a) {
	double sum = 0;
	double avrscore = 0;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= 5; j++) {
			sum += stu->vecExamScores[a].dScore[i];
		}
	}
	avrscore = sum / (6.0 * a);
	return avrscore;
}