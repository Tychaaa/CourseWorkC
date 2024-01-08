#include "Bestiary.h"

/*
*   ���� (WOLF)
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
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
        }
    }
    return staminaRegenerationAmount;
}

void Wolf::bite(Character& target)
{
    int staminaCost = 15; // ��������� ������������ ��� �����

    if (getStamina() >= staminaCost)
    {
        int damage = 30; // ������ ���� ����� �������
        Screen::displayCharacterByCharacter(name + " � ����� ������ " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " �������� ������� � �������� ���������.\n");
    }
}

void Wolf::clawAttack(Character& target)
{
    int staminaCost = 20; // ��������� ������������ ��� ����� �������

    if (getStamina() >= staminaCost)
    {
        int damage = 10; // ������ ���� ����� �������
        Screen::displayCharacterByCharacter(name + " ����� � ������� ������� ���� ������� �� " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� � ���������, ���������, ��� �� � ��������� ������� ���� �������.\n");
    }
}

void Wolf::attack(Character& target)
{
    // �������� ��������� ����� ����� ������ � ������ �������
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen); // ���������� ��������� ����� �� 1 �� 4

    if (choice <= 30) {
        this->clawAttack(target);
    }
    else if (choice > 30 && choice <= 90) {
        this->bite(target);
    }
    else {
        Screen::displayCharacterByCharacter(name + " ������������� � �� �������� �� " + target.getName() + ".\n");
    }
}

/*
*   ��� (OGRE)
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
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
        }
    }
    return staminaRegenerationAmount;
}

void Ogre::smash(Character& target)
{
    int staminaCost = 30; // ��������� ������������ ��� �����

    if (getStamina() >= staminaCost)
    {
        int damage = 25;
        Screen::displayCharacterByCharacter(name + " ����������� �������� � ������� �������������� ���� �� " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ��������� ��������� � �� ����� ��������� ���� � ������ �����.\n");
    }
}

void Ogre::groundPound(Character& target)
{
    int staminaCost = 50; // ��������� ������������ ��� �����

    if (getStamina() >= staminaCost)
    {
        int damage = 30;
        Screen::displayCharacterByCharacter(name + " ������� ������ ���� � �����, ����������� �����, ������ " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� ������ ������� �����. ��� �� ������� ������������.\n");
    }
}

void Ogre::fistAttack(Character& target)
{
    int staminaCost = 15; // ��������� ������������ ��� �����

    if (getStamina() >= staminaCost)
    {
        int damage = 15;
        Screen::displayCharacterByCharacter(name + " ������� ���� ������� �� " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� ����� ������� � �������� ���������.\n");
    }
}

void Ogre::attack(Character& target)
{
    // �������� ��������� ����� ����� ������ � ������ �������
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int choice = dist(gen); // ���������� ��������� ����� �� 1 �� 4

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
        Screen::displayCharacterByCharacter(name + " ������������� � �� �������� �� " + target.getName() + ".\n");
    }
    
}

/*
*   ������ (GOBLIN)
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
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
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
        Screen::displayCharacterByCharacter(name + " ������������ � ������� ���� �� ���� �� " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� ��������� ���������.\n");
    }
}

void Goblin::throwRock(Character& target)
{
    int staminaCost = 15;

    if (getStamina() >= staminaCost)
    {
        int damage = 15;
        Screen::displayCharacterByCharacter(name + " ������ ������ � " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� ������� �����.\n");
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
        Screen::displayCharacterByCharacter(name + " ������������� � �� �������� �� " + target.getName() + ".\n");
    }
}

/*
*   ������ (SKELETON)
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
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
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
        Screen::displayCharacterByCharacter(name + " ����������� ������� � ������� " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� ����� �������.\n");
    }
}

void Skeleton::throwBone(Character& target)
{
    int staminaCost = 15;

    if (getStamina() >= staminaCost)
    {
        int damage = 15;
        Screen::displayCharacterByCharacter(name + " ������� ����� � " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� �����, ����� ������� �����.\n");
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
        Screen::displayCharacterByCharacter(name + " ������������� � �� �������� �� " + target.getName() + ".\n");
    }
}

/*
*   �������� ���������� (EARTH ELEMENTAL)
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
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
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
        Screen::displayCharacterByCharacter(name + " ������� �������� ������ � " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� �����, ����� ������� ������.\n");
    }
}

void EarthElemental::earthquake(Character& target)
{
    int staminaCost = 50;
    int manaCost = 40;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 30;
        Screen::displayCharacterByCharacter(name + " �������� �������������, ������� " + target.getName() + ".\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� ������ ������� �����. ������������ ������������.\n");
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
*   ������ (SUCCUBUS)
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
    int staminaCost = 35;
    int damage = 40 + rand() % 21;

    if (getStamina() >= staminaCost)
    {
        Screen::displayCharacterByCharacter(getName() + " ����������� ����� �������� " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ������ ��� ���������� ��������.\n");
    }
}

void Succubus::demonicEmbrace(Character& target)
{
    int staminaCost = 45;
    int damage = 60 + rand() % 31;

    if (getStamina() >= staminaCost)
    {
        Screen::displayCharacterByCharacter(getName() + " �������� " + target.getName() + " � ������������ ������!\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ������ ��� ������������� �������.\n");
    }
}

void Succubus::charmingKiss(Character& target)
{
    int manaCost = 50;
    int damage = 70 + rand() % 31;

    if (getMana() >= manaCost)
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ������������� ������� " + target.getName() + "!\n");
        Screen::displayCharacterByCharacter(target.getName() + " �������� �� ���.\n");
        target.takeDamage(damage);
        target.decreaseStamina(manaCost / 2);

        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� �������� ��� �������������� �������.\n");
    }
}

void Succubus::seductiveWhisper(Character& target)
{
    int staminaCost = 40;
    int damage = 45 + rand() % 16;

    if (getStamina() >= staminaCost)
    {
        Screen::displayCharacterByCharacter(getName() + " ������ �������������� ����� " + target.getName() + "!\n");
        target.takeDamage(damage);
        Screen::displayCharacterByCharacter(getName() + " ��������������� +" + to_string(damage / 2) + " �������� �� ������� ����������.\n");
        health += damage / 2;
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ������ ��� ��������������� ������.\n");
    }
}

void Succubus::passionateTrap(Character& target)
{
    int manaCost = 70;
    int damage = 80 + rand() % 21;

    if (getMana() >= manaCost)
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ������� ������� ������ " + target.getName() + "!\n");
        Screen::displayCharacterByCharacter(target.getName() + " ����������� � ����� ��������� ������ � �������� ����.\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� �������� ��� �������� ������� �������.\n");
    }
}

/*
*   ������ (WITCH)
*/

