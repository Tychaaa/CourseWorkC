#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

// Класс для отображения текстовой информации
class Screen 
{
public:

    // Вывод текста
    static void displayText(const string& text);

    // Выбор вариантов
    static void displayOptions(vector<string>& options);

    // Вывод текста по буквам
    static void displayCharacterByCharacter(const string& text);

    // Вывод прямой речи NPC
    static void displayDialog(const string& name, const string& phrase);
};

