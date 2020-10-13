#include"Query.h"

//
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
			ss<< to_string((int)stu.vecExamScores[index].dScore[x]);
			ss << "\t";
		}
		ss << "\n";
	}

	ss << ("\n\n");

	strPrintContent = ss.str();
}

void query() {
	using namespace std;
	int number;

	Student stu;
	string stuPrintContent;

	system("cls");

	cout << "请输入学号： ";
	cin >> number;

	if (IsStudentExist(number) == false)
	{
		cout << "无此人或学号错误" << endl;
		_getch();
		return;
	}//判断有无此人
	else {
		LoadStudentData(number, stu);
		RenderStudentData(stu, stuPrintContent);
	}//输出学生数据

	vector<string> funcList;
	funcList.push_back("修改");
	funcList.push_back("返回上一级菜单");

	while (true)
	{
		auto input = TextChooserEnter(funcList, stuPrintContent);
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