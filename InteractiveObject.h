#pragma once
#include <iostream>
#include <string>

using namespace std;

// ������� ����� ��� ������������� ��������
class InteractiveObject 
{
private:

    string name;             // ��� �������
    string description;      // �������� �������

public:

    // �����������
    InteractiveObject();
    // ����������� � �����������
    InteractiveObject(const string& n, const string& desc);
    // ����������
    ~InteractiveObject();

    // �������
    string getName();
    string getDescription();

    // �������
    void setName(string& n);
    void setDescription(string& desc);

    // ����������� ������� ��� ��������������
    virtual void interact() = 0;  
};