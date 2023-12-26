#include "Bestiary.h"

Wolf::Wolf() : Character() {
}

Wolf::Wolf(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic)
    : Character(name, health, stamina, mana, weapon, magic) {
}

Wolf::~Wolf() {
}

void Wolf::bite(Character& target) {
    // ���������� ������� ����� ������� �����
    // ��������:
    int damage = 15; // ������ ���� ����� �������
    cout << this->getName() << " ������ " << target.getName() << "!\n";
    target.takeDamage(damage);
    decreaseStamina(15);
}

void Wolf::clawAttack(Character& target) {
    // ���������� ������� ����� ������� �����
    // ��������:
    int damage = 10; // ������ ���� ����� �������
    cout << this->getName() << " ������� ���� ������� �� " << target.getName() << "!\n";
    target.takeDamage(damage);
    decreaseStamina(20);
}

void Wolf::attack(Character& target) {
    // �������� ��������� ����� ����� ������ � ������ �������
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 4);

    int choice = dist(gen); // ���������� ��������� ����� �� 1 �� 4

    if (choice == 4) {
        this->clawAttack(target);
    }
    else {
        this->bite(target);
    }
}


Ogre::Ogre() : Character() {
}

Ogre::Ogre(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic)
    : Character(name, health, stamina, mana, weapon, magic) {
}

Ogre::~Ogre() {
}

// ���������� ������� ����� "smash" ����
void Ogre::smash(Character& target) {
    int damage = 25;
    cout << this->getName() << " ����������� �������� � ������� �������������� ���� �� " << target.getName() << "!\n";
    target.takeDamage(damage);
    decreaseStamina(30);
}

// ���������� ������� ����� "groundPound" ����
void Ogre::groundPound(Character& target) {
    int damage = 30;
    cout << this->getName() << " ������� ������ ���� � �����, ����������� �����, ������ " << target.getName() << "!\n";
    target.takeDamage(damage);
    decreaseStamina(50);
}

// ���������� ������� ����� ������� ����
void Ogre::fistAttack(Character& target) {
    int damage = 15;
    cout << this->getName() << " ������� ���� ������� �� " << target.getName() << "!\n";
    target.takeDamage(damage);
    decreaseStamina(15);
}

void Ogre::attack(Character& target) {
    // �������� ��������� ����� ����� ������ � ������ �������
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen); // ���������� ��������� ����� �� 1 �� 4

    if (choice <= 40) {
        this->fistAttack(target);
    }
    else if (choice > 40 && choice <= 80) {
        this->groundPound(target);
    }
    else {
        this->smash(target);
    }
    
}