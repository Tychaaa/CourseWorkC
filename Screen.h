#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

// ����� ��� ����������� ��������� ����������
class Screen 
{
public:

    // ����� ������
    static void displayText(const string& text);

    // ����� ���������
    static void displayOptions(vector<string>& options);

    // ����� ������ �� ������
    static void displayCharacterByCharacter(const string& text);

    // ����� ������ ���� NPC
    static void displayDialog(const string& name, const string& phrase);
};

