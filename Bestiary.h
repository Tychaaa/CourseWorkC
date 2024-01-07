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

    int regenerateStamina() override;

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
    Ogre(string name, int health, int stamina, int mana);
    ~Ogre(); // Деструктор

    int regenerateStamina() override;

    void smash(Character& target); // Функция для удара "smash" огра
    void groundPound(Character& target); // Функция для атаки "groundPound" огра
    void fistAttack(Character& target); // Удар кулаком

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

    int regenerateStamina() override;
    void sneakAttack(Character& target);
    void throwRock(Character& target);
    void attack(Character& target) override;
};

/*
*   СКЕЛЕТ (SKELETON)
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
*   ЗЕМЛЯНОЙ ЭЛЕМЕНТАЛЬ (EARTH ELEMENTAL)
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
*   СУККУБ (SUCCUBUS)
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
*   ВЕДЬМА (WITCH)
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
*   ЗАКЛИНАТЕЛЬНИЦА (ENCHANTRESS)
*/

class Enchantress : public Character {
public:
    Enchantress();
    Enchantress(std::string name, int health, int stamina, int mana);
    ~Enchantress();

    int regenerateStamina() override;
    int regenerateMana() override;
    void attack(Character& target) override;

    void mysticTouch(Character& target);
    void etherealDance(Character& target);
    void mysticBlast(Character& target);
    void whirlwindOfEnchantment(Character& target);
    void mirrorIllusion(Character& target);
};

/*
*   ДЕМОН-СТРАЖНИК (DEMON)
*/

class Demon : public Character
{
public:
    Demon(); // Конструктор
    Demon(string name, int health, int stamina, int mana);
    ~Demon(); // Деструктор

    int regenerateStamina() override;
    int regenerateMana() override;

    void hellishLash(Character& target);

    void cursedOath(Character& target);

    void infernalCurse(Character& target);

    void infernalBlade(Character& target);

    

    void attack(Character& target) override; // Переопределенная функция для атаки
};

/*
*   ВЛАДЫКА ТЬМЫ (DARK LORD)
*/

class DarkLord : public Character
{
public:
    DarkLord(); // Конструктор
    DarkLord(string name, int health, int stamina, int mana);
    ~DarkLord(); // Деструктор

    int regenerateStamina() override;
    int regenerateMana() override;

    void blackFlash(Character& target); // Чёрная вспышка
    void shadowStrike(Character& target); // Теневой удар
    void summonMinions(Character& target); // Призыв прислужников
    void energyAbsorption(Character& target); // Абсорбция энергии
    void worldHeartDestruction(Character& target); // Разрушение сердец мира
    void manaDrain(Character& target);

    void attack(Character& target) override; // Переопределенная функция для атаки
};

/*
*   ТЁМНЫЙ ЭЛЬФ (DARK ELF)
*/

class DarkElf : public Character {
public:
    DarkElf();
    DarkElf(std::string name, int health, int stamina, int mana);
    ~DarkElf();

    int regenerateStamina() override;
    int regenerateMana() override;
    void attack(Character& target) override;

    void shadowStrike(Character& target);
    void darkArrow(Character& target);
    void venomousArrow(Character& target);
    void shadowStep(Character& target);
    void bloodRitual(Character& target);
};