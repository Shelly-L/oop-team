#include "MyString.h"
#include <iostream>
using namespace std;
int main() {
    MyString s1, s2;

    // ��ʾ�û������ַ������洢�� s1 �� s2
    std::cout << "�������ַ��� s1��ֻ������ĸ�����֣�: ";
    s1.inputUntilNull();  // �������뺯�������� '\0' ֹͣ

    std::cout << "�������ַ��� s2��ֻ������ĸ�����֣�: ";
    s2.inputUntilNull();  // �������뺯�������� '\0' ֹͣ

    // ����û�������ַ���
    std::cout << "������� s1 ��: " << s1 << std::endl;
    std::cout << "s1 �ĳ�����: " << s1.length() << std::endl;
    std::cout << "������� s2 ��: " << s2 << std::endl;
    std::cout << "s2 �ĳ�����: " << s2.length() << std::endl;



    // ���� + �� += �����
    MyString s3 = s1 + s2;
    std::cout << "s3=s1 + s2: " << s3 << std::endl;  // ��� "HelloWorld"
    std::cout << "s3 �ĳ�����: " << s3.length() << std::endl;
    //s1 += s2;
    //std::cout << "s1 += s2: " << s1 << std::endl; // ��� "HelloWorld"

    // ѡ��������ַ���
    char target;
    std::cout << "ѡ��Ҫ�޸ĵ��ַ�����a - s1, b - s2, c - s3: ";
    std::cin >> target;

    // �����û������ָ���ַ��������޸�
    if (target == 'a') {
        std::cout << "�����޸� s1..." << std::endl;
        MyString::modifyString(s1);  // �����Զ�����޸Ĳ���
        s3 = s1 + s2;
    }
    else if (target == 'b') {
        std::cout << "�����޸� s2..." << std::endl;
        MyString::modifyString(s2);  // �����Զ�����޸Ĳ���
        s3 = s1 + s2;
    }
    else if (target == 'c') {
        std::cout << "�����޸� s3..." << std::endl;
        MyString::modifyString(s3);  // �����Զ�����޸Ĳ���
    }
    else {
        std::cout << "��Ч��ѡ��" << std::endl;
    }

    // ����޸ĺ���ַ���
    std::cout << "�޸ĺ�� s1: " << s1 << std::endl;
    std::cout << "�޸ĺ�� s2: " << s2 << std::endl;
    std::cout << "�޸ĺ�� s3: " << s3 << std::endl;

    // �Ƚ��ַ����� ASCII ֵ
    s1.compareStrings(s1, s2, s3);

    // ���� == �� != �����
    if (s1 == s3) {
        std::cout << "s1 and s3 ASCII ֵ���" << std::endl;
    }
    else {
        std::cout << "s1 and s3 ASCII ֵ�����" << std::endl;
    }

    char checkChoice;
    std::cout << "ѡ��Ҫ����ַ�λ�õ��ַ�����a - s1, b - s2, c - s3: ";
    std::cin >> checkChoice;

    MyString* checkString = nullptr;  // ���ڱ���������ַ��������ָ��
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
        std::cout << "��Чѡ��" << std::endl;
        return 1;  // ��ǰ�˳�����
    }

    // �û�����Ҫ�����ַ�λ��
    int index;
    std::cout << "������Ҫ�����ַ�λ�� : ";
    std::cin >> index;

    // �쳣������ԣ������û����������λ��
    try {
        if (index >= 1 && index <= checkString->length()) {
            char ch = (*checkString)[index - 1];  // ע�������±��Ǵ� 0 ��ʼ
            std::cout << "�ַ��������� " << index << " �����ַ���: " << ch << std::endl;
        }
        else {
            throw std::out_of_range("����Խ��!");
        }
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
