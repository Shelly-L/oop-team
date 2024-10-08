#include "MyString.h"
using namespace std;
// Ĭ�Ϲ��캯��
MyString::MyString() : str(nullptr), len(0) {}

// ���ι��캯��
MyString::MyString(const char* s) {
    if (s) {
        len = std::strlen(s);
        str = new char[len + 1];
        strcpy_s(str, len + 1, s);  // ʹ�� strcpy_s
    }
    else {
        str = nullptr;
        len = 0;
    }
}

// �������캯��
MyString::MyString(const MyString& other) : len(other.len) {
    str = new char[len + 1];
    strcpy_s(str, len + 1, other.str);  // ʹ�� strcpy_s
}

// ��������
MyString::~MyString() {
    delete[] str;
}

// ��ֵ���������
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] str;
        len = other.len;
        str = new char[len + 1];
        strcpy_s(str, len + 1, other.str);  // ʹ�� strcpy_s
    }
    return *this;
}

// ��ȡ�ַ�������
int MyString::length() const {
    return len;
}

// ���� C ����ַ���
const char* MyString::c_str() const {
    return str;
}

// + ���������
MyString MyString::operator+(const MyString& other) const {
    MyString result;
    result.len = len + other.len;
    result.str = new char[result.len + 1];
    strcpy_s(result.str, result.len + 1, str);  // ʹ�� strcpy_s
    strcat_s(result.str, result.len + 1, other.str);  // ʹ�� strcat_s
    return result;
}

// += ���������
MyString& MyString::operator+=(const MyString& other) {
    len += other.len;
    char* newStr = new char[len + 1];
    strcpy_s(newStr, len + 1, str);  // ʹ�� strcpy_s
    strcat_s(newStr, len + 1, other.str);  // ʹ�� strcat_s
    delete[] str;
    str = newStr;
    return *this;
}

// == ���������
bool MyString::operator==(const MyString& other) const {
    return std::strcmp(str, other.str) == 0;
}

// != ���������
bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

// < ���������
bool MyString::operator<(const MyString& other) const {
    return std::strcmp(str, other.str) < 0;
}

// <= ���������
bool MyString::operator<=(const MyString& other) const {
    return std::strcmp(str, other.str) <= 0;
}

// > ���������
bool MyString::operator>(const MyString& other) const {
    return std::strcmp(str, other.str) > 0;
}

// >= ���������
bool MyString::operator>=(const MyString& other) const {
    return std::strcmp(str, other.str) >= 0;
}

// [] ��������� (�� const �汾)
char& MyString::operator[](int index) {
    if (index < 0 || index >= len) {
        throw std::out_of_range("Index out of range");
    }
    return str[index];
}

// [] ��������� (const �汾)
const char& MyString::operator[](int index) const {
    if (index < 0 || index >= len) {
        throw std::out_of_range("Index out of range");
    }
    return str[index];
}

// << ������������
std::ostream& operator<<(std::ostream& os, const MyString& obj) {
    os << obj.str;
    return os;
}

// >> �������������
std::istream& operator>>(std::istream& is, MyString& obj) {
    char temp[1000];
    is >> temp;
    obj = MyString(temp);
    return is;
}

// ���������׷����һ���ַ���
void MyString::append(const MyString& other) {
    char* newStr = new char[len + other.len + 1];
    strcpy_s(newStr, len + 1, str);     // ���Ƶ�ǰ�ַ���
    strcat_s(newStr, len + other.len + 1, other.str);  // ׷����һ���ַ���
    delete[] str;
    str = newStr;
    len += other.len;
}

// ���������׷�ӵ����ַ�
void MyString::append(char ch) {
    char* newStr = new char[len + 2];   // +2 ��Ϊ�˼����ַ��ͽ�β�� '\0'
    strcpy_s(newStr, len + 1, str);
    newStr[len] = ch;  // ׷���ַ�
    newStr[len + 1] = '\0';  // ��β�ַ�
    delete[] str;
    str = newStr;
    len++;
}

