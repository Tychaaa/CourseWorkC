#pragma once
#include <iostream>
#include <string>
#include "Action.h"

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
    virtual ~InteractiveObject();

    // �������
    string getName();
    string getDescription();

    // �������
    void setName(string& n);
    void setDescription(string& desc);

    // ����������� ������� ��� ��������������
    virtual void interact() = 0;

    // ����������� �������, ������������ �������� ��������
    virtual vector<Action> getAvailableActions() const = 0;

    // ����������� ������� ��� ��������� ���������� ��������
    virtual void performAction(Action& action) = 0;
};