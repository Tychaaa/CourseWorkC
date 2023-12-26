#pragma once

#include <iostream>
#include <string>

#include "Character.h" // Возможно, тебе понадобится доступ к классу Character для атаки монстров

using namespace std;

class Monster :
    public Character
{
public:
    Monster(); // Конструктор
    Monster(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype);
    ~Monster(); // Деструктор

    virtual void attack(Character& target); // Функция для атаки персонажа
    //virtual void bite(Character& target); // Пример атаки монстра
    // Добавь другие функции для атак монстров, например, clawAttack и т.д.
};

