#include "Bestiary.h"

/*
*   ВОЛК (WOLF)
*/

Wolf::Wolf() : Character() {
}

Wolf::Wolf(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 25;
}

Wolf::~Wolf() {}

int Wolf::regenerateStamina()
{
    int staminaRegenerationAmount = 10;

    if (stamina < maxStamina)
    {
        stamina += staminaRegenerationAmount;
        if (stamina > maxStamina)
        {
            stamina = maxStamina; // Устанавливаем значение стамины в максимум, если превысили
        }
    }
    return staminaRegenerationAmount;
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

/*
*   ОГР (OGRE)
*/

Ogre::Ogre() : Character() {}

Ogre::Ogre(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 35;
}

Ogre::~Ogre() {}

int Ogre::regenerateStamina()
{
    int staminaRegenerationAmount = 10;

    if (stamina < maxStamina)
    {
        stamina += staminaRegenerationAmount;
        if (stamina > maxStamina)
        {
            stamina = maxStamina; // Устанавливаем значение стамины в максимум, если превысили
        }
    }
    return staminaRegenerationAmount;
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

/*
*   ГОБЛИН (GOBLIN)
*/

Goblin::Goblin() : Character() {}

Goblin::Goblin(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 20;
}

Goblin::~Goblin() {}

int Goblin::regenerateStamina()
{
    int staminaRegenerationAmount = 15;

    if (stamina < maxStamina)
    {
        stamina += staminaRegenerationAmount;
        if (stamina > maxStamina)
        {
            stamina = maxStamina; // Устанавливаем значение стамины в максимум, если превысили
        }
    }
    return staminaRegenerationAmount;
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

/*
*   СКЕЛЕТ (SKELETON)
*/

Skeleton::Skeleton() : Character() {}

Skeleton::Skeleton(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 30;
}

Skeleton::~Skeleton() {}

int Skeleton::regenerateStamina()
{
    int staminaRegenerationAmount = 10;

    if (stamina < maxStamina)
    {
        stamina += staminaRegenerationAmount;
        if (stamina > maxStamina)
        {
            stamina = maxStamina; // Устанавливаем значение стамины в максимум, если превысили
        }
    }
    return staminaRegenerationAmount;
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

/*
*   ЗЕМЛЯНОЙ ЭЛЕМЕНТАЛЬ (EARTH ELEMENTAL)
*/

EarthElemental::EarthElemental() : Character() {}

EarthElemental::EarthElemental(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 40;
}

EarthElemental::~EarthElemental() {}

int EarthElemental::regenerateStamina()
{
    int staminaRegenerationAmount = 10;

    if (stamina < maxStamina)
    {
        stamina += staminaRegenerationAmount;
        if (stamina > maxStamina)
        {
            stamina = maxStamina; // Устанавливаем значение стамины в максимум, если превысили
        }
    }
    return staminaRegenerationAmount;
}

int EarthElemental::regenerateMana()
{
    int manaRegenerationAmount = 20;

    if (mana < maxMana)
    {
        mana += manaRegenerationAmount;
        if (mana > maxStamina)
        {
            mana = maxMana;
        }
    }

    return manaRegenerationAmount;
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
    int manaCost = 40;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
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
}

/*
*   СУККУБ (SUCCUBUS)
*/

Succubus::Succubus() : Character() {}

Succubus::Succubus(std::string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "") 
{
    experience = 70;
}

Succubus::~Succubus() {}

int Succubus::regenerateStamina()
{
    int staminaRegenerationAmount = 15;

    if (stamina < maxStamina)
    {
        stamina += staminaRegenerationAmount;
        if (stamina > maxStamina)
        {
            stamina = maxStamina;
        }
    }
    return staminaRegenerationAmount;
}

int Succubus::regenerateMana()
{
    int manaRegenerationAmount = 15;

    if (mana < maxMana)
    {
        mana += manaRegenerationAmount;
        if (mana > maxStamina)
        {
            mana = maxMana;
        }
    }

    return manaRegenerationAmount;
}

void Succubus::attack(Character& target)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen);

    if (choice <= 25) {
        this->seductiveGlance(target);
    }
    else if (choice > 25 && choice <= 50) {
        this->demonicEmbrace(target);
    }
    else if (choice > 50 && choice <= 75) {
        this->charmingKiss(target);
    }
    else if (choice > 75 && choice <= 90) {
        this->seductiveWhisper(target);
    }
    else {
        this->passionateTrap(target);
    }
}

void Succubus::seductiveGlance(Character& target)
{
    int staminaCost = 15;

    if (getStamina() >= staminaCost)
    {
        int damage = 20;
        Screen::displayCharacterByCharacter(getName() + " очаровывает своим взглядом " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком устала для очарования взглядом.\n");
    }
}

void Succubus::demonicEmbrace(Character& target)
{
    int staminaCost = 25;

    if (getStamina() >= staminaCost)
    {
        int damage = 30;
        Screen::displayCharacterByCharacter(getName() + " обнимает " + target.getName() + " в демоническом порыве!\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком устала для демонического объятия.\n");
    }
}

void Succubus::charmingKiss(Character& target)
{
    int manaCost = 15;

    if (getMana() >= manaCost)
    {
        int damage = 20;
        Screen::displayCharacterByCharacter(getName() + " наносит очаровывающий поцелуй " + target.getName() + "!\n");
        Screen::displayCharacterByCharacter(target.getName() + " ослаблен от чар.\n");
        target.takeDamage(damage);
        target.decreaseStamina(manaCost / 2);

        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурена для очаровывающего поцелуя.\n");
    }
}

void Succubus::seductiveWhisper(Character& target)
{
    int staminaCost = 20;

    if (getStamina() >= staminaCost)
    {
        int damage = 25;
        Screen::displayCharacterByCharacter(getName() + " шепчет завораживающие слова " + target.getName() + "!\n");
        target.takeDamage(damage);
        Screen::displayCharacterByCharacter(getName() + " восстанавливает +" + to_string(damage / 2) + " здоровья от мучений противника.\n");
        health += damage / 2;
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком устала для завораживающего шепота.\n");
    }
}

void Succubus::passionateTrap(Character& target)
{
    int manaCost = 30;

    if (getMana() >= manaCost)
    {
        int damage = 40;
        Screen::displayCharacterByCharacter(getName() + " создает ловушку страсти вокруг " + target.getName() + "!\n");
        Screen::displayCharacterByCharacter(target.getName() + " погружается в вихрь страстных эмоций и получает урон.\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурена для создания ловушки страсти.\n");
    }
}

/*
*   ВЕДЬМА (WITCH)
*/

Witch::Witch() : Character() {}

Witch::Witch(std::string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 60;
}

Witch::~Witch() {}

int Witch::regenerateStamina()
{
    int staminaRegenerationAmount = 15;

    if (stamina < maxStamina)
    {
        stamina += staminaRegenerationAmount;
        if (stamina > maxStamina)
        {
            stamina = maxStamina;
        }
    }
    return staminaRegenerationAmount;
}

int Witch::regenerateMana()
{
    int manaRegenerationAmount = 15;

    if (mana < maxMana)
    {
        mana += manaRegenerationAmount;
        if (mana > maxStamina)
        {
            mana = maxMana;
        }
    }

    return manaRegenerationAmount;
}

void Witch::attack(Character& target)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen);

    if (choice <= 30) {
        this->darkCurse(target);
    }
    else if (choice > 30 && choice <= 50) {
        this->hexingBlast(target);
    }
    else if (choice > 50 && choice <= 70) {
        this->summonMinions(target);
    }
    else if (choice > 70 && choice <= 90) {
        this->poisonousBrew(target);
    }
    else {
        this->mysticalShield(target);
    }
}

void Witch::darkCurse(Character& target)
{
    int manaCost = 15;

    if (getMana() >= manaCost)
    {
        int damage = 20;
        Screen::displayCharacterByCharacter(getName() + " накладывает темное проклятие на " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурена для наложения темного проклятия.\n");
    }
}

void Witch::hexingBlast(Character& target)
{
    int staminaCost = 20;

    if (getStamina() >= staminaCost)
    {
        int damage = 25;
        Screen::displayCharacterByCharacter(getName() + " выпускает волшебный сгусток энергии по " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком устала для магического взрыва.\n");
    }
}

void Witch::summonMinions(Character& target)
{
    int manaCost = 25;

    if (getMana() >= manaCost)
    {
        int damage = 30;
        Screen::displayCharacterByCharacter(getName() + " призывает миньонов для атаки " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурена для призыва миньонов.\n");
    }
}

void Witch::poisonousBrew(Character& target)
{
    int staminaCost = 20;

    if (getStamina() >= staminaCost)
    {
        int damage = 25;
        Screen::displayCharacterByCharacter(getName() + " бросает ядовитое зелье в сторону " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком устала для броска ядовитого зелья.\n");
    }
}

void Witch::mysticalShield(Character& target)
{
    int manaCost = 15;

    if (getMana() >= manaCost)
    {
        Screen::displayCharacterByCharacter(getName() + " создает мистический щит (+" + to_string(manaCost) + " hp), защищаясь от атак " + target.getName() + "!\n");
        health += manaCost;
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурена для создания мистического щита.\n");
    }
}

/*
*   ЗАКЛИНАТЕЛЬНИЦА (ENCHANTRESS)
*/

Enchantress::Enchantress() : Character() {}

Enchantress::Enchantress(std::string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 80;
}

Enchantress::~Enchantress() {}

int Enchantress::regenerateStamina()
{
    int staminaRegenerationAmount = 15;

    if (stamina < maxStamina)
    {
        stamina += staminaRegenerationAmount;
        if (stamina > maxStamina)
        {
            stamina = maxStamina;
        }
    }
    return staminaRegenerationAmount;
}

int Enchantress::regenerateMana()
{
    int manaRegenerationAmount = 15;

    if (mana < maxMana)
    {
        mana += manaRegenerationAmount;
        if (mana > maxStamina)
        {
            mana = maxMana;
        }
    }

    return manaRegenerationAmount;
}

void Enchantress::attack(Character& target)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen);

    if (choice <= 25) {
        this->mysticTouch(target);
    }
    else if (choice > 25 && choice <= 50) {
        this->etherealDance(target);
    }
    else if (choice > 50 && choice <= 75) {
        this->mysticBlast(target);
    }
    else if (choice > 75 && choice <= 90) {
        this->whirlwindOfEnchantment(target);
    }
    else {
        this->mirrorIllusion(target);
    }
}

void Enchantress::mysticTouch(Character& target)
{
    int staminaCost = 20;

    if (getStamina() >= staminaCost)
    {
        int damage = 25;
        Screen::displayCharacterByCharacter(getName() + " прикасается к " + target.getName() + " мистическим прикосновением!\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком устала для мистического прикосновения.\n");
    }
}

void Enchantress::etherealDance(Character& target)
{
    int manaCost = 25;

    if (getMana() >= manaCost)
    {
        int damage = 30;
        Screen::displayCharacterByCharacter(getName() + " исполняет эфирный танец перед " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурена для эфирного танца.\n");
    }
}

void Enchantress::mysticBlast(Character& target)
{
    int manaCost = 25;

    if (getMana() >= manaCost)
    {
        int damage = 30;
        Screen::displayCharacterByCharacter(getName() + " выпускает мистический взрыв по " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурена для мистического взрыва.\n");
    }
}

void Enchantress::whirlwindOfEnchantment(Character& target)
{
    int manaCost = 35;

    if (getMana() >= manaCost)
    {
        int damage = 40;
        Screen::displayCharacterByCharacter(getName() + " создает вихрь заклинаний вокруг " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурена для создания вихря заклинаний.\n");
    }
}

void Enchantress::mirrorIllusion(Character& target)
{
    int manaCost = 30;

    if (getMana() >= manaCost)
    {
        int damage = 35;
        Screen::displayCharacterByCharacter(getName() + " создает зеркальную иллюзию, которая атакует " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурена для создания зеркальной иллюзии.\n");
    }
}
}

/*
*   Демон стражник (Demon)
*/

Demon::Demon() : Character() {}

Demon::Demon(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 200;
}

Demon::~Demon() {}

int Demon::regenerateStamina()
{
    int staminaRegenerationAmount = 15;

    if (stamina < maxStamina)
    {
        stamina += staminaRegenerationAmount;
        if (stamina > maxStamina)
        {
            stamina = maxStamina; // Устанавливаем значение стамины в максимум, если превысили
        }
    }
    return staminaRegenerationAmount;
}

int Demon::regenerateMana()
{
    int manaRegenerationAmount = 15;

    if (mana < maxMana)
    {
        mana += manaRegenerationAmount;
        if (mana > maxStamina)
        {
            mana = maxMana;
        }
    }

    return manaRegenerationAmount;
}

void Demon::hellishLash(Character& target)
{
    int staminaCost = 20;
    int manaCost = 20;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 25;
        Screen::displayCharacterByCharacter(name + " с демоническим ревом вызывает пламенный кнут из бездны, который охватывает " + target.getName() + " огненным ударом.\n");
        target.takeDamage(damage);
        Screen::displayCharacterByCharacter("Пламя оставляет горящий след на земле, испуская дурманящий дым.\n");

        decreaseStamina(staminaCost);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для вызова пламенного кнута.\n");
    }
}

void Demon::cursedOath(Character& target)
{
    int staminaCost = 30;
    int manaCost = 10;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 15;
        int staminaDamage = 10;
        Screen::displayCharacterByCharacter("Демон-стражник произносит древние мистические слова, наложенные на оружие, и наносит проклятый удар по " + target.getName() + ".\n");
        target.takeDamage(damage);
        Screen::displayCharacterByCharacter("Удар оставляет темное пятно на доспехах " + target.getName() + ", вызывая временную слабость.\n");
        target.setStamina(target.getStamina() - staminaDamage);

        decreaseStamina(staminaCost);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для проклятого обета.\n");
    }
}

void Demon::infernalCurse(Character& target)
{
    int manaCost = 40;

    if (getMana() >= manaCost)
    {
        int staminaDamage = 50;
        Screen::displayCharacterByCharacter("Демон-стражник бросает адское проклятие на " + target.getName() + ", погружая его в мир адской муки.\n");
        Screen::displayCharacterByCharacter("Проклятие оставляет " + target.getName() + " в изнурительных страданиях, ослабляя его силы.\n");
        target.setStamina(target.getStamina() - staminaDamage);

        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком истощен для проклятия.\n");
    }
}

void Demon::infernalBlade(Character& target)
{
    int staminaCost = 30;
    int manaCost = 30;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 40;
        Screen::displayCharacterByCharacter("Демон-стражник создает клинок из тьмы и огня, направляя его в сторону " + target.getName() + ".\n");
        target.takeDamage(damage);

        decreaseStamina(staminaCost);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для создания клинка.\n");
    }
}

void Demon::attack(Character& target)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen);

    if (choice <= 25)
    {
        hellishLash(target);
    }
    else if (choice > 25 && choice <= 50)
    {
        cursedOath(target);
    }
    else if (choice > 50 && choice <= 75)
    {
        infernalCurse(target);
    }
    else if (choice > 75 && choice <= 100)
    {
        infernalBlade(target);
    }
}

/*
*   ВЛАДЫКА ТЬМЫ (DARK LORD)
*/

DarkLord::DarkLord() : Character() {}

DarkLord::DarkLord(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 200;
}

DarkLord::~DarkLord() {}

int DarkLord::regenerateStamina()
{
    int staminaRegenerationAmount = 20;

    if (stamina < maxStamina)
    {
        stamina += staminaRegenerationAmount;
        if (stamina > maxStamina)
        {
            stamina = maxStamina;
        }
    }
    return staminaRegenerationAmount;
}

int DarkLord::regenerateMana()
{
    int manaRegenerationAmount = 20;

    if (mana < maxMana)
    {
        mana += manaRegenerationAmount;
        if (mana > maxStamina)
        {
            mana = maxMana;
        }
    }
    
    return manaRegenerationAmount;
}

void DarkLord::blackFlash(Character& target)
{
    int staminaCost = 30;
    int manaCost = 20;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 20;
        Screen::displayCharacterByCharacter(name + " создает мрак, окутывающий поле битвы... Темнота пожирает свет!\n");

        Screen::displayCharacterByCharacter(name + " с кинжалом в руке проносится сквозь мрак, оставляя лишь мерцающие следы...\n");
        target.takeDamage(damage);

        Screen::displayCharacterByCharacter(name + " с криком зверя вцепился когтями, рассекая воздух...\n");
        target.takeDamage(damage);

        Screen::displayCharacterByCharacter(name + " словно зверь, бросается в атаку, нанося свирепые раны...\n");
        target.takeDamage(damage);

        Screen::displayCharacterByCharacter("Мрак медленно рассеивается, возвращая видимость на поле битвы.\n");

        decreaseStamina(staminaCost);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для создания мрака.\n");
    }
}

