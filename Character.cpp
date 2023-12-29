#include "Character.h"
#include "Weapon.h"
#include "Magic.h"

// Конструктор
Character::Character() : name(""), health(0), stamina(0), mana(0), level(1), experience(0), classType("") {
    maxHealth = 0;
    maxStamina = 0;
    maxMana = 0;
}

// Конструктор с параметрами 1
Character::Character(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, string classtype)
    : name(name), health(health), stamina(stamina), mana(mana), weapon(weapon), magic(magic), classType(classtype) {
    maxHealth = health;
    maxStamina = health;
    maxMana = health;
}

// Конструктор с параметрами 2
Character::Character(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic, int exp)
    : name(name), health(health), stamina(stamina), mana(mana), weapon(weapon), magic(magic), experience(exp) {
    maxHealth = health;
    maxStamina = health;
    maxMana = health;
}

// Деструктор
Character::~Character(){}

// Геттеры
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

// методы для доступа к максимальным значениям
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

// Сеттеры
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

void Character::setExperience(int newExp) {
    experience += newExp;
    while (experience >= 100) {
        levelUp();
        experience -= 100; // Уменьшаем опыт на 100 после повышения уровня
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
    if (weapon) 
    {
        Screen::displayCharacterByCharacter(name + " атакует " + target.getName() + ", используя " + weapon->getName() + ".\n");
        target.takeDamage(weapon->getDamage());
        decreaseStamina(weapon->getCost());
    }
    else 
    {
        Screen::displayCharacterByCharacter("У " + name + " нет оружия для атаки!\n");
    }
}

void Character::castSpell(Character& target) 
{
    if (magic)
    {
        Screen::displayCharacterByCharacter(name + " кастует " + magic->getName() + " на " + target.name + ".\n");
        target.takeDamage(magic->getDamage());
        decreaseMana(magic->getCost());
    }
    else
    {
        Screen::displayCharacterByCharacter("У " + name + " нет магии для каста!\n");
    }
}

void Character::takeDamage(int dmg) 
{
    health -= dmg;
    Screen::displayCharacterByCharacter(name + " получил " + to_string(dmg) + " урона.\n");
}

void Character::decreaseStamina(int cost) {
    stamina -= cost;
    //cout << "Выносливость " << name << " уменшилась на " << cost << ".\n";
}

void Character::decreaseMana(int cost) {
    mana -= cost;
    //cout << "Мана " << name << " уменшилась на " << cost << ".\n";
}

void Character::regenerateStamina() {
    if (stamina < maxStamina) {
        stamina += 10 + 5 * level;
        if (stamina > maxStamina) {
            stamina = maxStamina; // Устанавливаем значение стамины в максимум, если превысили
        }
    }
}

void Character::regenerateMana() {
    if (mana < maxMana) {
        mana += 10 + 5 * level;
        if (mana > maxMana) {
            mana = maxMana; // Устанавливаем значение маны в максимум, если превысили
        }
    }
}

void Character::levelUp() {
    level++; // Увеличиваем уровень на один

    // Увеличиваем здоровье, выносливость, ману и т.д. на определенное количество при достижении нового уровня
    maxHealth += 10;
    maxStamina += 5;
    maxMana += 8;
    health = maxHealth;
    stamina = maxStamina;
    mana = maxMana;

    // Выводим сообщение о повышении уровня персонажа
    cout << "Уровень героя " << name << " повышен до " << level << "!\n";
    cout << "Здоровье увеличено до " << health << "\n Выносливость увеличенa до " << stamina << "\nМана увеличенa до " << mana << ".\n";
}