#include "Bestiary.h"

Wolf::Wolf() : Character() {
}

Wolf::Wolf(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "") {
    experience = 25;
}

Wolf::~Wolf() {
}

void Wolf::regenerateStamina()
{
    if (stamina < maxStamina) {
        stamina += 10;
        if (stamina > maxStamina) {
            stamina = maxStamina; // ”станавливаем значение стамины в максимум, если превысили
        }
    }
}

void Wolf::bite(Character& target) {
    int staminaCost = 15; // —тоимость выносливости дл€ укуса

    if (getStamina() >= staminaCost) {
        int damage = 30; // «адаем урон удара когт€ми
        cout << this->getName() << " с силой кусает " << target.getName() << endl;
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " внезапно выдохс€ и начинает отступать.\n";
    }
}

void Wolf::clawAttack(Character& target) {
    int staminaCost = 20; // —тоимость выносливости дл€ удара когт€ми

    if (getStamina() >= staminaCost) {
        int damage = 10; // «адаем урон удара когт€ми
        cout << this->getName() << " рычит и наносит жесткий удар когт€ми по " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " выдохс€ и отступает, осознава€, что не в состо€нии нанести удар когт€ми.\n";
    }
}

void Wolf::attack(Character& target) {
    // ¬ызываем случайную атаку между укусом и ударом когт€ми
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen); // √енерируем случайное число от 1 до 4

    if (choice <= 30) {
        this->clawAttack(target);
    }
    else if (choice > 30 && choice <= 90) {
        this->bite(target);
    }
    else {
        cout << this->getName() << " промахиваетс€ и не попадает по " << target.getName() << "!\n";
    }
}


Ogre::Ogre() : Character() {
}

Ogre::Ogre(string name, int health, int stamina, int mana, Weapon* weapon)
    : Character(name, health, stamina, mana, weapon, nullptr, "") {
    experience = 35;
}

Ogre::~Ogre() {
}

void Ogre::regenerateStamina()
{
    if (stamina < maxStamina) {
        stamina += 10;
        if (stamina > maxStamina) {
            stamina = maxStamina; // ”станавливаем значение стамины в максимум, если превысили
        }
    }
}

void Ogre::smash(Character& target) {
    int staminaCost = 30; // —тоимость выносливости дл€ удара

    if (getStamina() >= staminaCost) {
        int damage = 25;
        cout << this->getName() << " размахивает кулаками и наносит сокрушительный удар по " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " чувствует усталость и не может совершить удар с полной силой.\n";
    }
}

void Ogre::groundPound(Character& target) {
    int staminaCost = 50; // —тоимость выносливости дл€ удара

    if (getStamina() >= staminaCost) {
        int damage = 30;
        cout << this->getName() << " наносит мощный удар о землю, поднимаетс€ волна, удар€€ " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " слишком устал дл€ такого мощного удара. ≈му не хватает выносливости.\n";
    }
}

void Ogre::fistAttack(Character& target) {
    int staminaCost = 15; // —тоимость выносливости дл€ удара

    if (getStamina() >= staminaCost) {
        int damage = 15;
        cout << this->getName() << " наносит удар кулаком по " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " слишком устал дл€ удара кулаком и начинает отступать.\n";
    }
}

void Ogre::attack(Character& target) {
    // ¬ызываем случайную атаку между укусом и ударом когт€ми
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen); // √енерируем случайное число от 1 до 4

    if (choice <= 40) {
        this->fistAttack(target);
    }
    else if (choice > 40 && choice <= 80) {
        this->groundPound(target);
    }
    else if (choice > 80 && choice <= 90) {
        this->smash(target);
    }
    else {
        cout << this->getName() << " промахиваетс€ и не попадает по " << target.getName() << "!\n";
    }
    
}