#include "Bestiary.h"

Wolf::Wolf() : Character() {}

Wolf::Wolf(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 25;
}

Wolf::~Wolf() {}

void Wolf::regenerateStamina()
{
    if (stamina < maxStamina)
    {
        stamina += 10;
        if (stamina > maxStamina)
        {
            stamina = maxStamina; // Устанавливаем значение стамины в максимум, если превысили
        }
    }
}

void Wolf::bite(Character& target)
{
    int staminaCost = 15; // Стоимость выносливости для укуса

    if (getStamina() >= staminaCost)
    {
        int damage = 30; // Задаем урон удара когтями
        Screen::displayCharacterByCharacter(name + " с силой кусает " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " внезапно выдохся и начинает отступать.\n");
    }
}

void Wolf::clawAttack(Character& target)
{
    int staminaCost = 20; // Стоимость выносливости для удара когтями

    if (getStamina() >= staminaCost)
    {
        int damage = 10; // Задаем урон удара когтями
        Screen::displayCharacterByCharacter(name + " рычит и наносит жесткий удар когтями по " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " выдохся и отступает, осознавая, что не в состоянии нанести удар когтями.\n");
    }
}

void Wolf::attack(Character& target)
{
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
        Screen::displayCharacterByCharacter(name + " промахивается и не попадает по " + target.getName() + ".\n");
    }
}


Ogre::Ogre() : Character() {}

Ogre::Ogre(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 35;
}

Ogre::~Ogre() {}

void Ogre::regenerateStamina()
{
    if (stamina < maxStamina)
    {
        stamina += 10;
        if (stamina > maxStamina)
        {
            stamina = maxStamina; // Устанавливаем значение стамины в максимум, если превысили
        }
    }
}

void Ogre::smash(Character& target)
{
    int staminaCost = 30; // Стоимость выносливости для удара

    if (getStamina() >= staminaCost)
    {
        int damage = 25;
        Screen::displayCharacterByCharacter(name + " размахивает кулаками и наносит сокрушительный удар по " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " чувствует усталость и не может совершить удар с полной силой.\n");
    }
}

void Ogre::groundPound(Character& target)
{
    int staminaCost = 50; // Стоимость выносливости для удара

    if (getStamina() >= staminaCost)
    {
        int damage = 30;
        Screen::displayCharacterByCharacter(name + " наносит мощный удар о землю, поднимается волна, ударяя " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для такого мощного удара. Ему не хватает выносливости.\n");
    }
}

void Ogre::fistAttack(Character& target)
{
    int staminaCost = 15; // Стоимость выносливости для удара

    if (getStamina() >= staminaCost)
    {
        int damage = 15;
        Screen::displayCharacterByCharacter(name + " наносит удар кулаком по " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для удара кулаком и начинает отступать.\n");
    }
}

void Ogre::attack(Character& target)
{
    // Вызываем случайную атаку между укусом и ударом когтями
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen); // Генерируем случайное число от 1 до 4

    if (choice <= 40)
    {
        this->fistAttack(target);
    }
    else if (choice > 40 && choice <= 80)
    {
        this->groundPound(target);
    }
    else if (choice > 80 && choice <= 90)
    {
        this->smash(target);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " промахивается и не попадает по " + target.getName() + ".\n");
    }
    
}


Goblin::Goblin() : Character() {}

Goblin::Goblin(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 20;
}

Goblin::~Goblin() {}

void Goblin::regenerateStamina()
{
    if (stamina < maxStamina)
    {
        stamina += 15;
        if (stamina > maxStamina)
        {
            stamina = maxStamina;
        }
    }
}

void Goblin::sneakAttack(Character& target)
{
    int staminaCost = 20;

    if (getStamina() >= staminaCost)
    {
        int damage = 20;
        Screen::displayCharacterByCharacter(name + " прикрывается и наносит удар из тени по " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для скрытного нападения.\n");
    }
}

void Goblin::throwRock(Character& target)
{
    int staminaCost = 15;

    if (getStamina() >= staminaCost)
    {
        int damage = 15;
        Screen::displayCharacterByCharacter(name + " метает камень в " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для метания камня.\n");
    }
}

void Goblin::attack(Character& target)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen);

    if (choice <= 40)
    {
        this->sneakAttack(target);
    }
    else if (choice > 40 && choice <= 80)
    {
        this->throwRock(target);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " промахивается и не попадает по " + target.getName() + ".\n");
    }
}


Skeleton::Skeleton() : Character() {}

Skeleton::Skeleton(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 30;
}

Skeleton::~Skeleton() {}

void Skeleton::regenerateStamina()
{
    if (stamina < maxStamina)
    {
        stamina += 10; // Скелет восстанавливает меньше выносливости
        if (stamina > maxStamina)
        {
            stamina = maxStamina;
        }
    }
}

void Skeleton::boneStrike(Character& target)
{
    int staminaCost = 20;

    if (getStamina() >= staminaCost)
    {
        int damage = 25;
        Screen::displayCharacterByCharacter(name + " размахивает костями и ударяет " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для удара костями.\n");
    }
}

void Skeleton::throwBone(Character& target)
{
    int staminaCost = 15;

    if (getStamina() >= staminaCost)
    {
        int damage = 15;
        Screen::displayCharacterByCharacter(name + " бросает кость в " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал, чтобы бросить кость.\n");
    }
}

void Skeleton::attack(Character& target)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen);

    if (choice <= 40)
    {
        this->boneStrike(target);
    }
    else if (choice > 40 && choice <= 80)
    {
        this->throwBone(target);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " промахивается и не попадает по " + target.getName() + ".\n");
    }
}


