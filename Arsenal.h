#pragma once
#include <iostream>
#include <string>

#include "Character.h"

using namespace std;

class Arsenal {
protected:
    string name;
    int damage;
    int cost; // ����� ������� ��� ������

public:
    // �����������
    Arsenal();
    // ����������� � �����������
    Arsenal(string n, int dmg, int cst);
    // ����������
    virtual ~Arsenal();

    // �������
    string getName() const;
    int getDamage() const;
    int getCost() const;

    // �������
    void setName(string n);
    void setDamage(int dmg);
    void setCost(int cst);

};

