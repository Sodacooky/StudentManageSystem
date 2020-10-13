#include"Query.h"

//
static void RenderStudentData(Student& stu, std::string& strPrintContent);

static void RenderStudentData(Student& stu, std::string& strPrintContent)
{
	using namespace std;

	bool isSciStu = IsSciClassStudent(stu.unId);

	stringstream ss;

	ss << ("\t������\t" + stu.strName + "\n");
	ss << ("\tѧ�ţ�\t" + std::to_string(stu.unId) + "\n");
	ss << ("\t��Ŀ��\t");
	ss << (isSciStu ? "���\n\n" : "�Ŀ�\n\n");

	if (isSciStu)
	{
		ss << ("���Ա��\t����\t��ѧ\tӢ��\t����\t��ѧ\t����\n");
	}
	else
	{
		ss << ("���Ա��\t����\t��ѧ\tӢ��\t����\t��ʷ\t����\n");
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

	cout << "������ѧ�ţ� ";
	cin >> number;

	if (IsStudentExist(number) == false)
	{
		cout << "�޴��˻�ѧ�Ŵ���" << endl;
		_getch();
		return;
	}//�ж����޴���
	else {
		LoadStudentData(number, stu);
		RenderStudentData(stu, stuPrintContent);
	}//���ѧ������

	vector<string> funcList;
	funcList.push_back("�޸�");
	funcList.push_back("������һ���˵�");

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