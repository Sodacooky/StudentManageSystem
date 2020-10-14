#include "RankingInterface.h"

//班级内总分排名
static void TotalRankInClass();

//班级输入
static unsigned int ClassInput();

//选择考试
//返回考试index
static int SelectExam(const Class& cla);

//将容器内的学生按指定考试总分从高到底排序
static void SortTotalRank(std::vector<Student>& vecStu, int examIndex);

//级排名
static void TotalRankInGrade();

//年级输入
static int GradeInput();

//选择文理科
static int SelectSubject(unsigned int gradeId);

//将容器内的学生按总分平均分从高到低排序
static void SortTotalAverageRank(std::vector<Student>& vecStu);

static void SortTotalAverageRank(std::vector<Student>& vecStu)
{
	//算出学生的分
	for (auto&stu : vecStu)
	{
		double tmp = 0.0;
		for (auto&exam : stu.vecExamScores)
		{
			tmp += CountTotalOfExam(exam);
		}
		tmp /= stu.vecExamScores.size();
		stu.vecExamScores[0].dTotal = tmp;
	}

	//排序
	for (int i = 0; i < vecStu.size(); i++)
	{
		for (int j = 1; j < vecStu.size(); j++)
		{
			if (vecStu[j - 1].vecExamScores[0].dTotal < vecStu[j].vecExamScores[0].dTotal)
			{
				std::swap(vecStu[j - 1], vecStu[j]);
			}
		}
	}
}

static int SelectSubject(unsigned int gradeId)
{
	using namespace std;

	string tips;
	tips.append("------------------------------------------------\n");
	tips.append("\t查看 ");
	tips.append(to_string(gradeId));
	tips.append(" 级总分排名\n");
	tips.append("\t选择文理科\n");
	tips.append("------------------------------------------------\n");

	vector<string> selection = { "文科","理科" };
	return TextChooserEnter(selection, tips);
}

static int GradeInput()
{
	using namespace std;

	system("cls");

	unsigned int gradeId;
	//输入班级号
	while (true)
	{
		cout << "------------------------------------------------\n";
		cout << "\t查看级总分排名\n";
		cout << "\t输入年级\n";
		cout << "\t如19级为：19\n";
		cout << "------------------------------------------------\n";

		cout << "\n请输入年级：\t";
		cin >> gradeId;
		cout << endl;
		if (!IsGradeExist(gradeId))
		{
			cout << "------------------------------------------------\n";
			cout << "不正确的年级，请重新输入...\n";
		}
		else
		{
			break;
		}
	}

	return gradeId;
}

static void TotalRankInGrade()
{
	using namespace std;

	//选择年级
	auto gradeId = GradeInput();

	//选择文理科
	bool isSci = SelectSubject(gradeId) == 1 ? true : false;

	//读入班
	vector<Class> vecClass;
	LoadAllClassInGrade(gradeId, vecClass);

	//读入学生
	vector<Student> vecStudent;
	for (auto&cla : vecClass)
	{
		if (cla.bIsSciClass == isSci)
		{
			LoadAllStuInClass(cla.unPrefix, vecStudent);
		}
	}

	//排序
	SortTotalAverageRank(vecStudent);

	//打印
	system("cls");
	cout << "【 " << gradeId << " 级 " << (isSci ? "理科" : "文科") << " 排名】" << endl;
	if (isSci)
	{
		cout << "排名\t姓名\t\t总分\n";
	}
	else
	{
		cout << "排名\t姓名\t\t总分\n";
	}
	cout << "-----------------------------------------------------\n";

	for (int i = 0; i < vecStudent.size(); i++)
	{
		cout << i + 1 << "\t" << vecStudent[i].strName << (vecStudent[i].strName.size() > 6 ? "\t" : "\t\t");
		cout << vecStudent[i].vecExamScores[0].dTotal << "\t";
		cout << endl;
	}

	//等待
	cout << "\n按任意键返回...";
	_getch();
}

static void SortTotalRank(std::vector<Student>& vecStu, int examIndex)
{
	//算出学生的分
	for (auto&stu : vecStu)
	{
		CountTotalOfExam(stu.vecExamScores[examIndex]);
	}

	//排序
	for (int i = 0; i < vecStu.size(); i++)
	{
		for (int j = 1; j < vecStu.size(); j++)
		{
			if (vecStu[j - 1].vecExamScores[examIndex].dTotal < vecStu[j].vecExamScores[examIndex].dTotal)
			{
				std::swap(vecStu[j - 1], vecStu[j]);
			}
		}
	}
}

static int SelectExam(const Class& cla)
{
	int index;
	while (true)
	{
		std::cout << cla.unPrefix << " 班共有 " << cla.unExamAmount << " 次考试，请输入要排名的考试：\t";
		std::cin >> index;//+1 index
		std::cout << std::endl;

		if (index > cla.unExamAmount)
		{
			std::cout << "不正确的考试编号，请重新输入...\n";
		}
		else
		{
			break;
		}
	}

	index--;
	return index;
}

static unsigned int ClassInput()
{
	using namespace std;

	system("cls");

	unsigned int classPrefix;
	//输入班级号
	while (true)
	{
		cout << "------------------------------------------------\n";
		cout << "\t查看班级内总分排名\n";
		cout << "\t班级格式为：年级+班别\n";
		cout << "\t如19级的1班为：1901\n";
		cout << "------------------------------------------------\n";

		cout << "\n请输入班级号：\t";
		cin >> classPrefix;
		cout << endl;
		if (!IsClassExist(classPrefix))
		{
			cout << "------------------------------------------------\n";
			cout << "不正确的班级号，请重新输入...\n";
		}
		else
		{
			break;
		}
	}

	return classPrefix;
}

static void TotalRankInClass()
{
	using namespace std;

	//选择班级
	auto classPrefix = ClassInput();
	Class cla;
	LoadClassAttr(classPrefix, cla);

	//选择考试
	auto examIndex = SelectExam(cla);

	//加载学生
	vector<Student> vecStudents;
	LoadAllStuInClass(classPrefix, vecStudents);

	//排序
	SortTotalRank(vecStudents, examIndex);

	//打印
	cout << "【 " << classPrefix << " 班第 " << examIndex + 1 << " 次考试排名】" << endl;
	if (cla.bIsSciClass)
	{
		cout << "排名\t姓名\t\t总分\t语文\t数学\t英语\t物理\t化学\t生物\n";
	}
	else
	{
		cout << "排名\t姓名\t\t总分\t语文\t数学\t英语\t政治\t历史\t地理\n";
	}
	cout << "------------------------------------------------------------------------------\n";

	for (int i = 0; i != vecStudents.size(); i++)
	{
		cout << i + 1 << "\t" << vecStudents[i].strName << (vecStudents[i].strName.size() > 6 ? "\t" : "\t\t");
		cout << vecStudents[i].vecExamScores[examIndex].dTotal << "\t";
		for (auto score : vecStudents[i].vecExamScores[examIndex].dScore)
		{
			cout << score << "\t";
		}
		cout << endl;
	}

	//等待
	cout << "\n按任意键返回...";
	_getch();
}

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
	funcList.push_back("年级各学生总分排名(多次平均)");
	funcList.push_back("班级内总分排名");
	funcList.push_back("返回");

	while (true)
	{
		auto input = TextChooserEnter(funcList, head);
		switch (input)
		{
		case 0:
			TotalRankInGrade();
			break;
		case 1:
			TotalRankInClass();
			break;
		case 2:
			return;
			break;
		default:
			break;
		}
	}

}