Witch::Witch() : Character() {}

Witch::Witch(std::string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 80;
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
    int manaCost = 70;

    if (getMana() >= manaCost)
    {
        int damage = 50 + rand() % 31;
        Screen::displayCharacterByCharacter(getName() + " ����������� ������ ��������� �� " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� �������� ��� ��������� ������� ���������.\n");
    }
}

void Witch::hexingBlast(Character& target)
{
    int staminaCost = 80;

    if (getStamina() >= staminaCost)
    {
        int damage = 50 + rand() % 31;
        Screen::displayCharacterByCharacter(getName() + " ��������� ��������� ������� ������� �� " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ������ ��� ����������� ������.\n");
    }
}

void Witch::summonMinions(Character& target)
{
    int manaCost = 50;

    if (getMana() >= manaCost)
    {
        int damage = 50 + rand() % 31;
        Screen::displayCharacterByCharacter(getName() + " ��������� �������� ��� ����� " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� �������� ��� ������� ��������.\n");
    }
}

void Witch::poisonousBrew(Character& target)
{
    int staminaCost = 55;

    if (getStamina() >= staminaCost)
    {
        int damage = 50 + rand() % 31;
        Screen::displayCharacterByCharacter(getName() + " ������� �������� ����� � ������� " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ������ ��� ������ ��������� �����.\n");
    }
}

void Witch::mysticalShield(Character& target)
{
    int manaCost = 70;

    if (getMana() >= manaCost)
    {
        int shieldAmount = 40 + rand() % 31;
        Screen::displayCharacterByCharacter(getName() + " ������� ����������� ��� (+" + to_string(shieldAmount) + " hp), ��������� �� ���� " + target.getName() + "!\n");
        health += shieldAmount;
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� �������� ��� �������� ������������ ����.\n");
    }
}

/*
*   ��������������� (ENCHANTRESS)
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
    int staminaCost = 40;
    int damage = 50 + rand() % 11;

    if (getStamina() >= staminaCost)
    {
        Screen::displayCharacterByCharacter(getName() + " ����������� � " + target.getName() + " ����������� ��������������!\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ������ ��� ������������ �������������.\n");
    }
}

void Enchantress::etherealDance(Character& target)
{
    int manaCost = 50;
    int damage = 55 + rand() % 11;

    if (getMana() >= manaCost)
    {
        Screen::displayCharacterByCharacter(getName() + " ��������� ������� ����� ����� " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� �������� ��� �������� �����.\n");
    }
}

void Enchantress::mysticBlast(Character& target)
{
    int manaCost = 55;
    int damage = 55 + rand() % 11;

    if (getMana() >= manaCost)
    {
        Screen::displayCharacterByCharacter(getName() + " ��������� ����������� ����� �� " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� �������� ��� ������������ ������.\n");
    }
}

void Enchantress::whirlwindOfEnchantment(Character& target)
{
    int manaCost = 70;
    int damage = 60 + rand() % 11;

    if (getMana() >= manaCost)
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ����� ���������� ������ " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� �������� ��� �������� ����� ����������.\n");
    }
}

void Enchantress::mirrorIllusion(Character& target)
{
    int manaCost = 60;
    int damage = 65 + rand() % 11;

    if (getMana() >= manaCost)
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ���������� �������, ������� ������� " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� �������� ��� �������� ���������� �������.\n");
    }
}
/*
*   �����-�������� (DEMON)
*/

Demon::Demon() : Character() {}

Demon::Demon(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "")
{
    experience = 70;
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
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
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
    int staminaCost = 40;
    int manaCost = 40;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 60 + rand() % 26;
        Screen::displayCharacterByCharacter(name + " � ������������ ����� �������� ��������� ���� �� ������, ������� ���������� " + target.getName() + " �������� ������.\n");
        target.takeDamage(damage);
        Screen::displayCharacterByCharacter("����� ��������� ������� ���� �� �����, �������� ���������� ���.\n");

        decreaseStamina(staminaCost);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� ������ ���������� �����.\n");
    }
}

void Demon::cursedOath(Character& target)
{
    int staminaCost = 30;
    int manaCost = 25;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 50 + rand() % 16;
        int staminaDamage = 10;
        Screen::displayCharacterByCharacter("�����-�������� ���������� ������� ����������� �����, ���������� �� ������, � ������� ��������� ���� �� " + target.getName() + ".\n");
        target.takeDamage(damage);
        Screen::displayCharacterByCharacter("���� ��������� ������ ����� �� �������� " + target.getName() + ", ������� ��������� ��������.\n");
        target.setStamina(target.getStamina() - staminaDamage);

        decreaseStamina(staminaCost);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� ���������� �����.\n");
    }
}

void Demon::infernalCurse(Character& target)
{
    int manaCost = 40;

    if (getMana() >= manaCost)
    {
        int staminaDamage = 60;
        Screen::displayCharacterByCharacter("�����-�������� ������� ������ ��������� �� " + target.getName() + ", �������� ��� � ��� ������ ����.\n");
        Screen::displayCharacterByCharacter("��������� ��������� " + target.getName() + " � ������������� ����������, �������� ��� ����.\n");
        target.setStamina(target.getStamina() - staminaDamage);

        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ������� ��� ���������.\n");
    }
}

void Demon::infernalBlade(Character& target)
{
    int staminaCost = 60;
    int manaCost = 60;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 70 + rand() % 16;
        Screen::displayCharacterByCharacter("�����-�������� ������� ������ �� ���� � ����, ��������� ��� � ������� " + target.getName() + ".\n");
        target.takeDamage(damage);

        decreaseStamina(staminaCost);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� �������� ������.\n");
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
*   ������� ���� (DARK LORD)
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
    int staminaRegenerationAmount = 40;

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
    int manaRegenerationAmount = 40;

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
    int staminaCost = 70;
    int manaCost = 70;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 40 + rand() % 21;
        Screen::displayCharacterByCharacter(name + " ������� ����, ����������� ���� �����... ������� �������� ����!\n");

        Screen::displayCharacterByCharacter(name + " � �������� � ���� ���������� ������ ����, �������� ���� ��������� �����...\n");
        target.takeDamage(damage);

        Screen::displayCharacterByCharacter(name + " � ������ ����� �������� �������, �������� ������...\n");
        target.takeDamage(damage);

        Screen::displayCharacterByCharacter(name + " ������ �����, ��������� � �����, ������ �������� ����...\n");
        target.takeDamage(damage);

        Screen::displayCharacterByCharacter("���� �������� ������������, ��������� ��������� �� ���� �����.\n");

        decreaseStamina(staminaCost);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� �������� �����.\n");
    }
}

void DarkLord::shadowStrike(Character& target)
{
    int staminaCost = 50;
    int manaCost = 40;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 70 + rand() % 16;
        Screen::displayCharacterByCharacter(name + " ���������� ������ ������ �� ���� �� " + target.getName() + ".\n");
        Screen::displayCharacterByCharacter(name + " � ������������ �������� ����� ������������, �������� ��� ����������� ���������.\n");
        target.takeDamage(damage);

        decreaseStamina(staminaCost);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� �������� �����.\n");
    }
}

