#pragma once

#include <iostream>
#include <string>

#include "Character.h" // ��������, ���� ����������� ������ � ������ Character ��� ����� ��������

using namespace std;

class Monster :
    public Character
{
public:
    Monster(); // �����������
    Monster(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic);
    ~Monster(); // ����������

    virtual void attack(Character& target); // ������� ��� ����� ���������
    //virtual void bite(Character& target); // ������ ����� �������
    // ������ ������ ������� ��� ���� ��������, ��������, clawAttack � �.�.
};

