#pragma once

#include"Check.h"
using namespace std;
int check() {
	while (true)
	{
		auto input = StartInterface();
		switch (input)
		{
		case 0:
			query();
			break;
		case 1:
			inputInterface();
			break;
		case 2:
			RankingInterface();
			break;
		default:
			break;
		}
	}
	return 0;
}