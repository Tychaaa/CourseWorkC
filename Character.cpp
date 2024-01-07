#include "Character.h"
#include "Weapon.h"
#include "Magic.h"

// �����������
Character::Character() : name(""), health(0), stamina(0), mana(0), level(1), experience(0), classType("")
{
    maxHealth = 0;
    maxStamina = 0;
    maxMana = 0;
}

// ����������� � ����������� 1
Character::Character(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype)
    : name(name), health(health), stamina(stamina), mana(mana), weapon(weapon), magic(magic), classType(classtype)
{
    maxHealth = health;
    maxStamina = stamina;
    maxMana = mana;
}

// ����������� � ����������� 2
Character::Character(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, int exp)
    : name(name), health(health), stamina(stamina), mana(mana), weapon(weapon), magic(magic), experience(exp)
{
    maxHealth = health;
    maxStamina = stamina;
    maxMana = mana;
}

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

int Character::getMaxHealth() const
{
    return maxHealth;
}

int Character::getMaxStamina() const
{
    return maxStamina;
}

int Character::getMaxMana() const
{
    return maxMana;
}

int Character::getLevel() const
{
    return level;
}

int Character::getExperience() const
{
    return experience;
}

string Character::getClassType() const
{
    return classType;
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

void Character::setMaxHealth(int value)
{
    maxHealth = value;
}

void Character::setMaxStamina(int value)
{
    maxStamina = value;
}

void Character::setMaxMana(int value)
{
    maxMana = value;
}

void Character::setLevel(int newLevel)
{
    level = newLevel;
}

void Character::setExperience(int newExp)
{
    experience += newExp;
    while (experience >= 100) {
        levelUp();
        experience -= 100; // ��������� ���� �� 100 ����� ��������� ������
    }
}

void Character::setClassType(string newClass)
{
    classType = newClass;
}

void Character::setWeapon(Weapon* newWeapon)
{
    weapon = newWeapon;
}

void Character::setMagic(Magic* newMagic)
{
    magic = newMagic;
}

void Character::attack(Character& target)
{
    while (true)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(1, 100);

        int choice = dist(gen);

        if (choice <= 45)
        {
            if(weapon==nullptr)
            {
                continue;
            }
            attackWeapon(target);
            break;
        }
        else if (choice > 45 && choice <= 90)
        {
            if (magic == nullptr)
            {
                continue;
            }
            castSpell(target);
            break;
        }
        else
        {
            Screen::displayCharacterByCharacter(name + " ������������� � �� �������� �� " + target.getName() + ".\n");
            break;
        }
    }
}

void Character::attackWeapon(Character& target) 
{
    Screen::displayCharacterByCharacter(name + " ������� " + target.getName() + ", ��������� " + weapon->getName() + ".\n");
    target.takeDamage(weapon->getDamage());
    decreaseStamina(weapon->getCost());
}

void Character::castSpell(Character& target) 
{
    Screen::displayCharacterByCharacter(name + " ������� " + magic->getName() + " �� " + target.name + ".\n");
    target.takeDamage(magic->getDamage());
    decreaseMana(magic->getCost());
}

void Character::takeDamage(int dmg) 
{
    health -= dmg;

    if (health < dmg)
    {
        health = 0;
    }

    Screen::displayCharacterByCharacter(name + " ������� " + to_string(dmg) + " �����.\n");
}

void Character::decreaseStamina(int cost) {
    stamina -= cost;
}

void Character::decreaseMana(int cost)
{
    mana -= cost;
}

int Character::regenerateStamina()
{
    int staminaRegenerationAmount = 10 + 0.5 * level;
    if (stamina < maxStamina) {
        stamina += staminaRegenerationAmount;
        if (stamina > maxStamina)
        {
            stamina = maxStamina; // ������������� �������� ������� � ��������, ���� ���������
        }
    }

    return staminaRegenerationAmount;
}

int Character::regenerateMana()
{
    int manaRegenerationAmount = 10 + 0.5 * level;

    if (mana < maxMana)
    {
        mana += manaRegenerationAmount;
        if (mana > maxMana)
        {
            mana = maxMana; // ������������� �������� ���� � ��������, ���� ���������
        }
    }

    return manaRegenerationAmount;
}

void Character::levelUp()
{
    level++; // ����������� ������� �� ����

    // ����������� ��������, ������������, ���� � �.�. �� ������������ ���������� ��� ���������� ������ ������
    maxHealth += 10;
    maxStamina += 5;
    maxMana += 8;
    health = maxHealth;
    stamina = maxStamina;
    mana = maxMana;

    // ������� ��������� � ��������� ������ ���������
    cout << "\n������� ����� " << name << " ������� �� ";
    this_thread::sleep_for(chrono::milliseconds(500));

    for (char c : to_string(level))
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(100)); // �������� � �������������
    }
    cout << "!" << endl;

    cout << "�������� ��������� �� ";
   this_thread::sleep_for(chrono::milliseconds(500));
    for (char c : to_string(health))
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(100)); // �������� � �������������
    }
    cout << endl;

    cout << "������������ ��������a �� ";
    this_thread::sleep_for(chrono::milliseconds(500));
    for (char c : to_string(stamina))
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(100)); // �������� � �������������
    }
    cout << endl;

    cout << "���� ��������a �� ";
    this_thread::sleep_for(chrono::milliseconds(500));
    for (char c : to_string(mana))
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(100)); // �������� � �������������
    }
    cout << endl;
}