#include "MyString.h"
using namespace std;
// 默认构造函数
MyString::MyString() : str(nullptr), len(0) {}

// 带参构造函数
MyString::MyString(const char* s) {
    if (s) {
        len = std::strlen(s);
        str = new char[len + 1];
        strcpy_s(str, len + 1, s);  // 使用 strcpy_s
    }
    else {
        str = nullptr;
        len = 0;
    }
}

// 拷贝构造函数
MyString::MyString(const MyString& other) : len(other.len) {
    str = new char[len + 1];
    strcpy_s(str, len + 1, other.str);  // 使用 strcpy_s
}

// 析构函数
MyString::~MyString() {
    delete[] str;
}

// 赋值运算符重载
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] str;
        len = other.len;
        str = new char[len + 1];
        strcpy_s(str, len + 1, other.str);  // 使用 strcpy_s
    }
    return *this;
}

// 获取字符串长度
int MyString::length() const {
    return len;
}

// 返回 C 风格字符串
const char* MyString::c_str() const {
    return str;
}

// + 运算符重载
MyString MyString::operator+(const MyString& other) const {
    MyString result;
    result.len = len + other.len;
    result.str = new char[result.len + 1];
    strcpy_s(result.str, result.len + 1, str);  // 使用 strcpy_s
    strcat_s(result.str, result.len + 1, other.str);  // 使用 strcat_s
    return result;
}

// += 运算符重载
MyString& MyString::operator+=(const MyString& other) {
    len += other.len;
    char* newStr = new char[len + 1];
    strcpy_s(newStr, len + 1, str);  // 使用 strcpy_s
    strcat_s(newStr, len + 1, other.str);  // 使用 strcat_s
    delete[] str;
    str = newStr;
    return *this;
}

// == 运算符重载
bool MyString::operator==(const MyString& other) const {
    return std::strcmp(str, other.str) == 0;
}

// != 运算符重载
bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

// < 运算符重载
bool MyString::operator<(const MyString& other) const {
    return std::strcmp(str, other.str) < 0;
}

// <= 运算符重载
bool MyString::operator<=(const MyString& other) const {
    return std::strcmp(str, other.str) <= 0;
}

// > 运算符重载
bool MyString::operator>(const MyString& other) const {
    return std::strcmp(str, other.str) > 0;
}

// >= 运算符重载
bool MyString::operator>=(const MyString& other) const {
    return std::strcmp(str, other.str) >= 0;
}

// [] 运算符重载 (非 const 版本)
char& MyString::operator[](int index) {
    if (index < 0 || index >= len) {
        throw std::out_of_range("Index out of range");
    }
    return str[index];
}

// [] 运算符重载 (const 版本)
const char& MyString::operator[](int index) const {
    if (index < 0 || index >= len) {
        throw std::out_of_range("Index out of range");
    }
    return str[index];
}

// << 输出运算符重载
std::ostream& operator<<(std::ostream& os, const MyString& obj) {
    os << obj.str;
    return os;
}

// >> 输入运算符重载
std::istream& operator>>(std::istream& is, MyString& obj) {
    char temp[1000];
    is >> temp;
    obj = MyString(temp);
    return is;
}

// 增添操作：追加另一个字符串
void MyString::append(const MyString& other) {
    char* newStr = new char[len + other.len + 1];
    strcpy_s(newStr, len + 1, str);     // 复制当前字符串
    strcat_s(newStr, len + other.len + 1, other.str);  // 追加另一个字符串
    delete[] str;
    str = newStr;
    len += other.len;
}

// 增添操作：追加单个字符
void MyString::append(char ch) {
    char* newStr = new char[len + 2];   // +2 是为了加上字符和结尾的 '\0'
    strcpy_s(newStr, len + 1, str);
    newStr[len] = ch;  // 追加字符
    newStr[len + 1] = '\0';  // 结尾字符
    delete[] str;
    str = newStr;
    len++;
}