void DarkLord::summonMinions(Character& target)
{
    int manaCost = 65;

    if (getMana() >= manaCost)
    {
        int damage = 50 + rand() % 26;
        Screen::displayCharacterByCharacter(name + " ��������� ������� �������, ���������� �� " + target.getName() + ".\n");

        Screen::displayCharacterByCharacter("�������� ��������������� ����� " + target.getName() + ", ��� �������� ������ �������� ����.\n");
        target.takeDamage(damage);

        Screen::displayCharacterByCharacter("�������� �������� � ������� �������, ��� ����� �������� " + target.getName() + "!\n");
        target.takeDamage(damage);

        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� ������� ������������.\n");
    }
}

void DarkLord::energyAbsorption(Character& target)
{
    int manaCost = 70;

    if (getMana() >= manaCost)
    {
        int healAmount = 40 + rand() % 21;
        Screen::displayCharacterByCharacter(name + " ��������� ������� �� ���������� ����, �������������� ��� ��������.\n");
        health += healAmount;
        Screen::displayCharacterByCharacter(name + " �������� ����� ����, ����������� " + to_string(healAmount) + " ������ ��������.\n");
        
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� �������, ����� ��������� ������� ������ ����.\n");
    }
}

void DarkLord::worldHeartDestruction(Character& target)
{
    int staminaCost = 70;
    int manaCost = 50;

    if (getStamina() >= staminaCost && getMana() >= manaCost)
    {
        int damage = 90 + rand() % 16;
        Screen::displayCharacterByCharacter(name + " ���������� �������������� ����� �� ��������� ����, ������ ���� " + target.getName() + ".\n");
        target.takeDamage(damage);

        decreaseStamina(staminaCost);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(name + " ������� ����� ��� ����� �� ���������� ����.\n");
    }
}

