#include "Bestiary.h"

Wolf::Wolf() : Character() {
}

Wolf::Wolf(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic)
    : Character(name, health, stamina, mana, weapon, magic) {
}

Wolf::~Wolf() {
}

void Wolf::bite(Character& target) {
    // Реализация функции удара когтями волка
    // Например:
    int damage = 15; // Задаем урон удара когтями
    cout << this->getName() << " кусает " << target.getName() << "!\n";
    target.takeDamage(damage);
    decreaseStamina(15);
}

void Wolf::clawAttack(Character& target) {
    // Реализация функции удара когтями волка
    // Например:
    int damage = 10; // Задаем урон удара когтями
    cout << this->getName() << " наносит удар когтями по " << target.getName() << "!\n";
    target.takeDamage(damage);
    decreaseStamina(20);
}

void Wolf::attack(Character& target) {
    // Вызываем случайную атаку между укусом и ударом когтями
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 4);

    int choice = dist(gen); // Генерируем случайное число от 1 до 4

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

// Реализация функции удара "smash" огра
void Ogre::smash(Character& target) {
    int damage = 25;
    cout << this->getName() << " размахивает кулаками и наносит сокрушительный удар по " << target.getName() << "!\n";
    target.takeDamage(damage);
    decreaseStamina(30);
}

// Реализация функции атаки "groundPound" огра
void Ogre::groundPound(Character& target) {
    int damage = 30;
    cout << this->getName() << " наносит мощный удар о землю, поднимается волна, ударяя " << target.getName() << "!\n";
    target.takeDamage(damage);
    decreaseStamina(50);
}

// Реализация функции удара кулаком огра
void Ogre::fistAttack(Character& target) {
    int damage = 15;
    cout << this->getName() << " наносит удар кулаком по " << target.getName() << "!\n";
    target.takeDamage(damage);
    decreaseStamina(15);
}

void Ogre::attack(Character& target) {
    // Вызываем случайную атаку между укусом и ударом когтями
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen); // Генерируем случайное число от 1 до 4

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