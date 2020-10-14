#include"RecordInterface.h"

using namespace std;

//添加学生
static void AddStudent();

//添加班级
static void AddClass();

//为学生添加一次成绩
static void AddScoreToStudent();

//为一个班级导入一次成绩
static void ImportScoreToClass();

//将要导入的文件读为 学号->成绩 的关联容器
static void ImportFromFile(const string&filename, map<unsigned int, ExamScore>& mapScore);

static void ImportFromFile(const string&filename, map<unsigned int, ExamScore>& mapScore)
{
	ifstream file(filename);

	while (file.peek() != EOF)
	{
		unsigned int tmpStuId;
		ExamScore tmpScore;

		file >> tmpStuId;
		for (int i = 0; i != 6; i++)
		{
			file >> tmpScore.dScore[i];
		}

		mapScore.insert(pair< unsigned int, ExamScore>(tmpStuId, tmpScore));
	}
}

static void ImportScoreToClass()
{
	system("cls");

	cout << "------------------------------------------------\n";
	cout << "\t从文件为班级批量导入一次考试成绩\n";
	cout << "\t会增加班级总考试次数属性\n";
	cout << "\t班级格式为：年级+班别，如 1901\n";
	cout << "------------------------------------------------\n";

	//确定班级
	unsigned int classPrefix;
	while (true)
	{
		cout << "输入班级：\t";
		cin >> classPrefix;
		cout << endl;

		if (IsClassExist(classPrefix))
		{
			break;
		}
		else
		{
			cout << "班级不存在，请重新输入..." << endl;
		}
	}

	//确定文件
	string filename;
	cout << "------------------------------------------------\n";
	cout << "\t从文件为班级批量导入一次考试成绩\n";
	cout << "\t文件内格式：学号 科目1 科目2 ... 科目6\n";
	cout << "\t一个学生一行\n";
	cout << "------------------------------------------------\n";
	while (true)
	{
		cout << "输入要导入的文件名(包含路径)：";
		cin >> filename;
		cout << endl;

		if (IsFileExist(filename))
		{
			break;
		}
		else
		{
			cout << "文件不存在，请重新输入..." << endl;
		}
	}

	cout << "正在处理...\n";

	//读取文件
	map<unsigned int, ExamScore> mapScore;
	ImportFromFile(filename, mapScore);

	//读取学生并修改写回
	for (auto iter = mapScore.begin(); iter != mapScore.end(); iter++)
	{
		WriteNewScoreToStudent(iter->first, iter->second);
	}

	//修改班级属性
	Class cla;
	LoadClassAttr(classPrefix, cla);
	SetClassAttr(classPrefix, cla.bIsSciClass, cla.unExamAmount + 1);

	cout << "完成，按任意键退出...\n";
	_getch();
}

static void AddScoreToStudent()
{
	system("cls");

	unsigned int stuId;
	cout << "------------------------------------------------\n";
	cout << "\t指定学号，为其添加一次考试成绩\n";
	cout << "\t这一操作不会影响班级总考试次数属性\n";
	cout << "\t学号为格式为： 年级+班级+班级内序号\n";
	cout << "\t如19级01班的01同学，则输入190101\n";
	cout << "------------------------------------------------\n";

	cout << "\n请输入学号：\t";
	cin >> stuId;
	cout << endl;

	//判断有无此人
	if (IsStudentExist(stuId) == false)
	{
		cout << "------------------------------------------------\n";
		cout << "\t无此人或学号错误，按任意键退出..." << endl;
		cout << "------------------------------------------------\n";
		_getch();
		return;
	}
	else
	{
		if (IsSciClassStudent(stuId))
		{
			cout << "请按顺序输入 语文 数学 英语 物理 化学 生物 共6门成绩(空格间隔)\n";
		}
		else
		{
			cout << "请按顺序输入 语文 数学 英语 政治 历史 地理 共6门成绩(空格间隔)\n";
		}
		ExamScore exam;
		for (int i = 0; i != 6; i++)
		{
			cin >> exam.dScore[i];
		}
		WriteNewScoreToStudent(stuId, exam);

		cout << endl << "完成，按任意键退出..." << endl;
		_getch();
		return;
	}
}

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

	CreateClass(cla.unPrefix);
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
			AddScoreToStudent();
			break;

		case 3:
			ImportScoreToClass();
			break;

		case 4:
			return;
			break;

		default:
			break;
		}
	}
}