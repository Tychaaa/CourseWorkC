#pragma once
#include <iostream>
#include <string>
#include <random>

#include "Character.h"

using namespace std;

class Wolf : public Character {
public:
    Wolf(); // Конструктор
    Wolf(string name, int health, int stamina, int mana);
    Wolf(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype);
    ~Wolf(); // Деструктор

    void regenerateStamina() override;

    void bite(Character& target); // Переопределенная функция для укуса волка
    void clawAttack(Character& target); // Новая функция для удара когтями

    void attack(Character& target) override; // Переопределенная функция для атаки
};


class Ogre : public Character {
public:
    Ogre(); // Конструктор
    Ogre(string name, int health, int stamina, int mana, Weapon* weapon);
    Ogre(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype);
    ~Ogre(); // Деструктор

    void regenerateStamina() override;

    void smash(Character& target); // Функция для удара "smash" огра
    void groundPound(Character& target); // Функция для атаки "groundPound" огра
    void fistAttack(Character& target); // Новая функция для удара кулаком

    void attack(Character& target) override; // Переопределенная функция для атаки
};


