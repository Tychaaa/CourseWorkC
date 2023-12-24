#pragma once
#include <iostream>
#include <string>
#include "Action.h"

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
    InteractiveObject(const string& n, const string& desc);
    // Деструктор
    virtual ~InteractiveObject();

    // Геттеры
    string getName();
    string getDescription();

    // Сеттеры
    void setName(string& n);
    void setDescription(string& desc);

    // Виртуальная функция для взаимодействия
    virtual void interact() = 0;

    // Виртуальная функция, возвращающая варианты действий
    virtual vector<Action> getAvailableActions() const = 0;

    // Виртуальная функция для обработки выбранного действия
    virtual void performAction(Action& action) = 0;
};