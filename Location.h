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
    // Конструктор с параметрами 1
    Location(const string& n, const string& desc);
    // Конструктор с параметрами 2
    Location(const string& n, const string& desc, const vector<InteractiveObject*>& objs);
    // Деструктор
    ~Location();

    // Метод, вызываемый при входе в локацию
    void onEnter();

    // Обработка ввода от пользователя
    void handleUserInput(char userInput);

    // Новый метод для добавления интерактивных объектов
    void addInteractiveObject(InteractiveObject* object);
};