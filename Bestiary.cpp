#include "Bestiary.h"

Wolf::Wolf() : Monster() {
    // Инициализация по умолчанию или специфичная для волка
}

Wolf::Wolf(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype)
    : Monster(name, health, stamina, mana, weapon, magic, classtype) {
    // Инициализация волка с заданными параметрами
}

Wolf::~Wolf() {
    // Деструктор волка, если нужно освободить какие-то ресурсы
}

void Wolf::bite(Character& target) {
    // Реализация функции укуса волка
    // ...
}

void Wolf::clawAttack(Character& target) {
    // Реализация функции удара когтями волка
    // Например:
    int damage = 10; // Задаем урон удара когтями
    cout << this->getName() << " наносит удар когтями по " << target.getName() << "!\n";
    target.takeDamage(damage);
}

void Wolf::attack(Character& target) {
    // Вызываем случайную атаку между укусом и ударом когтями
    int choice = rand() % 2; // Генерируем случайное число от 0 до 1

    if (choice == 0) {
        this->bite(target);
    }
    else {
        this->clawAttack(target);
    }
}


Ogre::Ogre() : Monster() {
    // Инициализация по умолчанию или специфичная для огра
}

Ogre::Ogre(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype)
    : Monster(name, health, stamina, mana, weapon, magic, classtype) {
    // Инициализация огра с заданными параметрами
}

Ogre::~Ogre() {
    // Деструктор огра, если нужно освободить какие-то ресурсы
}

void Ogre::smash(Character& target) {
    // Реализация функции удара "smash" огра
    // ...
}

void Ogre::groundPound(Character& target) {
    // Реализация функции атаки "groundPound" огра
    // ...
}

void Ogre::fistAttack(Character& target) {
    // Реализация функции удара кулаком огра
    // Например:
    int damage = 15; // Задаем урон удара кулаком
    cout << this->getName() << " наносит удар кулаком по " << target.getName() << "!\n";
    target.takeDamage(damage);
}

void Ogre::attack(Character& target) {
    // Вызываем случайную атаку между ударом кулаком, ударом "smash" и "groundPound"
    int choice = rand() % 3; // Генерируем случайное число от 0 до 2

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