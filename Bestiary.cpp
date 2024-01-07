#include "Bestiary.h"

/*
*   ���� (WOLF)
*/

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
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
        }
    }
}

void Wolf::bite(Character& target) {
    int staminaCost = 15; // ��������� ������������ ��� �����

    if (getStamina() >= staminaCost) {
        int damage = 30; // ������ ���� ����� �������
        cout << this->getName() << " � ����� ������ " << target.getName() << endl;
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " �������� ������� � �������� ���������.\n";
    }
}

void Wolf::clawAttack(Character& target) {
    int staminaCost = 20; // ��������� ������������ ��� ����� �������

    if (getStamina() >= staminaCost) {
        int damage = 10; // ������ ���� ����� �������
        cout << this->getName() << " ����� � ������� ������� ���� ������� �� " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ������� � ���������, ���������, ��� �� � ��������� ������� ���� �������.\n";
    }
}

void Wolf::attack(Character& target) {
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
        cout << this->getName() << " ������������� � �� �������� �� " << target.getName() << "!\n";
    }
}

/*
*   ��� (OGRE)
*/

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
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
        }
    }
}

void Ogre::smash(Character& target) {
    int staminaCost = 30; // ��������� ������������ ��� �����

    if (getStamina() >= staminaCost) {
        int damage = 25;
        cout << this->getName() << " ����������� �������� � ������� �������������� ���� �� " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ��������� ��������� � �� ����� ��������� ���� � ������ �����.\n";
    }
}

void Ogre::groundPound(Character& target) {
    int staminaCost = 50; // ��������� ������������ ��� �����

    if (getStamina() >= staminaCost) {
        int damage = 30;
        cout << this->getName() << " ������� ������ ���� � �����, ����������� �����, ������ " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ������� ����� ��� ������ ������� �����. ��� �� ������� ������������.\n";
    }
}

void Ogre::fistAttack(Character& target) {
    int staminaCost = 15; // ��������� ������������ ��� �����

    if (getStamina() >= staminaCost) {
        int damage = 15;
        cout << this->getName() << " ������� ���� ������� �� " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ������� ����� ��� ����� ������� � �������� ���������.\n";
    }
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
    else if (choice > 80 && choice <= 90) {
        this->smash(target);
    }
    else {
        cout << this->getName() << " ������������� � �� �������� �� " << target.getName() << "!\n";
    }
    
}

/*
*   ������ (GOBLIN)
*/

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
        cout << this->getName() << " ������������ � ������� ���� �� ���� �� " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ������� ����� ��� ��������� ���������.\n";
    }
}

void Goblin::throwRock(Character& target) {
    int staminaCost = 15;

    if (getStamina() >= staminaCost) {
        int damage = 15;
        cout << this->getName() << " ������ ������ � " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ������� ����� ��� ������� �����.\n";
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
        cout << this->getName() << " ������������� � �� �������� �� " << target.getName() << "!\n";
    }
}

/*
*   ������ (SKELETON)
*/

Skeleton::Skeleton() : Character() {}

Skeleton::Skeleton(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "") {
    experience = 30;
}

Skeleton::~Skeleton() {}

void Skeleton::regenerateStamina() {
    if (stamina < maxStamina) {
        stamina += 10; // ������ ��������������� ������ ������������
        if (stamina > maxStamina) {
            stamina = maxStamina;
        }
    }
}

void Skeleton::boneStrike(Character& target) {
    int staminaCost = 20;

    if (getStamina() >= staminaCost) {
        int damage = 25;
        cout << this->getName() << " ����������� ������� � ������� " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ������� ����� ��� ����� �������.\n";
    }
}

void Skeleton::throwBone(Character& target) {
    int staminaCost = 15;

    if (getStamina() >= staminaCost) {
        int damage = 15;
        cout << this->getName() << " ������� ����� � " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ������� ����� ��� ������ �����.\n";
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
        cout << this->getName() << " ������������� � �� �������� �� " << target.getName() << "!\n";
    }
}

/*
*   �������� ���������� (EARTH ELEMENTAL)
*/

EarthElemental::EarthElemental() : Character() {}

EarthElemental::EarthElemental(string name, int health, int stamina, int mana)
    : Character(name, health, stamina, mana, nullptr, nullptr, "") {
    experience = 40;
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
        cout << this->getName() << " ������� �������� ������ � " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ������� ����� ��� ������� �����.\n";
    }
}

void EarthElemental::earthquake(Character& target) {
    int staminaCost = 50;

    if (getStamina() >= staminaCost) {
        int damage = 30;
        cout << this->getName() << " �������� �������������, ������� " << target.getName() << "!\n";
        target.takeDamage(damage);
        decreaseStamina(staminaCost);
    }
    else {
        cout << this->getName() << " ������� ����� ��� ������ ������� �����. ������������ ������������.\n";
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

void Succubus::regenerateStamina()
{
    if (stamina < maxStamina) 
    {
        stamina += 25;
        if (stamina > maxStamina) 
        {
            stamina = maxStamina;
        }
    }
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
    int staminaCost = 25;

    if (getStamina() >= staminaCost)
    {
        int damage = 30;
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
    int manaCost = 15;

    if (getMana() >= manaCost)
    {
        int damage = 20;
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
    int staminaCost = 20;

    if (getStamina() >= staminaCost)
    {
        int damage = 25;
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
    int manaCost = 30;

    if (getMana() >= manaCost)
    {
        int damage = 40;
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
    experience = 60;
}

Witch::~Witch() {}

void Witch::regenerateStamina()
{
    if (stamina < maxStamina)
    {
        stamina += 20;
        if (stamina > maxStamina)
        {
            stamina = maxStamina;
        }
    }
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
    int staminaCost = 20;

    if (getStamina() >= staminaCost)
    {
        int damage = 25;
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
    int manaCost = 25;

    if (getMana() >= manaCost)
    {
        int damage = 30;
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
    int staminaCost = 20;

    if (getStamina() >= staminaCost)
    {
        int damage = 25;
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
    int manaCost = 15;

    if (getMana() >= manaCost)
    {
        Screen::displayCharacterByCharacter(getName() + " ������� ����������� ��� (+" + to_string(manaCost) + " hp), ��������� �� ���� " + target.getName() + "!\n");
        health += manaCost;
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

void Enchantress::regenerateMana()
{
    if (mana < maxMana)
    {
        mana += 20;
        if (mana > maxMana)
        {
            mana = maxMana;
        }
    }
}

void Enchantress::attack(Character& target)
{
}
