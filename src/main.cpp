//程序从这里开始

#include <iostream>

#include "StartInterface.h"
#include "QueryInterface.h"
#include "RankingInterface.h"
#include "RecordInterface.h"
using namespace std;

int main(int argc, char* argv[])
{
	while (true)
	{
		auto input = StartInterface();
		switch (input)
		{
		case 0://查询
			QueryInterface();
			break;

		case 1://录入
			RecordInterface();
			break;

		case 2://排名
			RankingInterface();
			break;

		default:
			break;
		}
	}
	return 0;
}