#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "InteractiveObject.h"
#include "Screen.h"
#include "Input.h"

using namespace std;

// Класс для локаций
class Location 
{
private:

    string name;                          // Название локации
    string description;                   // Описание локации
    vector<InteractiveObject*> objects;   // Список объектов для взаимодействия

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

    // Новый метод для добавления интерактивных объектов
    void addInteractiveObject(InteractiveObject* object);
};