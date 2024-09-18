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
	string store, food, address,feedback,state1="下单",state2="退款";
	
	double money;

	while(true)
	{
		cout << "\n请输入账号(n电话号码--注册账号，直接回车则退出)：";
		cin.getline(tel, 80);
		if(tel[0] == '\0')
			break;
		if(tel[0]=='N' || tel[0]=='n')
		{
			cout << "请输入账号名：";
			cin.getline(name, 80);
			xUser.Set(tel+1, name);
			uLink.Append(xUser);
		}
		else
			xUser.Set(tel, "");
		pU = uLink.Locate(xUser.t(), true);
		if(pU==NULL)
		{
			cout << "账号名输入错误！" << endl;
			continue;
		}
		while(true)
		{
			cout << endl;
			uLink.CurData().Show(cout);
			cout << "1 -- 点单" << endl;
			cout << "2 -- 查询" << endl;
			cout << "3 -- 退款" << endl;
			cout << "0 -- 返回" << endl;
			cout << "请选择：";
			choice = getche() - '0';
			cout << endl;
			if(choice<=0) break;
			switch(choice)
			{
			case 1: 
					cout << "请输入（年 月 日 金额 商店 食物 收货地址）: ";
					cin >> year >> month >> day >> money >> store >> food >> address;
					cin.getline(str, 80);					// 处理换行字符
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
	cout << "\n自动调用析构函数释放所有结点，返回主函数。\n" << endl;
}


//void order_test()
//{
//
//	const char* filename[] = { "LQY.txt","YBY.txt","DJ.txt","DJ.txt" };//因为“LQY.xt"是常量，所以数组也应该是常量数组
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
//			continue; // 如果文件打开失败，跳过当前迭代
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
//	//cout << "添加了" << n << "个订单";
//}
//
//
//