// 删除操作：删除指定位置的字符
void MyString::remove(int index) {
    if (index < 0 || index >= len) {
        throw std::out_of_range("Index out of range");
    }

    char* newStr = new char[len];  // 新字符串
    std::memcpy(newStr, str, index);  // 复制删除前的部分
    std::memcpy(newStr + index, str + index + 1, len - index);  // 复制删除后的部分
    delete[] str;
    str = newStr;
    len--;
}

// 删除操作：删除指定范围的字符
void MyString::remove(int start, int end) {
    if (start < 0 || end >= len || start > end) {
        throw std::out_of_range("Invalid range");
    }

    char* newStr = new char[len - (end - start + 1) + 1];  // 新字符串
    std::memcpy(newStr, str, start);  // 复制删除前的部分
    std::memcpy(newStr + start, str + end + 1, len - end);  // 复制删除后的部分
    delete[] str;
    str = newStr;
    len -= (end - start + 1);
}

// 修改指定索引位置的字符
void MyString::modifyCharacter(int index, char newChar) {
    if (index < 0 || index >= len) {
        throw std::out_of_range("Index out of range");
    }
    str[index] = newChar;
}

void MyString::modifyString(MyString& str) {
    char choice;

    // 不断循环直到用户选择退出
    while (true) {
        std::cout << "选择操作：\n"
            << "a - 增添字符\n"
            << "b - 增添字符串\n"
            << "c - 删除字符\n"
            << "d - 删除范围字符\n"
            << "e - 修改字符\n"
            << "q - 退出操作\n";
        std::cin >> choice;

        if (choice == 'a') {
            char ch;
            std::cout << "请输入要增添的字符: ";
            std::cin >> ch;
            str.append(ch);
            std::cout << "更新后: " << str << std::endl;

        }
        else if (choice == 'b') {
            MyString addStr;
            std::cout << "请输入要增添的字符串: ";
            std::cin >> addStr;
            str.append(addStr);
            std::cout << "更新后: " << str << std::endl;

        }
        else if (choice == 'c') {
            int index;
            std::cout << "请输入要删除的字符位置 : ";
            std::cin >> index;
            try {
                str.remove(index-1);  // 删除指定位置的字符
                std::cout << "更新后: " << str << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }

        }
        else if (choice == 'd') {
            int start, end;
            std::cout << "请输入删除的字符范围 (start end): ";
            std::cin >> start >> end;
            try {
                str.remove(start-1, end-1);  // 删除指定范围的字符
                std::cout << "更新后: " << str << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }

        }
        else if (choice == 'e') {
            int index;
            char newChar;
            std::cout << "请输入要修改的字符位置 : ";
            std::cin >> index;
            std::cout << "请输入新的字符: ";
            std::cin >> newChar;
            try {
                str.modifyCharacter(index-1, newChar);  // 修改指定位置的字符
                std::cout << "修改后的字符串: " << str << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }

        }
        else if (choice == 'q') {
            std::cout << "退出操作." << std::endl;
            break;  // 退出循环

        }
        else {
            std::cout << "无效操作! 请重新选择." << std::endl;
        }
    }
}

