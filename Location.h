#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "InteractiveObject.h"
#include "Screen.h"
#include "Input.h"

using namespace std;

// ����� ��� �������
class Location 
{
private:

    string name;
    string description;
    vector<InteractiveObject*> objects;

public:   

    // �����������
    Location();
    // ����������� � �����������
    Location(string& n, string& desc);
    // ����������
    ~Location();

    // �����, ���������� ��� ����� � �������
    void onEnter();

    // ��������� ����� �� ������������
    void handleUserInput(char userInput);
};