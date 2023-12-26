#pragma once
#include <iostream>
#include <string>
#include <random>

#include "Character.h"

using namespace std;

class Wolf : public Character {
public:
    Wolf(); // �����������
    Wolf(string name, int health, int stamina, int mana);
    Wolf(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype);
    ~Wolf(); // ����������

    void regenerateStamina() override;

    void bite(Character& target); // ���������������� ������� ��� ����� �����
    void clawAttack(Character& target); // ����� ������� ��� ����� �������

    void attack(Character& target) override; // ���������������� ������� ��� �����
};


class Ogre : public Character {
public:
    Ogre(); // �����������
    Ogre(string name, int health, int stamina, int mana, Weapon* weapon);
    Ogre(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype);
    ~Ogre(); // ����������

    void regenerateStamina() override;

    void smash(Character& target); // ������� ��� ����� "smash" ����
    void groundPound(Character& target); // ������� ��� ����� "groundPound" ����
    void fistAttack(Character& target); // ����� ������� ��� ����� �������

    void attack(Character& target) override; // ���������������� ������� ��� �����
};


