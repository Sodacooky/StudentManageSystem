#include"inputInterface.h"

void addStudent();//���ѧ��
static void ImportScoreFile();//��ӿ��Գɼ�


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
	funcList.push_back("���ļ�����һ�ο���");
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
	cout << "��������ѧ�������� :  ";
	cin >> stu.strName;
	cout << "��������ѧ����ѧ�� :  ";
	cin >> stu.unId;
	WriteStudent(stu.unId, stu);
	int number = stu.unId;
	if (IsStudentExist(number) == false)
	{
		cout << "------------------------------------------------\n";
		cout << "\t���ѧ��ʧ�ܣ���������˳���ѯ..." << endl;
		cout << "------------------------------------------------\n";
		_getch();
		return;
	}
	else
	{
		cout << "------------------------------------------------\n";
		cout << "\t���ѧ���ɹ�����������˳���ѯ..." << endl;
		cout << "------------------------------------------------\n";
		_getch();
		return;
	}
}

static void ImportScoreFile()
{

}