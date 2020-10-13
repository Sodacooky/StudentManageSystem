#include"Query.h"

void query() {
	using namespace std;
	int number;
	
	string head;
	head.append("------------------------------------------------\n");
	head.append("\t查询信息\n");
	head.append("\t请使用方向键选择，回车键确定\n");
	head.append("------------------------------------------------\n");
	cout << "请输入学号： ";
	cin >>number ;
	//if () {

	//	cout << "无此人或学号错误";

	//}//判断有无此人
	//else {

	//}//输出学生数据

	

	vector<string> funcList;
	funcList.push_back("修改");
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
			return;
			break;
		default:
			break;
		}
	}
}