// ɾ��������ɾ��ָ��λ�õ��ַ�
void MyString::remove(int index) {
    if (index < 0 || index >= len) {
        throw std::out_of_range("Index out of range");
    }

    char* newStr = new char[len];  // ���ַ���
    std::memcpy(newStr, str, index);  // ����ɾ��ǰ�Ĳ���
    std::memcpy(newStr + index, str + index + 1, len - index);  // ����ɾ����Ĳ���
    delete[] str;
    str = newStr;
    len--;
}

// ɾ��������ɾ��ָ����Χ���ַ�
void MyString::remove(int start, int end) {
    if (start < 0 || end >= len || start > end) {
        throw std::out_of_range("Invalid range");
    }

    char* newStr = new char[len - (end - start + 1) + 1];  // ���ַ���
    std::memcpy(newStr, str, start);  // ����ɾ��ǰ�Ĳ���
    std::memcpy(newStr + start, str + end + 1, len - end);  // ����ɾ����Ĳ���
    delete[] str;
    str = newStr;
    len -= (end - start + 1);
}

// �޸�ָ������λ�õ��ַ�
void MyString::modifyCharacter(int index, char newChar) {
    if (index < 0 || index >= len) {
        throw std::out_of_range("Index out of range");
    }
    str[index] = newChar;
}

void MyString::modifyString(MyString& str) {
    char choice;

    // ����ѭ��ֱ���û�ѡ���˳�
    while (true) {
        std::cout << "ѡ�������\n"
            << "a - �����ַ�\n"
            << "b - �����ַ���\n"
            << "c - ɾ���ַ�\n"
            << "d - ɾ����Χ�ַ�\n"
            << "e - �޸��ַ�\n"
            << "q - �˳�����\n";
        std::cin >> choice;

        if (choice == 'a') {
            char ch;
            std::cout << "������Ҫ������ַ�: ";
            std::cin >> ch;
            str.append(ch);
            std::cout << "���º�: " << str << std::endl;

        }
        else if (choice == 'b') {
            MyString addStr;
            std::cout << "������Ҫ������ַ���: ";
            std::cin >> addStr;
            str.append(addStr);
            std::cout << "���º�: " << str << std::endl;

        }
        else if (choice == 'c') {
            int index;
            std::cout << "������Ҫɾ�����ַ�λ�� : ";
            std::cin >> index;
            try {
                str.remove(index-1);  // ɾ��ָ��λ�õ��ַ�
                std::cout << "���º�: " << str << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }

        }
        else if (choice == 'd') {
            int start, end;
            std::cout << "������ɾ�����ַ���Χ (start end): ";
            std::cin >> start >> end;
            try {
                str.remove(start-1, end-1);  // ɾ��ָ����Χ���ַ�
                std::cout << "���º�: " << str << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }

        }
        else if (choice == 'e') {
            int index;
            char newChar;
            std::cout << "������Ҫ�޸ĵ��ַ�λ�� : ";
            std::cin >> index;
            std::cout << "�������µ��ַ�: ";
            std::cin >> newChar;
            try {
                str.modifyCharacter(index-1, newChar);  // �޸�ָ��λ�õ��ַ�
                std::cout << "�޸ĺ���ַ���: " << str << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }

        }
        else if (choice == 'q') {
            std::cout << "�˳�����." << std::endl;
            break;  // �˳�ѭ��

        }
        else {
            std::cout << "��Ч����! ������ѡ��." << std::endl;
        }
    }
}

