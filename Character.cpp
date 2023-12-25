#include "Character.h"
#include "Weapon.h"
#include "Magic.h"

// �����������
Character::Character() : name(""), health(0), stamina(0), mana(0), level(1), experience(0) {}

// ����������� � �����������
Character::Character(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic)
    : name(name), health(health), stamina(stamina), mana(mana), weapon(weapon), magic(magic) {}

// ����������
Character::~Character(){}

// �������
string Character::getName() const
{
    return name;
}

int Character::getHealth() const
{
    return health;
}

int Character::getStamina() const
{
    return stamina;
}

int Character::getMana() const
{
    return mana;
}

int Character::getLevel() const
{
    return level;
}

int Character::getExperience() const
{
    return experience;
}

Weapon* Character::getWeapon() const
{
    return weapon;
}

Magic* Character::getMagic() const
{
    return magic;
}

// �������
void Character::setName(string newName)
{
    name = newName;
}

void Character::setHealth(int newHealth)
{
    health = newHealth;
}

void Character::setStamina(int newStamina)
{
    stamina = newStamina;
}

void Character::setMana(int newMana)
{
    mana = newMana;
}

void Character::setLevel(int newLevel)
{
    level = newLevel;
}

void Character::setExperience(int newExp)
{
    experience = newExp;
}

void Character::setWeapon(Weapon* newWeapon)
{
    weapon = newWeapon;
}

void Character::setMagic(Magic* newMagic)
{
    magic = newMagic;
}


void Character::attack(Character& target) {
    if (weapon) {
        std::cout << name << " ������� " << target.name << ", ��������� " << weapon->getName() << ".\n";
        target.takeDamage(weapon->getDamage());
        decreaseStamina(weapon->getCost());
    }
    else {
        cout << "� " << name << " ��� ������ ��� �����!\n";
    }
}

void Character::castSpell(Character& target) {
    if (magic) {
        std::cout << name << " ������� " << magic->getName() << " �� " << target.name << ".\n";
        target.takeDamage(magic->getDamage());
        decreaseMana(magic->getCost());
    }
    else {
        cout << "� " << name << " ��� ����� ��� �����!\n";
    }
}

void Character::takeDamage(int dmg) {
    health -= dmg;
    cout << name << " ������� " << dmg << " ����a. ������� ��������: " << health << "\n";
}

void Character::decreaseStamina(int cost) {
    stamina -= cost;
    cout << "������������ " << name << " ���������� �� " << cost << ". ������� ������������: " << stamina << "\n";
}

void Character::decreaseMana(int cost) {
    mana -= cost;
    cout << "���� " << name << " ���������� �� " << cost << ". ������� ����: " << mana << "\n";
}

void Character::levelUp() {
    level++; // ����������� ������� �� ����

    // ����������� ��������, ������������, ���� � �.�. �� ������������ ���������� ��� ���������� ������ ������
    // ����� �������� ���� ������ - ����� ��������� ���������� �������� ��� ����� ����
    health += 10;
    stamina += 5;
    mana += 8;

    // ������� ��������� � ��������� ������ ���������
    cout << "������� ����� " << name << " ������� �� " << level << "!\n";
    cout << "�������� ��������� �� " << health << "\n ������������ ��������a �� " << stamina << "\n���� ��������a �� " << mana << ".\n";
}