#include "MyString.h"
#include <iostream>
using namespace std;
int main() {
    MyString s1, s2;

    // 提示用户输入字符串并存储到 s1 和 s2
    std::cout << "请输入字符串 s1（只允许字母和数字）: ";
    s1.inputUntilNull();  // 利用输入函数，遇到 '\0' 停止

    std::cout << "请输入字符串 s2（只允许字母和数字）: ";
    s2.inputUntilNull();  // 利用输入函数，遇到 '\0' 停止

    // 输出用户输入的字符串
    std::cout << "您输入的 s1 是: " << s1 << std::endl;
    std::cout << "s1 的长度是: " << s1.length() << std::endl;
    std::cout << "您输入的 s2 是: " << s2 << std::endl;
    std::cout << "s2 的长度是: " << s2.length() << std::endl;



    // 测试 + 和 += 运算符
    MyString s3 = s1 + s2;
    std::cout << "s3=s1 + s2: " << s3 << std::endl;  // 输出 "HelloWorld"
    std::cout << "s3 的长度是: " << s3.length() << std::endl;
    //s1 += s2;
    //std::cout << "s1 += s2: " << s1 << std::endl; // 输出 "HelloWorld"

    // 选择操作的字符串
    char target;
    std::cout << "选择要修改的字符串：a - s1, b - s2, c - s3: ";
    std::cin >> target;

    // 根据用户输入对指定字符串进行修改
    if (target == 'a') {
        std::cout << "正在修改 s1..." << std::endl;
        MyString::modifyString(s1);  // 调用自定义的修改操作
        s3 = s1 + s2;
    }
    else if (target == 'b') {
        std::cout << "正在修改 s2..." << std::endl;
        MyString::modifyString(s2);  // 调用自定义的修改操作
        s3 = s1 + s2;
    }
    else if (target == 'c') {
        std::cout << "正在修改 s3..." << std::endl;
        MyString::modifyString(s3);  // 调用自定义的修改操作
    }
    else {
        std::cout << "无效的选择！" << std::endl;
    }

    // 输出修改后的字符串
    std::cout << "修改后的 s1: " << s1 << std::endl;
    std::cout << "修改后的 s2: " << s2 << std::endl;
    std::cout << "修改后的 s3: " << s3 << std::endl;

    // 比较字符串的 ASCII 值
    s1.compareStrings(s1, s2, s3);

    // 测试 == 和 != 运算符
    if (s1 == s3) {
        std::cout << "s1 and s3 ASCII 值相等" << std::endl;
    }
    else {
        std::cout << "s1 and s3 ASCII 值不相等" << std::endl;
    }

    char checkChoice;
    std::cout << "选择要检查字符位置的字符串：a - s1, b - s2, c - s3: ";
    std::cin >> checkChoice;

    MyString* checkString = nullptr;  // 用于保存待检查的字符串对象的指针
    if (checkChoice == 'a') {
        checkString = &s1;
    }
    else if (checkChoice == 'b') {
        checkString = &s2;
    }
    else if (checkChoice == 'c') {
        checkString = &s3;
    }
    else {
        std::cout << "无效选择！" << std::endl;
        return 1;  // 提前退出程序
    }

    // 用户输入要检查的字符位置
    int index;
    std::cout << "请输入要检查的字符位置 : ";
    std::cin >> index;

    // 异常处理测试：访问用户输入的索引位置
    try {
        if (index >= 1 && index <= checkString->length()) {
            char ch = (*checkString)[index - 1];  // 注意数组下标是从 0 开始
            std::cout << "字符串中索引 " << index << " 处的字符是: " << ch << std::endl;
        }
        else {
            throw std::out_of_range("索引越界!");
        }
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
