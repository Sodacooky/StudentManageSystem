#include "RankingInterface.h"

void RankingInterface()
{
	using namespace std;

	string head;
	head.append("------------------------------------------------\n");
	head.append("\t查看排名，选择你要查看的排名\n");
	head.append("\t请使用方向键选择，回车键确定\n");
	head.append("------------------------------------------------\n");

	//功能列表
	vector<string> funcList;
	funcList.push_back("班平均分排名");
	funcList.push_back("学生总分(多次平均)级排名");
	funcList.push_back("班级内总分排序");
	funcList.push_back("返回");

	while (true)
	{
		auto input = TextChooserEnter(funcList, head);
		switch (input)
		{
		case 0:
			//todo
			break;
		case 1:
			//todo
			break;
		case 2:
			break;
		case 3:
			return;
			//break;
		default:
			break;
		}
	}

}