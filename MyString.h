#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class MyString {
private:
    char* str;  // �ַ����洢
    int len;    // �ַ�������

public:
    // ���캯��
    MyString();                      // Ĭ�Ϲ��캯��
    MyString(const char* s);         // ���ι��캯��
    MyString(const MyString& other); // �������캯��
    ~MyString();                     // ��������

    // ��ֵ���������
    MyString& operator=(const MyString& other);

    // ��Ա����
    void inputUntilNull();  // ���������ַ��������� '\0' ֹͣ
    int length() const;              // ��ȡ�ַ�������
    const char* c_str() const;       // ���� C ����ַ���

    // �ַ����������
    void append(const MyString& other);
    void append(char ch);

    // �ַ���ɾ������
    void remove(int index);          // ɾ��ָ��λ�õ��ַ�
    void remove(int start, int end); // ɾ��ָ����Χ���ַ�

    // �޸�ָ������λ�õ��ַ�
    void modifyCharacter(int index, char newChar);


    // ���������
    MyString operator+(const MyString& other) const; // + �����
    MyString& operator+=(const MyString& other);     // += �����

    bool operator==(const MyString& other) const;    // == �����
    bool operator!=(const MyString& other) const;    // != �����
    bool operator<(const MyString& other) const;     // < �����
    bool operator<=(const MyString& other) const;    // <= �����
    bool operator>(const MyString& other) const;     // > �����
    bool operator>=(const MyString& other) const;    // >= �����

    char& operator[](int index);                     // [] ��������� const��
    const char& operator[](int index) const;         // [] �������const��

    // ����������������
    friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
    friend std::istream& operator>>(std::istream& is, MyString& obj);

    // ���⹦�ܣ��û��Զ�����ַ����޸Ĳ���
    static void modifyString(MyString& str);


    void compareStrings(MyString& str1, MyString& str2, MyString& str3); // �Ƚ� ASCII ֵ
};

#endif

