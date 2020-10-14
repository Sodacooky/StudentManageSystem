#include"inputInterface.h"

void addStudent();//添加学生
static void ImportScoreFile();//添加考试成绩


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
	funcList.push_back("从文件导入一次考试");
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
			ImportScoreFile();
			break;
		case 2:
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
	WriteStudent(stu.unId, stu);
	int number = stu.unId;
	if (IsStudentExist(number) == false)
	{
		cout << "------------------------------------------------\n";
		cout << "\t添加学生失败，按任意键退出查询..." << endl;
		cout << "------------------------------------------------\n";
		_getch();
		return;
	}
	else
	{
		cout << "------------------------------------------------\n";
		cout << "\t添加学生成功，按任意键退出查询..." << endl;
		cout << "------------------------------------------------\n";
		_getch();
		return;
	}
}

static void ImportScoreFile()
{

}