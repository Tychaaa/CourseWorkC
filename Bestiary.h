#pragma once
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>

#include "Character.h"

using namespace std;

/*
*   ���� (WOLF)
*/

class Wolf : public Character {
public:
    Wolf(); // �����������
    Wolf(string name, int health, int stamina, int mana);
    ~Wolf(); // ����������

    int regenerateStamina() override;

    void bite(Character& target); // ���������������� ������� ��� ����� �����
    void clawAttack(Character& target); // ����� ������� ��� ����� �������

    void attack(Character& target) override; // ���������������� ������� ��� �����
};

/*
*   ��� (OGRE)
*/

class Ogre : public Character {
public:
    Ogre(); // �����������
    Ogre(string name, int health, int stamina, int mana);
    ~Ogre(); // ����������

    int regenerateStamina() override;

    void smash(Character& target); // ������� ��� ����� "smash" ����
    void groundPound(Character& target); // ������� ��� ����� "groundPound" ����
    void fistAttack(Character& target); // ���� �������

    void attack(Character& target) override; // ���������������� ������� ��� �����
};

/*
*   ������ (GOBLIN)
*/

class Goblin : public Character {
public:
    Goblin();
    Goblin(string name, int health, int stamina, int mana);
    ~Goblin();

    int regenerateStamina() override;
    void sneakAttack(Character& target);
    void throwRock(Character& target);
    void attack(Character& target) override;
};

/*
*   ������ (SKELETON)
*/

class Skeleton : public Character {
public:
    Skeleton();
    Skeleton(string name, int health, int stamina, int mana);
    ~Skeleton();

    int regenerateStamina() override;
    void boneStrike(Character& target);
    void throwBone(Character& target);
    void attack(Character& target) override;
};

/*
*   �������� ���������� (EARTH ELEMENTAL)
*/

class EarthElemental : public Character {
public:
    EarthElemental();
    EarthElemental(string name, int health, int stamina, int mana);
    ~EarthElemental();

    int regenerateStamina() override;
    int regenerateMana() override;
    void attack(Character& target) override;

    void rockThrow(Character& target);
    void earthquake(Character& target);
};

/*
*   ������ (SUCCUBUS)
*/

class Succubus : public Character {
public:
    Succubus();
    Succubus(std::string name, int health, int stamina, int mana);
    ~Succubus();

    int regenerateStamina() override;
    int regenerateMana() override;
    void attack(Character& target) override;

    void seductiveGlance(Character& target);
    void demonicEmbrace(Character& target);
    void charmingKiss(Character& target);
    void seductiveWhisper(Character& target);
    void passionateTrap(Character& target);
};

/*
*   ������ (WITCH)
*/

class Witch : public Character {
public:
    Witch();
    Witch(std::string name, int health, int stamina, int mana);
    ~Witch();

    int regenerateStamina() override;
    int regenerateMana() override;
    void attack(Character& target) override;

    void darkCurse(Character& target);
    void hexingBlast(Character& target);
    void summonMinions(Character& target);
    void poisonousBrew(Character& target);
    void mysticalShield(Character& target);
};

/*
*   ��������������� (ENCHANTRESS)
*/

class Enchantress : public Character {
public:
    Enchantress();
    Enchantress(std::string name, int health, int stamina, int mana);
    ~Enchantress();

    int regenerateStamina() override;
    int regenerateMana() override;
    void attack(Character& target) override;

    void charmingGaze(Character& target);
    void mysticBlast(Character& target);
    void enchantWeapon(Character& target);
    void fairyBlessing(Character& target);
    void dispelMagic(Character& target);
};


class DarkLord : public Character
{
public:
    DarkLord(); // �����������
    DarkLord(string name, int health, int stamina, int mana);
    ~DarkLord(); // ����������

    int regenerateStamina() override;
    int regenerateMana() override;

    void blackFlash(Character& target); // ׸���� �������
    void shadowStrike(Character& target); // ������� ����
    void summonMinions(Character& target); // ������ ������������
    void energyAbsorption(Character& target); // ��������� �������
    void worldHeartDestruction(Character& target); // ���������� ������ ����
    void manaDrain(Character& target);

    void attack(Character& target) override; // ���������������� ������� ��� �����
};