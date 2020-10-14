#include"inputInterface.h"

void inputInterface() {
	using namespace std;

	string head;
	head.append("------------------------------------------------\n");
	head.append("\t录入成绩\n");
	head.append("\t请使用方向键选择，回车键确定\n");
	head.append("------------------------------------------------\n");

	//功能列表
	vector<string> funcList;
	funcList.push_back("添加学生");
	funcList.push_back("为学生添加考试成绩");
	funcList.push_back("修改学生考试成绩");
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
			//todo
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}