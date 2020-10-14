#include"QueryInterface.h"

//讲学生信息“渲染”到字符串中
static void RenderStudentData(Student& stu, std::string& strPrintContent);

//修改学生的成绩
static void Edit(Student& stu);

//科目选择，返回和成绩数组对应的
//参数二为科目的文本
static int SelectSubject(unsigned int stuId, std::string& subjectName_out);

static int SelectSubject(unsigned int stuId, std::string& subjectName_out)
{
	using namespace std;
	string tips;
	tips.append("------------------------------------------------\n");
	tips.append("\t选择要修改的科目\n");
	tips.append("------------------------------------------------\n");

	vector<string> subjects;
	if (IsSciClassStudent(stuId))
	{
		subjects.push_back("语文");
		subjects.push_back("数学");
		subjects.push_back("英语");
		subjects.push_back("物理");
		subjects.push_back("化学");
		subjects.push_back("生物");
	}
	else
	{
		subjects.push_back("语文");
		subjects.push_back("数学");
		subjects.push_back("英语");
		subjects.push_back("政治");
		subjects.push_back("历史");
		subjects.push_back("地理");
	}

	auto index = TextChooserEnter(subjects, tips);
	subjectName_out = subjects[index];
	return index;
}

static void Edit(Student& stu)
{
	using namespace std;

	//不清空屏幕让用户可以看见是哪一场考试
	//提示输入考试编号后回车
	unsigned int exam_code = 0;
	while (true)
	{
		cout << "------------------------------------------------\n";
		cout << "\n\n输入要修改的考试号后回车：\t";
		cin >> exam_code;
		if (exam_code > stu.vecExamScores.size())
		{
			cout << "不正确的考试号！请重新输入..." << endl;
		}
		else
		{
			break;
		}
	}

	//让用户选择修改哪一门的成绩
	string subject_name;
	auto subject_index = SelectSubject(stu.unId, subject_name);

	//原成绩信息字符串
	string old_exam_info;
	RenderStudentData(stu, old_exam_info);

	//让用户输入新的分数
	double new_score = 0.0;
	system("cls");
	cout << old_exam_info << "输入第 " << exam_code << " 次考试的 " << subject_name << " 的新成绩：\t";
	cin >> new_score;
	cout << endl;

	//修改
	stu.vecExamScores[exam_code - 1].dScore[subject_index] = new_score;

	//写入
	WriteStudent(stu.unId, stu);
}

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
		ss << ("考试号\t语文\t数学\t英语\t物理\t化学\t生物\t总分\n");
	}
	else
	{
		ss << ("考试号\t语文\t数学\t英语\t政治\t历史\t地理\t总分\n");
	}

	ss << ("-----------------------------------------------------------------------\n");

	for (int index = 0; index != stu.vecExamScores.size(); index++)
	{
		ss << (std::to_string(index + 1) + "\t");
		for (int x = 0; x != 6; x++)
		{
			ss << DoubleToValidString(stu.vecExamScores[index].dScore[x]);
			ss << "\t";
		}
		ss << DoubleToValidString(CountTotalOfExam(stu.vecExamScores[index]));
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
			Edit(stu);
			RenderStudentData(stu, stuPrintContent);
			break;

		case 1://back
			return;
			break;

		default:
			break;
		}
	}
}