EarthElemental::EarthElemental() : Character() {}

EarthElemental::EarthElemental(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 40;
}

EarthElemental::~EarthElemental() {}

void EarthElemental::regenerateStamina()
{
    if (stamina < maxStamina)
    {
        stamina += 10;
        if (stamina > maxStamina)
        {
            stamina = maxStamina;
        }
    }
}

void EarthElemental::rockThrow(Character& target)
{
    int staminaCost = 25;

    if (getStamina() >= staminaCost)
    {
        int damage = 20;
        Screen::displayCharacterByCharacter(name + " бросает огромный камень в " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал, чтобы метнуть камень.\n");
    }
}

void EarthElemental::earthquake(Character& target)
{
    int staminaCost = 50;

    if (getStamina() >= staminaCost)
    {
        int damage = 30;
        Screen::displayCharacterByCharacter(name + " вызывает землетрясение, поражая " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для такого мощного удара. Недостаточно выносливости.\n");
    }
}

void EarthElemental::attack(Character& target)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen);

    if (choice <= 50)
    {
        this->rockThrow(target);
    }
    else
    {
        this->earthquake(target);
    }
    Screen::displayCharacterByCharacter(name + " промахивается и не попадает по " + target.getName() + ".\n");
}


DarkLord::DarkLord() : Character() {}

DarkLord::DarkLord(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 50;
}

DarkLord::~DarkLord() {}

void DarkLord::regenerateStamina()
{
    if (stamina < maxStamina)
    {
        stamina += 15;
        if (stamina > maxStamina)
        {
            stamina = maxStamina;
        }
    }
}

void DarkLord::blackFlash(Character& target)
{
    int staminaCost = 35;

    if (getStamina() >= staminaCost)
    {
        int damage = 20;
        Screen::displayCharacterByCharacter(name + " создает мрак, окутывающий поле битвы... Темнота пожирает свет!\n");

        Screen::displayCharacterByCharacter(name + " с кинжалом в руке проносится сквозь мрак, оставляя лишь мерцающие следы...\n");
        target.takeDamage(damage);

        Screen::displayCharacterByCharacter(name + " с криком зверя вцепился когтями, рассекая воздух...\n");
        target.takeDamage(damage);

        Screen::displayCharacterByCharacter(name + " словно зверь, бросается в атаку, укусив свою жертву...\n");
        target.takeDamage(damage);

        Screen::displayCharacterByCharacter("Мрак медленно рассеивается, возвращая видимость на поле битвы.\n");

        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для создания мрака.\n");
    }
}

void DarkLord::shadowStrike(Character& target)
{
    int staminaCost = 50;

    if (getStamina() >= staminaCost)
    {
        int damage = 40;
        Screen::displayCharacterByCharacter(name + " направляет мощный клинок из тьмы на всех врагов.\n");
        Screen::displayCharacterByCharacter(name + " с неистовством задевает своих прислужников, разрушая своё собственное княжество.\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для теневого удара.\n");
    }
}

void DarkLord::summonMinions(Character& target)
{
    int staminaCost = 45;

    if (getStamina() >= staminaCost)
    {
        int damage = 15;
        Screen::displayCharacterByCharacter(name + " призывает теневых существ, нападающих на игроков.\n");

        Screen::displayCharacterByCharacter("Существо материализуется перед игроком, его зловещий взгляд поражает цель.\n");
        target.takeDamage(damage);

        Screen::displayCharacterByCharacter("Существо нападает с мрачной яростью, его удары поражают игрока!\n");
        target.takeDamage(damage);

        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для призыва прислужников.\n");
    }
}

void DarkLord::energyAbsorption(Character& target)
{
    int staminaCost = 30;

    if (getStamina() >= staminaCost)
    {
        int healAmount = 30;
        Screen::displayCharacterByCharacter(name + " поглощает энергию из окружающей тьмы, восстанавливая своё здоровье.\n");
        health += healAmount;
        Screen::displayCharacterByCharacter(name + " обретает новую силу, восстановив " + to_string(healAmount) + " единиц здоровья.\n");
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком истощен, чтобы поглотить энергию вокруг себя.\n");
    }
}

void DarkLord::worldHeartDestruction(Character& target)
{
    int staminaCost = 60;

    if (getStamina() >= staminaCost)
    {
        int damage = 60;
        Screen::displayCharacterByCharacter(name + " направляет разрушительную атаку на фундамент мира, нанося урон игроку.\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для атаки по фундаменту мира.\n");
    }
}

void DarkLord::manaDrain(Character& target)
{
    int manaDamage = 25; // Урон по мане

    Screen::displayCharacterByCharacter(name + " воплощает тьму в атаке, высасывая энергию из " + target.getName() + ", истощая его ману.\n");
    target.setMana(target.getMana() - manaDamage);
    mana += manaDamage;
}

void DarkLord::attack(Character& target)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen);

    if (choice <= 20)
    {
        blackFlash(target);
    }
    else if (choice > 20 && choice <= 40)
    {
        shadowStrike(target);
    }
    else if (choice > 40 && choice <= 60)
    {
        summonMinions(target);
    }
    else if (choice > 60 && choice <= 80)
    {
        energyAbsorption(target);
    }
    else if(choice > 80 && choice <= 90)
    {
        worldHeartDestruction(target);
    }
    else
    {
        manaDrain(target);
    }
}