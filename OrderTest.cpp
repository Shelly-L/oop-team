// BankingTest.cpp
#include "LinkList.h"
#include "take-out.h"
#include <conio.h>

void OrderTest()
{
	LinkList<User> uLink;
	User xUser;
	Node<User> *pU;
	order xorder;
	char tel[80], name[80], str[80];
	int choice, year, month, day;
	string store, food, address,feedback,state1="�µ�",state2="�˿�";
	
	double money;

	while(true)
	{
		cout << "\n�������˺�(n�绰����--ע���˺ţ�ֱ�ӻس����˳�)��";
		cin.getline(tel, 80);
		if(tel[0] == '\0')
			break;
		if(tel[0]=='N' || tel[0]=='n')
		{
			cout << "�������˺�����";
			cin.getline(name, 80);
			xUser.Set(tel+1, name);
			uLink.Append(xUser);
		}
		else
			xUser.Set(tel, "");
		pU = uLink.Locate(xUser.t(), true);
		if(pU==NULL)
		{
			cout << "�˺����������" << endl;
			continue;
		}
		while(true)
		{
			cout << endl;
			uLink.CurData().Show(cout);
			cout << "1 -- �㵥" << endl;
			cout << "2 -- ��ѯ" << endl;
			cout << "3 -- �˿�" << endl;
			cout << "0 -- ����" << endl;
			cout << "��ѡ��";
			choice = getche() - '0';
			cout << endl;
			if(choice<=0) break;
			switch(choice)
			{
			case 1: 
					cout << "�����루�� �� �� ��� �̵� ʳ�� �ջ���ַ��: ";
					cin >> year >> month >> day >> money >> store >> food >> address;
					cin.getline(str, 80);					// �������ַ�
					xorder.Set(year, month, day, money,store,food,address,feedback,state1);
					xorder.fb();
					uLink.CurData().Appendorder(xorder);
					break;
			case 2:	
				    uLink.CurData().Level();
					cout << uLink.CurData() << endl; break;
			case 3:
				uLink.CurData().Deleteorder();
			}
		}
	}
	cout << "\n�Զ��������������ͷ����н�㣬������������\n" << endl;
}


//void order_test()
//{
//
//	const char* filename[] = { "LQY.txt","YBY.txt","DJ.txt","DJ.txt" };//��Ϊ��LQY.xt"�ǳ�������������ҲӦ���ǳ�������
//	LinkList<User> uLink;
//	User xUser;
//	order xorder;
//	char tel[80], name[80], str[80];
//
//
//
//	for (int i = 0; i < 4; i++) {
//		ifstream infile(filename[i]);
//		if (!infile.is_open()) {
//			cerr << "Failed to open file: " << filename[i] << endl;
//			continue; // ����ļ���ʧ�ܣ�������ǰ����
//		}
//
//		if (infile.getline(tel, 80, ' ') && infile.getline(name, 20, ' ')) {
//			xUser.Set(tel, name);
//			uLink.Append(xUser);
//			xUser.load(filename[i]);
//		}
//		else {
//			std::cerr << "Failed to read data from file: " << filename[i] << std::endl;
//		}
//
//		infile.close();
//	}
//	//cout << "�����" << n << "������";
//}
//
//
//