void MyString::compareStrings(MyString& str1, MyString& str2, MyString& str3) {
    char compareChoiceA, compareChoiceB;

    std::cout << "选择第一个字符串进行比较: 1 - str1, 2 - str2, 3 - str3: ";
    std::cin >> compareChoiceA;
    std::cout << "选择第二个字符串进行比较: 1 - str1, 2 - str2, 3 - str3: ";
    std::cin >> compareChoiceB;

    MyString* strA = nullptr;
    MyString* strB = nullptr;

    // 根据用户选择设置待比较的两个字符串
    if (compareChoiceA == '1') {
        strA = &str1;
    }
    else if (compareChoiceA == '2') {
        strA = &str2;
    }
    else if (compareChoiceA == '3') {
        strA = &str3;
    }
    else {
        std::cout << "无效选择!" << std::endl;
        return;
    }

    if (compareChoiceB == '1') {
        strB = &str1;
    }
    else if (compareChoiceB == '2') {
        strB = &str2;
    }
    else if (compareChoiceB == '3') {
        strB = &str3;
    }
    else {
        std::cout << "无效选择!" << std::endl;
        return;
    }

    // ASCII 值比较
    std::cout << "正在比较字符串 " << *strA << " 和 " << *strB << " 的 ASCII 值..." << std::endl;
    if (*strA == *strB) {
        std::cout << "两个字符串相等!" << std::endl;
    }
    else if (*strA > *strB) {
        std::cout << "字符串 " << *strA << " 的 ASCII 值大于 " << *strB << std::endl;
    }
    else {
        std::cout << "字符串 " << *strA << " 的 ASCII 值小于 " << *strB << std::endl;
    }
}

//void MyString::inputUntilNull() {
//    char temp[100];   // 临时数组用来存储用户输入的字符串  
//    int i = 0;        // 记录输入的字符数量  
//
//    char ch;
//
//    // 逐字符读取，直到遇到换行符 '\n' 或者达到最大输入限制  
//    while (std::cin.get(ch) && ch != '\n' && i < 99) {
//        temp[i++] = ch;  // 将读取的字符存入临时数组  
//    }
//
//    // 检查是否输入了 '\0'，如果是，则停止读取  
//    if (i > 0 && temp[i - 1] == '\0') {
//        i--;  // 遇到 '\0'，在有效长度上减去1  
//    }
//
//    temp[i] = '\0';  // 确保字符串结尾有 '\0'  
//
//    len = i;  // 设置字符串的实际长度  
//    str = new char[len + 1];  // 为 str 分配足够的内存  
//
//    // 使用 strcpy_s 安全地复制字符串到 str 中  
//    errno_t result = strcpy_s(str, len + 1, temp);
//
//    if (result != 0) {
//        std::cerr << "字符串复制失败!" << std::endl;
//        delete[] str;
//        str = nullptr;
//        len = 0;
//    }
//}

void MyString::inputUntilNull() {
    char temp[100];   // 临时数组用来存储用户输入的字符串
    int i = 0;        // 记录输入的字符数量

    char ch;

    // 进入一个循环，直到用户输入有效的字符串
    while (true) {
        i = 0;  // 重置字符计数器
        

        try {
            // 逐字符读取，直到遇到换行符 '\n' 或者达到最大输入限制
            while (std::cin.get(ch) && ch != '\n' && i < 99) {
                // 仅接受字母和数字，其他字符会抛出异常
                if (!isalpha(ch) && !isdigit(ch)) {
                    throw std::invalid_argument("输入无效字符，只允许字母和数字!");
                }
                temp[i++] = ch;  // 将读取的字符存入临时数组
            }

            temp[i] = '\0';  // 确保字符串结尾有 '\0'

            len = i;  // 设置字符串的实际长度

            // 如果有效字符数量为零，则提示重新输入
            if (len == 0) {
                std::cerr << "输入不能为空，请重新输入。" << std::endl;
                continue;  // 重新进入循环继续输入
            }

            // 为 str 分配足够的内存
            str = new char[len + 1];

            // 使用 strcpy_s 安全地复制字符串到 str 中
            errno_t result = strcpy_s(str, len + 1, temp);

            if (result != 0) {
                std::cerr << "字符串复制失败!" << std::endl;
                delete[] str;
                str = nullptr;
                len = 0;
                continue;  // 继续重新输入
            }

            // 如果所有条件满足，退出循环
            break;
        }
        catch (const std::invalid_argument& e) {
            // 捕获无效字符异常，输出错误信息，并提示用户重新输入
            std::cerr << e.what() << std::endl;  // 输出错误信息
            std::cerr << "请重新输入有效的字符串。" << std::endl;  // 提示用户重新输入
            // 清空输入缓冲区，准备重新输入
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}



