#include "Bestiary.h"

Wolf::Wolf() : Monster() {
    // ������������� �� ��������� ��� ����������� ��� �����
}

Wolf::Wolf(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype)
    : Monster(name, health, stamina, mana, weapon, magic, classtype) {
    // ������������� ����� � ��������� �����������
}

Wolf::~Wolf() {
    // ���������� �����, ���� ����� ���������� �����-�� �������
}

void Wolf::bite(Character& target) {
    // ���������� ������� ����� �����
    // ...
}

void Wolf::clawAttack(Character& target) {
    // ���������� ������� ����� ������� �����
    // ��������:
    int damage = 10; // ������ ���� ����� �������
    cout << this->getName() << " ������� ���� ������� �� " << target.getName() << "!\n";
    target.takeDamage(damage);
}

void Wolf::attack(Character& target) {
    // �������� ��������� ����� ����� ������ � ������ �������
    int choice = rand() % 2; // ���������� ��������� ����� �� 0 �� 1

    if (choice == 0) {
        this->bite(target);
    }
    else {
        this->clawAttack(target);
    }
}


Ogre::Ogre() : Monster() {
    // ������������� �� ��������� ��� ����������� ��� ����
}

Ogre::Ogre(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype)
    : Monster(name, health, stamina, mana, weapon, magic, classtype) {
    // ������������� ���� � ��������� �����������
}

Ogre::~Ogre() {
    // ���������� ����, ���� ����� ���������� �����-�� �������
}

void Ogre::smash(Character& target) {
    // ���������� ������� ����� "smash" ����
    // ...
}

void Ogre::groundPound(Character& target) {
    // ���������� ������� ����� "groundPound" ����
    // ...
}

void Ogre::fistAttack(Character& target) {
    // ���������� ������� ����� ������� ����
    // ��������:
    int damage = 15; // ������ ���� ����� �������
    cout << this->getName() << " ������� ���� ������� �� " << target.getName() << "!\n";
    target.takeDamage(damage);
}

void Ogre::attack(Character& target) {
    // �������� ��������� ����� ����� ������ �������, ������ "smash" � "groundPound"
    int choice = rand() % 3; // ���������� ��������� ����� �� 0 �� 2

    if (choice == 0) {
        this->fistAttack(target);
    }
    else if (choice == 1) {
        this->smash(target);
    }
    else {
        this->groundPound(target);
    }
}