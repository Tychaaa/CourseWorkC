#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "InteractiveObject.h"
#include "Screen.h"

using namespace std;

// ����� ��� �������
class Location 
{
private:

    string name;                          // �������� �������
    string description;                   // �������� �������
    vector<InteractiveObject*> objects;   // ������ �������� ��� ��������������

public:   

    // �����������
    Location();
    // ����������� � ����������� 1
    Location(const string& n, const string& desc);
    // ����������� � ����������� 2
    Location(const string& n, const string& desc, const vector<InteractiveObject*>& objs);
    // ����������
    ~Location();

    // �����, ���������� ��� ����� � �������
    void onEnter();

    // ����� ����� ��� ���������� ������������� ��������
    void addInteractiveObject(InteractiveObject* object);
};