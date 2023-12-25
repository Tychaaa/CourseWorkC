#pragma once
#include <iostream>
#include <string>

#include "Arsenal.h"

using namespace std;

class Weapon :
    public Arsenal
{
public:
    // Конструктор
    Weapon();
    // Конструктор с параметрами
    Weapon(string n, int dmg, int cst);
    // Деструктор
    ~Weapon();

    void use(Character& target) override;
}; 
