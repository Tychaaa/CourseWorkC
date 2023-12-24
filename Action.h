#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Класс "Действие" реализующий взаимодействия с объектами
class Action 
{
public:

    // Перечисление для типов действий
    enum class ActionType {
        Talk,         // Действие "Поговорить"
        Examine,      // Действие "Осмотреть"
        Open          // Действие "Открыть"

        /*
        * TODO: добавить действия для новых объектов
        */
    };

    // Конструктор
    Action();

    // Конструктор с параметрами
    Action(ActionType type, const string& description);

    // Деструктор
    ~Action();

    // Геттер для получения типа действия
    ActionType getType() const;

    // Геттер для получения описания действия
    string getDescription() const;

private:

    ActionType type;      // Тип действия
    string description;   // Описание действия
};