void DarkLord::manaDrain(Character& target)
{
    int manaDamage = 30 + rand() % 16;

    Screen::displayCharacterByCharacter(name + " ��������� ���� � �����, ��������� ������� �� " + target.getName() + ", ������� ��� ����.\n");
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
*   Ҩ���� ���� (DARK ELF)
*/

DarkElf::DarkElf() : Character() {}

DarkElf::DarkElf(std::string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "") 
{
    experience = 100;
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
    int manaCost = 60;

    if (getMana() >= manaCost)
    {
        int damage = 80 + rand() % 21;
        Screen::displayCharacterByCharacter(getName() + " ��������� �� ���� � ������� �������� ���� " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ������� ��� ��������� �����.\n");
    }
}

void DarkElf::darkArrow(Character& target) {
    int staminaCost = 50;

    if (getStamina() >= staminaCost) {
        int damage = 90 + rand() % 11;
        Screen::displayCharacterByCharacter(getName() + " ������������ ����� ������� � " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        Screen::displayCharacterByCharacter(getName() + " ������� ����� ��� �������� ����� �������.\n");
    }
}

void DarkElf::venomousArrow(Character& target)
{
    int manaCost = 65;

    if (getMana() >= manaCost)
    {
        int damage = 90 + rand() % 11;
        Screen::displayCharacterByCharacter(getName() + " ��������� ������, �������� ����, � ������� " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ������� ��� �������� �������� �������.\n");
    }
}

void DarkElf::shadowStep(Character& target)
{
    int manaCost = 80;

    if (getMana() >= manaCost)
    {
        int damage = 95 + rand() % 6;
        Screen::displayCharacterByCharacter(getName() + " ��������� ������������ � ���� � ������� " + target.getName() + "!\n");
        target.takeDamage(damage);
        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ������� ��� ����������� �����������.\n");
    }
}

void DarkElf::bloodRitual(Character& target)
{
    int manaCost = 50;

    if (getMana() >= manaCost)
    {
        int damage = 95 + rand() % 6;
        int healing = damage / 2;

        Screen::displayCharacterByCharacter(getName() + " �������� �������� �����, ��������� ������� ���� ������ " + target.getName() + "!\n");
        target.takeDamage(damage);
        Screen::displayCharacterByCharacter(getName() + " ��������������� +" + to_string(healing) + " �������� �� ��������� ������.\n");
        health += healing;

        decreaseMana(manaCost);
    }
    else
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ������� ��� ���������� ��������� ������.\n");
    }
}