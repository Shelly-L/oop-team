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


void order::discount()//输入原本金额，输出满减金额
{
	double m=money;
	if(money>=108)
	{ 
		m = money - 18;
		cout << "恭喜你，满108减18元" << endl;
	}
	else if (money >= 88)
	{
		m = money - 14;
		cout << "恭喜你，满88减14元" << endl;
	}
	else if (money >= 68)
	{
		m = money - 10;
		cout << "恭喜你，满68减10元" << endl;
	}
	else if (money >= 48)
	{
		m = money - 7;
		cout << "恭喜你，满48减7元" << endl;
	}
	else if (money >= 35)
	{
		m = money - 3;
		cout << "恭喜你，满35减3元" << endl;
	}
	final_money = m;
}

void order:: fb ()//对该订单的评价；
{
	int flag=0;
	cout << "是否留下评价(跳过输入0/评价输入1）" << endl;
	flag = getche()- '0';
	cout << endl;
	if(flag==0)
		feedback="无";
	else
	{
		cout<<"请输入你的评价"<<endl;
		cin>>feedback;
	}
	
}

void User::Level()
{
	int n = link.NumNodes();
	if (n > 3)
		level = "资深吃货";
	else if (n >= 2)
		level = "中级吃货";
	else
		level = "初级吃货";
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
		cout << "已经没有可以退款的订单了" << endl;
	else link.DeleteCurNode();
}

void User::Show(ostream &out) const
{   
	out << "用户户名：" << name << "\t电话：" << tel <<"\t等级"<<level<<endl;
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
	out << "    日期\t商户\t商品\t收货地址\t原金额\t最终金额\t评价" << endl;
	u.link.PutList(out);
	return out;
}
