#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "StartInterface.h"
#include "TextChooser.h"
#include"RankingInterface.h"
using namespace std;
int check() {
	int index = 0;
	index = StartInterface();
	if (index == 0) {

	}

	else if (index == 1) {

	}

	else if (index == 2) {
		int index = 0;
		index = RankingInterface();
		if (index == 0) {
			cout << 1;
		}
		else if (index == 1) {
			cout << 2;
		}
		else if (index == 2) {
			
		}
	}

	return 0;
}