#pragma once
#include <iostream>
#include <string>

#include "Arsenal.h"

using namespace std;

class Magic :
    public Arsenal
{
public:
    // Конструктор
    Magic();
    // Конструктор с параметрами
    Magic(string n, int dmg, int cst);
    // Деструктор
    ~Magic();

    void use(Character& target) override;
};

