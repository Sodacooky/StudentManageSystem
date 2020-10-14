#include"inputInterface.h"

void addStudent();
void inputStudentScore();
void reviseScore();

using namespace std;

void inputInterface() {
	

	string head;
	head.append("------------------------------------------------\n");
	head.append("\t¼��ɼ�\n");
	head.append("\t��ʹ�÷����ѡ�񣬻س���ȷ��\n");
	head.append("------------------------------------------------\n");

	//�����б�
	vector<string> funcList;
	funcList.push_back("���ѧ��");
	funcList.push_back("Ϊѧ����ӿ��Գɼ�");
	funcList.push_back("�޸�ѧ�����Գɼ�");
	funcList.push_back("������һ���˵�");

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
	cout << "��������ѧ�������� :  ";
	cin >> stu.strName;
	cout << "��������ѧ����ѧ�� :  ";
	cin >> stu.unId;
}


void inputStudentScore(){
	system("cls");
	int number;
	Student stu;
	cout << "\n������ѧ�ţ�\t";
	cin >> number;
	bool isSciStu = IsSciClassStudent(stu.unId);
	if (IsStudentExist(number) == false)
	{
		cout << "------------------------------------------------\n";
		cout << "\t�޴��˻�ѧ�Ŵ��󣬰�������˳���ѯ..." << endl;
		cout << "------------------------------------------------\n";
		_getch();
		return;
	}
	else
	{
		string head;
		head.append("------------------------------------------------\n");
		head.append("\tΪѧ����ӿ��Գɼ�\n");
		head.append("\t��ʹ�÷����ѡ�񣬻س���ȷ��\n");
		head.append("------------------------------------------------\n");
		vector<string> funcList;
		if (isSciStu)
		{
			funcList.push_back("����");
			funcList.push_back("��ѧ");
			funcList.push_back("Ӣ��");
			funcList.push_back("����");
			funcList.push_back("��ѧ");
			funcList.push_back("����");
			funcList.push_back("����");
		}
		else
		{

			funcList.push_back("����");
			funcList.push_back("��ѧ");
			funcList.push_back("Ӣ��");
			funcList.push_back("����");
			funcList.push_back("��ʷ");
			funcList.push_back("����");
			funcList.push_back("����");
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
	cout << "\n������ѧ�ţ�\t";
	cin >> number;
	bool isSciStu = IsSciClassStudent(stu.unId);
	if (IsStudentExist(number) == false)
	{
		cout << "------------------------------------------------\n";
		cout << "\t�޴��˻�ѧ�Ŵ��󣬰�������˳���ѯ..." << endl;
		cout << "------------------------------------------------\n";
		_getch();
		return;
	}
	else
	{
		string head;
		head.append("------------------------------------------------\n");
		head.append("\t�޸�ѧ�����Գɼ�\n");
		head.append("\t��ʹ�÷����ѡ�񣬻س���ȷ��\n");
		head.append("------------------------------------------------\n");
		vector<string> funcList;
		if (isSciStu)
		{
			funcList.push_back("����");
			funcList.push_back("��ѧ");
			funcList.push_back("Ӣ��");
			funcList.push_back("����");
			funcList.push_back("��ѧ");
			funcList.push_back("����");
			funcList.push_back("����");
		}
		else
		{

			funcList.push_back("����");
			funcList.push_back("��ѧ");
			funcList.push_back("Ӣ��");
			funcList.push_back("����");
			funcList.push_back("��ʷ");
			funcList.push_back("����");
			funcList.push_back("����");
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

