#pragma once
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>

#include "Character.h"

using namespace std;

class Wolf : public Character {
public:
    Wolf(); // �����������
    Wolf(string name, int health, int stamina, int mana);
    ~Wolf(); // ����������

    void regenerateStamina() override;

    void bite(Character& target); // ���������������� ������� ��� ����� �����
    void clawAttack(Character& target); // ����� ������� ��� ����� �������

    void attack(Character& target) override; // ���������������� ������� ��� �����
};


class Ogre : public Character {
public:
    Ogre(); // �����������
    Ogre(string name, int health, int stamina, int mana);
    ~Ogre(); // ����������

    void regenerateStamina() override;

    void smash(Character& target); // ������� ��� ����� "smash" ����
    void groundPound(Character& target); // ������� ��� ����� "groundPound" ����
    void fistAttack(Character& target); // ����� ������� ��� ����� �������

    void attack(Character& target) override; // ���������������� ������� ��� �����
};


class Goblin : public Character {
public:
    Goblin();
    Goblin(string name, int health, int stamina, int mana);
    ~Goblin();

    void regenerateStamina();
    void sneakAttack(Character& target);
    void throwRock(Character& target);
    void attack(Character& target);
};


class Skeleton : public Character {
public:
    Skeleton();
    Skeleton(string name, int health, int stamina, int mana);
    ~Skeleton();

    void regenerateStamina();
    void boneStrike(Character& target);
    void throwBone(Character& target);
    void attack(Character& target);
};


class EarthElemental : public Character {
public:
    EarthElemental();
    EarthElemental(string name, int health, int stamina, int mana);
    ~EarthElemental();

    void regenerateStamina() override;
    void attack(Character& target) override;

private:
    void rockThrow(Character& target);
    void earthquake(Character& target);
};

class DarkLord : public Character
{
public:
    DarkLord(); // �����������
    DarkLord(string name, int health, int stamina, int mana);
    ~DarkLord(); // ����������

    void regenerateStamina() override;

    void blackFlash(Character& target); // ׸���� �������
    void shadowStrike(Character& target); // ������� ����
    void summonMinions(Character& target); // ������ ������������
    void energyAbsorption(Character& target); // ��������� �������
    void worldHeartDestruction(Character& target); // ���������� ������ ����
    void manaDrain(Character& target);

    void attack(Character& target) override; // ���������������� ������� ��� �����
};