void MyString::compareStrings(MyString& str1, MyString& str2, MyString& str3) {
    char compareChoiceA, compareChoiceB;

    std::cout << "ѡ���һ���ַ������бȽ�: 1 - str1, 2 - str2, 3 - str3: ";
    std::cin >> compareChoiceA;
    std::cout << "ѡ��ڶ����ַ������бȽ�: 1 - str1, 2 - str2, 3 - str3: ";
    std::cin >> compareChoiceB;

    MyString* strA = nullptr;
    MyString* strB = nullptr;

    // �����û�ѡ�����ô��Ƚϵ������ַ���
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
        std::cout << "��Чѡ��!" << std::endl;
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
        std::cout << "��Чѡ��!" << std::endl;
        return;
    }

    // ASCII ֵ�Ƚ�
    std::cout << "���ڱȽ��ַ��� " << *strA << " �� " << *strB << " �� ASCII ֵ..." << std::endl;
    if (*strA == *strB) {
        std::cout << "�����ַ������!" << std::endl;
    }
    else if (*strA > *strB) {
        std::cout << "�ַ��� " << *strA << " �� ASCII ֵ���� " << *strB << std::endl;
    }
    else {
        std::cout << "�ַ��� " << *strA << " �� ASCII ֵС�� " << *strB << std::endl;
    }
}

//void MyString::inputUntilNull() {
//    char temp[100];   // ��ʱ���������洢�û�������ַ���  
//    int i = 0;        // ��¼������ַ�����  
//
//    char ch;
//
//    // ���ַ���ȡ��ֱ���������з� '\n' ���ߴﵽ�����������  
//    while (std::cin.get(ch) && ch != '\n' && i < 99) {
//        temp[i++] = ch;  // ����ȡ���ַ�������ʱ����  
//    }
//
//    // ����Ƿ������� '\0'������ǣ���ֹͣ��ȡ  
//    if (i > 0 && temp[i - 1] == '\0') {
//        i--;  // ���� '\0'������Ч�����ϼ�ȥ1  
//    }
//
//    temp[i] = '\0';  // ȷ���ַ�����β�� '\0'  
//
//    len = i;  // �����ַ�����ʵ�ʳ���  
//    str = new char[len + 1];  // Ϊ str �����㹻���ڴ�  
//
//    // ʹ�� strcpy_s ��ȫ�ظ����ַ����� str ��  
//    errno_t result = strcpy_s(str, len + 1, temp);
//
//    if (result != 0) {
//        std::cerr << "�ַ�������ʧ��!" << std::endl;
//        delete[] str;
//        str = nullptr;
//        len = 0;
//    }
//}

void MyString::inputUntilNull() {
    char temp[100];   // ��ʱ���������洢�û�������ַ���
    int i = 0;        // ��¼������ַ�����

    char ch;

    // ����һ��ѭ����ֱ���û�������Ч���ַ���
    while (true) {
        i = 0;  // �����ַ�������
        

        try {
            // ���ַ���ȡ��ֱ���������з� '\n' ���ߴﵽ�����������
            while (std::cin.get(ch) && ch != '\n' && i < 99) {
                // ��������ĸ�����֣������ַ����׳��쳣
                if (!isalpha(ch) && !isdigit(ch)) {
                    throw std::invalid_argument("������Ч�ַ���ֻ������ĸ������!");
                }
                temp[i++] = ch;  // ����ȡ���ַ�������ʱ����
            }

            temp[i] = '\0';  // ȷ���ַ�����β�� '\0'

            len = i;  // �����ַ�����ʵ�ʳ���

            // �����Ч�ַ�����Ϊ�㣬����ʾ��������
            if (len == 0) {
                std::cerr << "���벻��Ϊ�գ����������롣" << std::endl;
                continue;  // ���½���ѭ����������
            }

            // Ϊ str �����㹻���ڴ�
            str = new char[len + 1];

            // ʹ�� strcpy_s ��ȫ�ظ����ַ����� str ��
            errno_t result = strcpy_s(str, len + 1, temp);

            if (result != 0) {
                std::cerr << "�ַ�������ʧ��!" << std::endl;
                delete[] str;
                str = nullptr;
                len = 0;
                continue;  // ������������
            }

            // ��������������㣬�˳�ѭ��
            break;
        }
        catch (const std::invalid_argument& e) {
            // ������Ч�ַ��쳣�����������Ϣ������ʾ�û���������
            std::cerr << e.what() << std::endl;  // ���������Ϣ
            std::cerr << "������������Ч���ַ�����" << std::endl;  // ��ʾ�û���������
            // ������뻺������׼����������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}



