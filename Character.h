#pragma once
#include <iostream>
#include <string>

// Предварительное объявление классов
class Weapon;
class Magic;

using namespace std;

class Character
{
private:

    string name;      // Имя
    int health;       // Здоровье
    int stamina;      // Выносливость
    int mana;         // Запас маны
    int level;        // Уровень игрока
    int experience;   // Опыт игрока
    string classType; // Класс игрока
    Weapon* weapon;   // Указатель на оружие персонажа
    Magic* magic;     // Указатель на оружие персонажа

public:

    Character();

    Character(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype);

    ~Character();

    // Геттеры
    string getName() const;
    int getHealth() const;
    int getStamina() const;
    int getMana() const;
    int getLevel() const;
    int getExperience() const;
    string getClassType() const;
    Weapon* getWeapon() const;
    Magic* getMagic() const;

    // Сеттеры
    void setName(string newName);
    void setHealth(int newHealth);
    void setStamina(int newStamina);
    void setMana(int newMana);
    void setLevel(int newLevel);
    void setExperience(int newExp);
    void setClassType(string newClass);
    void setWeapon(Weapon* newWeapon);
    void setMagic(Magic* newMagic);

    void attack(Character& target);
    void castSpell(Character& target);
    void takeDamage(int damage);
    void decreaseStamina(int cost);
    void decreaseMana(int cost);
    void levelUp();
};