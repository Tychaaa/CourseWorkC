#pragma once
#include <iostream>
#include <string>

#include "Monster.h"

using namespace std;

class Wolf : public Monster {
public:
    Wolf(); // �����������
    Wolf(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic);
    ~Wolf(); // ����������

    void bite(Character& target); // ���������������� ������� ��� ����� �����
    void clawAttack(Character& target); // ����� ������� ��� ����� �������

    void attack(Character& target) override; // ���������������� ������� ��� �����
};

class Ogre : public Monster {
public:
    Ogre(); // �����������
    Ogre(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic);
    ~Ogre(); // ����������

    void smash(Character& target); // ������� ��� ����� "smash" ����
    void groundPound(Character& target); // ������� ��� ����� "groundPound" ����
    void fistAttack(Character& target); // ����� ������� ��� ����� �������

    void attack(Character& target) override; // ���������������� ������� ��� �����
};


