#pragma once
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>

#include "Character.h"

using namespace std;

/*
*   ВОЛК (WOLF)
*/

class Wolf : public Character {
public:
    Wolf(); // Конструктор
    Wolf(string name, int health, int stamina, int mana);
    ~Wolf(); // Деструктор

    void regenerateStamina() override;

    void bite(Character& target); // Переопределенная функция для укуса волка
    void clawAttack(Character& target); // Новая функция для удара когтями

    void attack(Character& target) override; // Переопределенная функция для атаки
};

/*
*   ОГР (OGRE)
*/

class Ogre : public Character {
public:
    Ogre(); // Конструктор
    Ogre(string name, int health, int stamina, int mana, Weapon* weapon);
    ~Ogre(); // Деструктор

    void regenerateStamina() override;

    void smash(Character& target); // Функция для удара "smash" огра
    void groundPound(Character& target); // Функция для атаки "groundPound" огра
    void fistAttack(Character& target); // Новая функция для удара кулаком

    void attack(Character& target) override; // Переопределенная функция для атаки
};

/*
*   ГОБЛИН (GOBLIN)
*/

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

/*
*   СКЕЛЕТ (SKELETON)
*/

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

/*
*   ЗЕМЛЯНОЙ ЭЛЕМЕНТАЛЬ (EARTH ELEMENTAL)
*/

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

/*
*   СУККУБ (SUCCUBUS)
*/

class Succubus : public Character {
public:
    Succubus();
    Succubus(std::string name, int health, int stamina, int mana);
    ~Succubus();

    void regenerateStamina() override;
    void attack(Character& target) override;

    void seductiveGlance(Character& target);
    void demonicEmbrace(Character& target);
    void charmingKiss(Character& target);
    void seductiveWhisper(Character& target);
    void passionateTrap(Character& target);
};

/*
*   ВЕДЬМА (WITCH)
*/

class Witch : public Character {
public:
    Witch();
    Witch(std::string name, int health, int stamina, int mana);
    ~Witch();

    void regenerateStamina() override;
    void attack(Character& target) override;

    void darkCurse(Character& target);
    void hexingBlast(Character& target);
    void summonMinions(Character& target);
    void poisonousBrew(Character& target);
    void mysticalShield(Character& target);
};

/*
*   ЗАКЛИНАТЕЛЬНИЦА (ENCHANTRESS)
*/

class Enchantress : public Character {
public:
    Enchantress();
    Enchantress(std::string name, int health, int stamina, int mana);
    ~Enchantress();

    void regenerateMana() override;
    void attack(Character& target) override;

    void charmingGaze(Character& target);
    void mysticBlast(Character& target);
    void enchantWeapon(Character& target);
    void fairyBlessing(Character& target);
    void dispelMagic(Character& target);
};