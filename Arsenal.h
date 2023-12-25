#pragma once
#include <iostream>
#include <string>

#include "Character.h"

using namespace std;

class Arsenal {
protected:
    string name;
    int damage;
    int cost; // Общий атрибут для затрат

public:
    // Конструктор
    Arsenal();
    // Конструктор с параметрами
    Arsenal(string n, int dmg, int cst);
    // Деструктор
    virtual ~Arsenal();

    // Геттеры
    string getName() const;
    int getDamage() const;
    int getCost() const;

    // Сеттеры
    void setName(string n);
    void setDamage(int dmg);
    void setCost(int cst);

    virtual void use();

    virtual void use(Character& target) = 0; // Виртуальная функция для использования предмета

};

