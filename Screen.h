#pragma once
#include <iostream>
#include <vector>

using namespace std;

// ����� ��� ����������� ��������� ����������
class Screen 
{
public:

    static void displayText(string& text);

    static void displayOptions(vector<string>& options);
};

