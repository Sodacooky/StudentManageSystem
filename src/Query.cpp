#include"Query.h"

void query() {
	using namespace std;
	int number;
	
	string head;
	head.append("------------------------------------------------\n");
	head.append("\t��ѯ��Ϣ\n");
	head.append("\t��ʹ�÷����ѡ�񣬻س���ȷ��\n");
	head.append("------------------------------------------------\n");
	cout << "������ѧ�ţ� ";
	cin >>number ;
	//if () {

	//	cout << "�޴��˻�ѧ�Ŵ���";

	//}//�ж����޴���
	//else {

	//}//���ѧ������

	

	vector<string> funcList;
	funcList.push_back("�޸�");
	funcList.push_back("������һ���˵�");

	while (true)
	{
		auto input = TextChooserEnter(funcList, head);
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