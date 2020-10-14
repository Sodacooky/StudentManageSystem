#include"inputInterface.h"

void addStudent();
void inputStudentScore();
void reviseScore();

using namespace std;

void inputInterface() {
	

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
			addStudent();
			break;
		case 1:
			inputStudentScore();
			break;
		case 2:
			reviseScore();
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}

void addStudent() {
	system("cls");
	Student stu;
	cout << "请输入新学生的姓名 :  ";
	cin >> stu.strName;
	cout << "请输入新学生的学号 :  ";
	cin >> stu.unId;
}


void inputStudentScore(){
	system("cls");
	int number;
	Student stu;
	cout << "\n请输入学号：\t";
	cin >> number;
	bool isSciStu = IsSciClassStudent(stu.unId);
	if (IsStudentExist(number) == false)
	{
		cout << "------------------------------------------------\n";
		cout << "\t无此人或学号错误，按任意键退出查询..." << endl;
		cout << "------------------------------------------------\n";
		_getch();
		return;
	}
	else
	{
		string head;
		head.append("------------------------------------------------\n");
		head.append("\t为学生添加考试成绩\n");
		head.append("\t请使用方向键选择，回车键确定\n");
		head.append("------------------------------------------------\n");
		vector<string> funcList;
		if (isSciStu)
		{
			funcList.push_back("语文");
			funcList.push_back("数学");
			funcList.push_back("英文");
			funcList.push_back("物理");
			funcList.push_back("化学");
			funcList.push_back("生物");
			funcList.push_back("返回");
		}
		else
		{

			funcList.push_back("语文");
			funcList.push_back("数学");
			funcList.push_back("英文");
			funcList.push_back("政治");
			funcList.push_back("历史");
			funcList.push_back("地理");
			funcList.push_back("返回");
		}

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
				//todo
				break;

			case 4:
				//todo
				break;

			case 5:
				//todo
				break;

			case 6:
				return;
				break;
			default:
				break;
			}
		}
	}
}


void reviseScore() {
	system("cls");
	int number;
	Student stu;
	cout << "\n请输入学号：\t";
	cin >> number;
	bool isSciStu = IsSciClassStudent(stu.unId);
	if (IsStudentExist(number) == false)
	{
		cout << "------------------------------------------------\n";
		cout << "\t无此人或学号错误，按任意键退出查询..." << endl;
		cout << "------------------------------------------------\n";
		_getch();
		return;
	}
	else
	{
		string head;
		head.append("------------------------------------------------\n");
		head.append("\t修改学生考试成绩\n");
		head.append("\t请使用方向键选择，回车键确定\n");
		head.append("------------------------------------------------\n");
		vector<string> funcList;
		if (isSciStu)
		{
			funcList.push_back("语文");
			funcList.push_back("数学");
			funcList.push_back("英文");
			funcList.push_back("物理");
			funcList.push_back("化学");
			funcList.push_back("生物");
			funcList.push_back("返回");
		}
		else
		{

			funcList.push_back("语文");
			funcList.push_back("数学");
			funcList.push_back("英文");
			funcList.push_back("政治");
			funcList.push_back("历史");
			funcList.push_back("地理");
			funcList.push_back("返回");
		}

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
				//todo
				break;

			case 4:
				//todo
				break;

			case 5:
				//todo
				break;
			case 6:
				return;
				break;
			default:
				break;
			}
		}
	}
}

