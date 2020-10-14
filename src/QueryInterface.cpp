#include"QueryInterface.h"

//讲学生信息“渲染”到字符串中
static void RenderStudentData(Student& stu, std::string& strPrintContent);

static void RenderStudentData(Student& stu, std::string& strPrintContent)
{
	using namespace std;

	bool isSciStu = IsSciClassStudent(stu.unId);

	stringstream ss;

	ss << ("\t姓名：\t" + stu.strName + "\n");
	ss << ("\t学号：\t" + std::to_string(stu.unId) + "\n");
	ss << ("\t科目：\t");
	ss << (isSciStu ? "理科\n\n" : "文科\n\n");

	if (isSciStu)
	{
		ss << ("考试编号\t语文\t数学\t英语\t物理\t化学\t生物\n");
	}
	else
	{
		ss << ("考试编号\t语文\t数学\t英语\t政治\t历史\t地理\n");
	}

	ss << ("------------------------------------------------------------\n");

	for (int index = 0; index != stu.vecExamScores.size(); index++)
	{
		ss << (std::to_string(index + 1) + "\t\t");
		for (int x = 0; x != 6; x++)
		{
			ss << DoubleToValidString(stu.vecExamScores[index].dScore[x]);
			ss << "\t";
		}
		ss << "\n";
	}

	ss << ("\n\n");

	strPrintContent = ss.str();
}

void QueryInterface()
{
	using namespace std;
	int number;

	Student stu;
	string stuPrintContent;

	system("cls");

	cout << "------------------------------------------------\n";
	cout << "\t使用学号查询学生信息\n";
	cout << "\t学号为格式为： 年级+班级+班级内序号\n";
	cout << "\t如19级01班的01同学，则输入190101\n";
	cout << "------------------------------------------------\n";

	cout << "\n请输入学号：\t";
	cin >> number;

	//判断有无此人
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
		//输出学生数据
		LoadStudentData(number, stu);
		RenderStudentData(stu, stuPrintContent);
	}

	vector<string> funcList;
	funcList.push_back("修改");
	funcList.push_back("返回上一级菜单");

	while (true)
	{
		auto input = TextChooserEnter(funcList, stuPrintContent);
		switch (input)
		{
		case 0://修改
			//todo
			break;

		case 1://back
			return;
			break;

		default:
			break;
		}
	}
}