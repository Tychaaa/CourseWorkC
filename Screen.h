#pragma once
#include <iostream>
#include <vector>

using namespace std;

// Класс для отображения текстовой информации
class Screen 
{
public:

    static void displayText(const string& text);

    static void displayOptions(vector<string>& options);
};

