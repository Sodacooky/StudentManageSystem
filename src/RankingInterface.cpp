#include "RankingInterface.h"

void RankingInterface()
{
	using namespace std;

	string head;
	head.append("------------------------------------------------\n");
	head.append("\t�鿴����\n");
	head.append("\t��ʹ�÷����ѡ�񣬻س���ȷ��\n");
	head.append("------------------------------------------------\n");

	//�����б�
	vector<string> funcList;
	funcList.push_back("�꼶�ڸ�������");
	funcList.push_back("�༶������");
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
			return;
			//break;
		default:
			break;
		}
	}

}