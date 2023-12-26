#pragma once
#include <iostream>
#include <string>

// ��������������� ���������� �������
class Weapon;
class Magic;

using namespace std;

class Character
{
protected:
    string name;
    int health;
    int stamina;
    int mana;
    int maxHealth;
    int maxStamina;
    int maxMana;
    int level;
    int experience;
    Weapon* weapon; // ��������� �� ������ ���������
    Magic* magic; // ��������� �� ������ ���������

public:
    Character();

    Character(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic);

    ~Character();

    // �������
    string getName() const;
    int getHealth() const;
    int getMana() const;
    int getMaxHealth() const;
    int getMaxStamina() const;
    int getMaxMana() const;
    int getLevel() const;
    int getExperience() const;
    int getStamina() const;
    Weapon* getWeapon() const;
    Magic* getMagic() const;

    // �������
    void setName(string newName);
    void setHealth(int newHealth);
    void setMana(int newMana);
    void setMaxHealth(int value);
    void setMaxStamina(int value);
    void setMaxMana(int value);
    void setLevel(int newLevel);
    void setExperience(int newExp);
    void setStamina(int newStamina);
    void setWeapon(Weapon* newWeapon);
    void setMagic(Magic* newMagic);

    virtual void attack(Character& target);
    void castSpell(Character& target);
    void takeDamage(int damage);
    void decreaseStamina(int cost);
    void decreaseMana(int cost);
    virtual void regenerateStamina();
    virtual void regenerateMana();
    void levelUp();
};
