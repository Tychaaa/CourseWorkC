#pragma once
#include <iostream>
#include <string>

#include "Arsenal.h"

using namespace std;

class Magic :
    public Arsenal
{
public:
    // �����������
    Magic();
    // ����������� � �����������
    Magic(string n, int dmg, int cst);
    // ����������
    ~Magic();

    void use(Character& target) override;
};

