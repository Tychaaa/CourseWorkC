#pragma once
#include <iostream>
#include <string>

// ��������������� ���������� �������
class Weapon;
class Magic;

using namespace std;

class Character
{
private:

    string name;      // ���
    int health;       // ��������
    int stamina;      // ������������
    int mana;         // ����� ����
    int level;        // ������� ������
    int experience;   // ���� ������
    string classType; // ����� ������
    Weapon* weapon;   // ��������� �� ������ ���������
    Magic* magic;     // ��������� �� ������ ���������

public:

    Character();

    Character(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype);

    ~Character();

    // �������
    string getName() const;
    int getHealth() const;
    int getStamina() const;
    int getMana() const;
    int getLevel() const;
    int getExperience() const;
    string getClassType() const;
    Weapon* getWeapon() const;
    Magic* getMagic() const;

    // �������
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