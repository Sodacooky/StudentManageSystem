#include "RankingInterface.h"

void RankingInterface()
{
	using namespace std;

	string head;
	head.append("------------------------------------------------\n");
	head.append("\t查看排名\n");
	head.append("\t请使用方向键选择，回车键确定\n");
	head.append("------------------------------------------------\n");

	//功能列表
	vector<string> funcList;
	funcList.push_back("年级内各班排序");
	funcList.push_back("班级内排序");
	funcList.push_back("返回上一级菜单");

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
			return;
			//break;
		default:
			break;
		}
	}

}