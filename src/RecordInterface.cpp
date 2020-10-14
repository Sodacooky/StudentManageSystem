#include"RecordInterface.h"

using namespace std;

//添加学生
static void AddStudent();

//添加班级
static void AddClass();

static void AddClass()
{
	system("cls");

	Class cla;

	cout << "------------------------------------------------\n";
	cout << "\t创建新班级，会自动创建年级\n";
	cout << "\t班级格式为：年级+班别\n";
	cout << "\t如19级的1班为：1901\n";
	cout << "------------------------------------------------\n";
	while (true)
	{
		cout << "请输入班级的编号 :  ";
		cin >> cla.unPrefix;
		cout << endl;
		if (cla.unPrefix > 1000 && cla.unPrefix < 10000)
		{
			break;
		}
		else
		{
			cout << "不正确的班级号，请重新输入..." << endl;
		}
	}

	if (IsClassExist(cla.unPrefix))
	{
		cout << "班级已存在，按任意键退出..." << endl;
		_getch();
		return;
	}

	string tips;
	tips.append("------------------------------------------------\n");
	tips.append("\t创建新班级 ");
	tips.append(to_string(cla.unPrefix));
	tips.append("\n");
	tips.append("\t选择文理科属性\n");
	tips.append("------------------------------------------------\n");

	vector<string> selection = { "文科","理科" };
	cla.bIsSciClass = (TextChooserEnter(selection, tips) == 1 ? true : false);

	SetClassAttr(cla.unPrefix, cla.bIsSciClass, 0);//出于某种原因，肯定是0场了

	return;
}

static void AddStudent()
{
	system("cls");

	Student stu;

	cout << "请输入新学生的姓名 :  ";
	cin >> stu.strName;
	cout << "请输入新学生的学号 :  ";
	cin >> stu.unId;

	if (!IsStudentExist(stu.unId))
	{
		WriteStudent(stu.unId, stu);
		cout << "完成，按任意键退出..." << endl;
		_getch();
		return;
	}
	else
	{
		cout << "学生已存在，按任意键退出..." << endl;
		_getch();
		return;
	}
}

void RecordInterface()
{
	string head;
	head.append("------------------------------------------------\n");
	head.append("\t录入成绩\n");
	head.append("\t请使用方向键选择，回车键确定\n");
	head.append("------------------------------------------------\n");

	//功能列表
	vector<string> funcList;
	funcList.push_back("添加学生");
	funcList.push_back("添加班级");
	funcList.push_back("为学生添加一次成绩");
	funcList.push_back("从文件导入一次考试");
	funcList.push_back("返回上一级菜单");

	while (true)
	{
		auto input = TextChooserEnter(funcList, head);
		switch (input)
		{
		case 0:
			AddStudent();
			break;

		case 1:
			AddClass();
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			return;
			break;

		default:
			break;
		}
	}
}