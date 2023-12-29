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
            stamina = maxStamina; // Устанавливаем значение стамины в максимум, если превысили
        }
    }
}

void Wolf::bite(Character& target) {
    int staminaCost = 15; // Стоимость выносливости для укуса

    if (getStamina() >= staminaCost) {
        int damage = 30; // Задаем урон удара когтями
        cout << this->getName() << " с силой кусает " << target.getName() << endl;
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " внезапно выдохся и начинает отступать.\n";
    }
}

void Wolf::clawAttack(Character& target) {
    int staminaCost = 20; // Стоимость выносливости для удара когтями

    if (getStamina() >= staminaCost) {
        int damage = 10; // Задаем урон удара когтями
        cout << this->getName() << " рычит и наносит жесткий удар когтями по " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " выдохся и отступает, осознавая, что не в состоянии нанести удар когтями.\n";
    }
}

void Wolf::attack(Character& target) {
    // Вызываем случайную атаку между укусом и ударом когтями
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen); // Генерируем случайное число от 1 до 4

    if (choice <= 30) {
        this->clawAttack(target);
    }
    else if (choice > 30 && choice <= 90) {
        this->bite(target);
    }
    else {
        cout << this->getName() << " промахивается и не попадает по " << target.getName() << "!\n";
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
            stamina = maxStamina; // Устанавливаем значение стамины в максимум, если превысили
        }
    }
}

void Ogre::smash(Character& target) {
    int staminaCost = 30; // Стоимость выносливости для удара

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
    int staminaCost = 50; // Стоимость выносливости для удара

    if (getStamina() >= staminaCost) {
        int damage = 30;
        cout << this->getName() << " наносит мощный удар о землю, поднимается волна, ударяя " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " слишком устал для такого мощного удара. Ему не хватает выносливости.\n";
    }
}

void Ogre::fistAttack(Character& target) {
    int staminaCost = 15; // Стоимость выносливости для удара

    if (getStamina() >= staminaCost) {
        int damage = 15;
        cout << this->getName() << " наносит удар кулаком по " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " слишком устал для удара кулаком и начинает отступать.\n";
    }
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
    else if (choice > 80 && choice <= 90) {
        this->smash(target);
    }
    else {
        cout << this->getName() << " промахивается и не попадает по " << target.getName() << "!\n";
    }
    
}


Goblin::Goblin() : Character() {}

Goblin::Goblin(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "") {
    experience = 20;
}

Goblin::~Goblin() {}

void Goblin::regenerateStamina() {
    if (stamina < maxStamina) {
        stamina += 15;
        if (stamina > maxStamina) {
            stamina = maxStamina;
        }
    }
}

void Goblin::sneakAttack(Character& target) {
    int staminaCost = 20;

    if (getStamina() >= staminaCost) {
        int damage = 20;
        cout << this->getName() << " прикрывается и наносит удар из тени по " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " слишком устал для скрытного нападения.\n";
    }
}

void Goblin::throwRock(Character& target) {
    int staminaCost = 15;

    if (getStamina() >= staminaCost) {
        int damage = 15;
        cout << this->getName() << " метает камень в " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " слишком устал для метания камня.\n";
    }
}

void Goblin::attack(Character& target) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen);

    if (choice <= 40) {
        this->sneakAttack(target);
    }
    else if (choice > 40 && choice <= 80) {
        this->throwRock(target);
    }
    else {
        cout << this->getName() << " промахивается и не попадает по " << target.getName() << "!\n";
    }
}


Skeleton::Skeleton() : Character() {}

Skeleton::Skeleton(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "") {
    experience = 30;
}

Skeleton::~Skeleton() {}

void Skeleton::regenerateStamina() {
    if (stamina < maxStamina) {
        stamina += 10; // Скелет восстанавливает меньше выносливости
        if (stamina > maxStamina) {
            stamina = maxStamina;
        }
    }
}

void Skeleton::boneStrike(Character& target) {
    int staminaCost = 20;

    if (getStamina() >= staminaCost) {
        int damage = 25;
        cout << this->getName() << " размахивает костями и ударяет " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " слишком устал для удара костями.\n";
    }
}

void Skeleton::throwBone(Character& target) {
    int staminaCost = 15;

    if (getStamina() >= staminaCost) {
        int damage = 15;
        cout << this->getName() << " бросает кость в " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " слишком устал для броска кости.\n";
    }
}

void Skeleton::attack(Character& target) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen);

    if (choice <= 40) {
        this->boneStrike(target);
    }
    else if (choice > 40 && choice <= 80) {
        this->throwBone(target);
    }
    else {
        cout << this->getName() << " промахивается и не попадает по " << target.getName() << "!\n";
    }
}


EarthElemental::EarthElemental() : Character() {}

EarthElemental::EarthElemental(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "") {
    experience = 40; // Задайте опыт для земляного элементаля
}

EarthElemental::~EarthElemental() {}

void EarthElemental::regenerateStamina() {
    if (stamina < maxStamina) {
        stamina += 10;
        if (stamina > maxStamina) {
            stamina = maxStamina;
        }
    }
}

void EarthElemental::rockThrow(Character& target) {
    int staminaCost = 25;

    if (getStamina() >= staminaCost) {
        int damage = 20;
        cout << this->getName() << " бросает огромный камень в " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " слишком устал для метания камня.\n";
    }
}

void EarthElemental::earthquake(Character& target) {
    int staminaCost = 50;

    if (getStamina() >= staminaCost) {
        int damage = 30;
        cout << this->getName() << " вызывает землетрясение, поражая " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " слишком устал для такого мощного удара. Недостаточно выносливости.\n";
    }
}

void EarthElemental::attack(Character& target) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen);

    if (choice <= 50) {
        this->rockThrow(target);
    }
    else {
        this->earthquake(target);
    }
}