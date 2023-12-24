#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ����� "��������" ����������� �������������� � ���������
class Action 
{
public:

    // ������������ ��� ����� ��������
    enum class ActionType {
        Talk,         // �������� "����������"
        Examine,      // �������� "���������"
        Open          // �������� "�������"

        /*
        * TODO: �������� �������� ��� ����� ��������
        */
    };

    // �����������
    Action();

    // ����������� � �����������
    Action(ActionType type, const string& description);

    // ����������
    ~Action();

    // ������ ��� ��������� ���� ��������
    ActionType getType() const;

    // ������ ��� ��������� �������� ��������
    string getDescription() const;

private:

    ActionType type;      // ��� ��������
    string description;   // �������� ��������
};