void DarkLord::shadowStrike(Character& target)
{
    int staminaCost = 50;
    int manaCost = 40;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 40;
        Screen::displayCharacterByCharacter(name + " направляет мощный клинок из тьмы на " + target.getName() + ".\n");
        Screen::displayCharacterByCharacter(name + " с неистовством задевает своих прислужников, разрушая своё собственное княжество.\n");
        target.takeDamage(damage);

        decreaseStamina(staminaCost);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для теневого удара.\n");
    }
}

void DarkLord::summonMinions(Character& target)
{
    int manaCost = 35;

    if (getMana() >= manaCost)
    {
        int damage = 15;
        Screen::displayCharacterByCharacter(name + " призывает теневых существ, нападающих на " + target.getName() + ".\n");

        Screen::displayCharacterByCharacter("Существо материализуется перед " + target.getName() + ", его зловещий взгляд поражает цель.\n");
        target.takeDamage(damage);

        Screen::displayCharacterByCharacter("Существо нападает с мрачной яростью, его удары поражают " + target.getName() + "!\n");
        target.takeDamage(damage);

        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком устал для призыва прислужников.\n");
    }
}

void DarkLord::energyAbsorption(Character& target)
{
    int manaCost = 40;

    if (getMana() >= manaCost)
    {
        int healAmount = 30;
        Screen::displayCharacterByCharacter(name + " поглощает энергию из окружающей тьмы, восстанавливая своё здоровье.\n");
        health += healAmount;
        Screen::displayCharacterByCharacter(name + " обретает новую силу, восстановив " + to_string(healAmount) + " единиц здоровья.\n");
        
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " слишком истощен, чтобы поглотить энергию вокруг себя.\n");
    }
}

