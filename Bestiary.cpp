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
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
        }
    }
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
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
        }
    }
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
        stamina += 10; // ������ ��������������� ������ ������������
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

    if (getStamina() >= staminaCost)
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
    Screen::displayCharacterByCharacter(name + " ������������� � �� �������� �� " + target.getName() + ".\n");
}