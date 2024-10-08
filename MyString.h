#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class MyString {
private:
    char* str;  // 字符串存储
    int len;    // 字符串长度

public:
    // 构造函数
    MyString();                      // 默认构造函数
    MyString(const char* s);         // 带参构造函数
    MyString(const MyString& other); // 拷贝构造函数
    ~MyString();                     // 析构函数

    // 赋值运算符重载
    MyString& operator=(const MyString& other);

    // 成员函数
    void inputUntilNull();  // 负责输入字符串，遇到 '\0' 停止
    int length() const;              // 获取字符串长度
    const char* c_str() const;       // 返回 C 风格字符串

    // 字符串增添操作
    void append(const MyString& other);
    void append(char ch);

    // 字符串删除操作
    void remove(int index);          // 删除指定位置的字符
    void remove(int start, int end); // 删除指定范围的字符

    // 修改指定索引位置的字符
    void modifyCharacter(int index, char newChar);


    // 运算符重载
    MyString operator+(const MyString& other) const; // + 运算符
    MyString& operator+=(const MyString& other);     // += 运算符

    bool operator==(const MyString& other) const;    // == 运算符
    bool operator!=(const MyString& other) const;    // != 运算符
    bool operator<(const MyString& other) const;     // < 运算符
    bool operator<=(const MyString& other) const;    // <= 运算符
    bool operator>(const MyString& other) const;     // > 运算符
    bool operator>=(const MyString& other) const;    // >= 运算符

    char& operator[](int index);                     // [] 运算符（非 const）
    const char& operator[](int index) const;         // [] 运算符（const）

    // 输入输出运算符重载
    friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
    friend std::istream& operator>>(std::istream& is, MyString& obj);

    // 额外功能：用户自定义的字符串修改操作
    static void modifyString(MyString& str);


    void compareStrings(MyString& str1, MyString& str2, MyString& str3); // 比较 ASCII 值
};

#endif

