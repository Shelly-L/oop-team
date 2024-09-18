//take_out.h
#ifndef TAKE_OUT_H
#define TAKE_OUT_H
#include "LinkList.h"
#include <iomanip>
#include<string>

class User;	// ��ǰ����

class order	// ��������
{
public:
	order(int Year=2024, int Month=9, int Day=18, double Money=0,double Final_Money=0,const string Name="LQY", const string Food="��",const string Address="��",const string Feedback="��",const string State="��");
	void Set(int Year, int Month, int Day, double Money,string Name,string Food,string Address,string Feedback,const string State);
	void discount();//����ԭ��������������
	void fb ();//�Ըö��������ۣ�
	friend ostream & operator<<(ostream &out, const order &b);//���ʱ�䣬�̻���ʳ�ԭ���۸�������۸�
	friend class User;

private:
	int year, month, day;	// ��������
	string name,food,address,feedback,state;   //�����������̻�,ʳ����ջ���ַ
	double money,final_money;		// ���ζ����Ľ��
};

class User
{
public:
	User(const string TEL="19979704156", const string Name="LQY", string Level="����");
	void Set(const char *TEL, const char *Name);
	string t() const;
	operator string() const;
	void Level();
	void Deleteorder();
	void Appendorder(const order &b); //����¶���
	void Show(ostream &out) const;  //��ʾ�û���Ϣ���˺ţ��������ȼ�����Ϊ�������м������
	friend ostream & operator<<(ostream &out, const User &u); //��ʾ������Ϣ

private:
	string tel,name,level;		// �˺š�����
	LinkList<order> link;		// ����(���û��Ķ�����¼)
};
#endif
