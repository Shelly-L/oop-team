//ordering.cpp
#include "take-out.h"
#include "LinkList.h"
#include <iomanip>
#include <conio.h>

order::order(int Year, int Month, int Day, double Money,double Final_money,const string Name, const string Food,const string Address,const string Feedback,const string State):year(Year),month(Month),day(Day),money(Money),final_money(Final_money),name(Name),food(Food),address(Address),feedback(Feedback),state(State)
{
}

void order::Set(int Year, int Month, int Day, double Money,const string Name, const string Food,const string Address,const string Feedback,const string State)
{
	year = Year;
	month = Month;
	day = Day;
	money = Money;
	name=Name;
	food=Food;
	address=Address;
	discount();
	feedback = Feedback;
}


void order::discount()//����ԭ��������������
{
	double m=money;
	if(money>=108)
	{ 
		m = money - 18;
		cout << "��ϲ�㣬��108��18Ԫ" << endl;
	}
	else if (money >= 88)
	{
		m = money - 14;
		cout << "��ϲ�㣬��88��14Ԫ" << endl;
	}
	else if (money >= 68)
	{
		m = money - 10;
		cout << "��ϲ�㣬��68��10Ԫ" << endl;
	}
	else if (money >= 48)
	{
		m = money - 7;
		cout << "��ϲ�㣬��48��7Ԫ" << endl;
	}
	else if (money >= 35)
	{
		m = money - 3;
		cout << "��ϲ�㣬��35��3Ԫ" << endl;
	}
	final_money = m;
}

void order:: fb ()//�Ըö��������ۣ�
{
	int flag=0;
	cout << "�Ƿ���������(��������0/��������1��" << endl;
	flag = getche()- '0';
	cout << endl;
	if(flag==0)
		feedback="��";
	else
	{
		cout<<"�������������"<<endl;
		cin>>feedback;
	}
	
}

void User::Level()
{
	int n = link.NumNodes();
	if (n > 3)
		level = "����Ի�";
	else if (n >= 2)
		level = "�м��Ի�";
	else
		level = "�����Ի�";
}

ostream & operator<<(ostream &out, const order &b)
{
	out << setfill('0');
	out << b.year << '-' << setw(2) << b.month << '-' << b.day << '\t';
	out <<b.name<<'\t'<<b.food<<'\t'<<b.address<<'\t'<<b.money<<'\t'<<b.final_money<<'\t'<<b.feedback<<' ';
	return out;
}
////////////////////////////////
User::User(const string TEL, const string Name, string Level):tel(TEL),name(Name),level(Level)
{
}

void User:: Appendorder(const order &b)
{ 
	link.Append(b);
}

void User::Deleteorder()
{
	if (link.CurNode() == NULL)
		cout << "�Ѿ�û�п����˿�Ķ�����" << endl;
	else link.DeleteCurNode();
}

void User::Show(ostream &out) const
{   
	out << "�û�������" << name << "\t�绰��" << tel <<"\t�ȼ�"<<level<<endl;
}

void User::Set(const char* TEL, const char* Name)
{
	tel = TEL;
	name = Name;
}

string User::t() const
{
	return tel;
}


User::operator string() const
{
	return tel;
}
ostream & operator<<(ostream &out, const User &u)
{
	u.Show(out);
	out << "    ����\t�̻�\t��Ʒ\t�ջ���ַ\tԭ���\t���ս��\t����" << endl;
	u.link.PutList(out);
	return out;
}
