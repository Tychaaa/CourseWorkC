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
    Wolf(); // Конструктор
    Wolf(string name, int health, int stamina, int mana);
    ~Wolf(); // Деструктор

    void regenerateStamina() override;

    void bite(Character& target); // Переопределенная функция для укуса волка
    void clawAttack(Character& target); // Новая функция для удара когтями

    void attack(Character& target) override; // Переопределенная функция для атаки
};


class Ogre : public Character {
public:
    Ogre(); // Конструктор
    Ogre(string name, int health, int stamina, int mana);
    ~Ogre(); // Деструктор

    void regenerateStamina() override;

    void smash(Character& target); // Функция для удара "smash" огра
    void groundPound(Character& target); // Функция для атаки "groundPound" огра
    void fistAttack(Character& target); // Новая функция для удара кулаком

    void attack(Character& target) override; // Переопределенная функция для атаки
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
    DarkLord(); // Конструктор
    DarkLord(string name, int health, int stamina, int mana);
    ~DarkLord(); // Деструктор

    void regenerateStamina() override;

    void blackFlash(Character& target); // Чёрная вспышка
    void shadowStrike(Character& target); // Теневой удар
    void summonMinions(Character& target); // Призыв прислужников
    void energyAbsorption(Character& target); // Абсорбция энергии
    void worldHeartDestruction(Character& target); // Разрушение сердец мира
    void manaDrain(Character& target);

    void attack(Character& target) override; // Переопределенная функция для атаки
};