#include"inputInterface.h"

void inputInterface() {
	using namespace std;

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
			//todo
			break;
		case 1:
			//todo
			break;
		case 2:
			//todo
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}