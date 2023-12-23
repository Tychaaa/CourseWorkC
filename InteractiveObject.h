#pragma once
#include <iostream>
#include <string>

using namespace std;

// Базовый класс для интерактивных объектов
class InteractiveObject 
{
private:

    string name;             // Имя объекта
    string description;      // Описание объекта

public:

    // Конструктор
    InteractiveObject();
    // Конструктор с параметрами
    InteractiveObject(string& n, string& desc);
    // Деструктор
    ~InteractiveObject();

    // Геттеры
    string getName();
    string getDescription();

    // Сеттеры
    void setName(string& n);
    void setDescription(string& desc);

    // Виртуальная функция для взаимодействия
    virtual void interact() = 0;  
};