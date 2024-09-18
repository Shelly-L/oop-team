//take_out.h
#ifndef TAKE_OUT_H
#define TAKE_OUT_H
#include "LinkList.h"
#include <iomanip>
#include<string>

class User;	// 提前声明

class order	// 外卖订单
{
public:
	order(int Year=2024, int Month=9, int Day=18, double Money=0,double Final_Money=0,const string Name="LQY", const string Food="无",const string Address="无",const string Feedback="无",const string State="无");
	void Set(int Year, int Month, int Day, double Money,string Name,string Food,string Address,string Feedback,const string State);
	void discount();//输入原本金额，输出满减金额
	void fb ();//对该订单的评价；
	friend ostream & operator<<(ostream &out, const order &b);//输出时间，商户，食物，原本价格和满减价格
	friend class User;

private:
	int year, month, day;	// 订单日期
	string name,food,address,feedback,state;   //订单的外卖商户,食物和收货地址
	double money,final_money;		// 本次订单的金额
};

class User
{
public:
	User(const string TEL="19979704156", const string Name="LQY", string Level="暂无");
	void Set(const char *TEL, const char *Name);
	string t() const;
	operator string() const;
	void Level();
	void Deleteorder();
	void Appendorder(const order &b); //添加新订单
	void Show(ostream &out) const;  //显示用户信息（账号，户名，等级：分为初级、中级和资深）
	friend ostream & operator<<(ostream &out, const User &u); //显示订单信息

private:
	string tel,name,level;		// 账号、户名
	LinkList<order> link;		// 链表(该用户的订单记录)
};
#endif