void DarkLord::worldHeartDestruction(Character& target)
{
    int staminaCost = 60;
    int manaCost = 35;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 60;
        Screen::displayCharacterByCharacter(name + " направляет разрушительную атаку на фундамент мира, нанося урон " + target.getName() + ".\n");
        target.takeDamage(damage);

        decreaseStamina(staminaCost);
        decreaseMana(manaCost);
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

/*
*   ТЁМНЫЙ ЭЛЬФ (DARK ELF)
*/

DarkElf::DarkElf() : Character() {}

DarkElf::DarkElf(std::string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "") 
{
    experience = 50;
}

DarkElf::~DarkElf() {}

int DarkElf::regenerateStamina()
{
    int staminaRegenerationAmount = 25;

    if (stamina < maxStamina)
    {
        stamina += staminaRegenerationAmount;
        if (stamina > maxStamina)
        {
            stamina = maxStamina;
        }
    }
    return staminaRegenerationAmount;
}

int DarkElf::regenerateMana()
{
    int manaRegenerationAmount = 20;

    if (mana < maxMana)
    {
        mana += manaRegenerationAmount;
        if (mana > maxStamina)
        {
            mana = maxMana;
        }
    }

    return manaRegenerationAmount;
}

void DarkElf::attack(Character& target)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen);

    if (choice <= 20) {
        this->shadowStrike(target);
    }
    else if (choice > 20 && choice <= 40) {
        this->darkArrow(target);
    }
    else if (choice > 40 && choice <= 60) {
        this->venomousArrow(target);
    }
    else if (choice > 60 && choice <= 80) {
        this->shadowStep(target);
    }
    else {
        this->bloodRitual(target);
    }
}

