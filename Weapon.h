#pragma once
#include <iostream>
#include <string>

#include "Arsenal.h"

using namespace std;

class Weapon :
    public Arsenal
{
public:
    // �����������
    Weapon();
    // ����������� � �����������
    Weapon(string n, int dmg, int cst);
    // ����������
    ~Weapon();

    void use(Character& target) override;
}; 
