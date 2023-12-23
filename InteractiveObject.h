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
    InteractiveObject(string& n, string& desc);
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