void DarkElf::shadowStrike(Character& target)
{
    int manaCost = 15;

    if (getMana() >= manaCost)
    {
        int damage = 25;
        Screen::displayCharacterByCharacter(getName() + " выползает из тени и наносит скрытный удар " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурен для скрытного удара.\n");
    }
}

void DarkElf::darkArrow(Character& target) {
    int staminaCost = 20;

    if (getStamina() >= staminaCost) {
        int damage = 30;
        Screen::displayCharacterByCharacter(getName() + " выстреливает тёмной стрелой в " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        Screen::displayCharacterByCharacter(getName() + " слишком устал для выстрела тёмной стрелой.\n");
    }
}

void DarkElf::venomousArrow(Character& target)
{
    int manaCost = 20;

    if (getMana() >= manaCost)
    {
        int damage = 30;
        Screen::displayCharacterByCharacter(getName() + " выпускает стрелу, покрытую ядом, в сторону " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурен для стрельбы ядовитой стрелой.\n");
    }
}

void DarkElf::shadowStep(Character& target)
{
    int manaCost = 25;

    if (getMana() >= manaCost)
    {
        int damage = 35;
        Screen::displayCharacterByCharacter(getName() + " мгновенно перемещается в тень и атакует " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурен для мгновенного перемещения.\n");
    }
}

void DarkElf::bloodRitual(Character& target)
{
    int manaCost = 25;

    if (getMana() >= manaCost)
    {
        int damage = 30;
        int healing = damage / 2;

        Screen::displayCharacterByCharacter(getName() + " проводит кровавый обряд, направляя древние силы против " + target.getName() + "!\n");
        target.takeDamage(damage);
        Screen::displayCharacterByCharacter(getName() + " восстанавливает +" + to_string(healing) + " здоровья от кровавого обряда.\n");
        health += healing;

        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " слишком изнурен для проведения кровавого обряда.\n");
    }
}