#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "InteractiveObject.h"
#include "Screen.h"
#include "Input.h"

using namespace std;

// Класс для локаций
class Location 
{
private:

    string name;
    string description;
    vector<InteractiveObject*> objects;

public:   

    // Конструктор
    Location();
    // Конструктор с параметрами
    Location(string& n, string& desc);
    // Деструктор
    ~Location();

    // Метод, вызываемый при входе в локацию
    void onEnter();

    // Обработка ввода от пользователя
    void handleUserInput(char userInput);
};