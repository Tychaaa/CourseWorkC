#include "Character.h"
#include "Weapon.h"
#include "Magic.h"

// Конструктор
Character::Character() : name(""), health(0), stamina(0), mana(0), level(1), experience(0) {}

// Конструктор с параметрами
Character::Character(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic)
    : name(name), health(health), stamina(stamina), mana(mana), weapon(weapon), magic(magic) {}

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
        std::cout << name << " атакует " << target.name << ", используя " << weapon->getName() << ".\n";
        target.takeDamage(weapon->getDamage());
        decreaseStamina(weapon->getCost());
    }
    else {
        cout << "У " << name << " нет оружия для атаки!\n";
    }
}

void Character::castSpell(Character& target) {
    if (magic) {
        std::cout << name << " кастует " << magic->getName() << " на " << target.name << ".\n";
        target.takeDamage(magic->getDamage());
        decreaseMana(magic->getCost());
    }
    else {
        cout << "У " << name << " нет магии для каста!\n";
    }
}

void Character::takeDamage(int dmg) {
    health -= dmg;
    cout << name << " получил " << dmg << " уронa. Текущее здоровье: " << health << "\n";
}

void Character::decreaseStamina(int cost) {
    stamina -= cost;
    cout << "Выносливость " << name << " уменшилась на " << cost << ". Текущая выносливость: " << stamina << "\n";
}

void Character::decreaseMana(int cost) {
    mana -= cost;
    cout << "Мана " << name << " уменшилась на " << cost << ". Текущая мана: " << mana << "\n";
}

void Character::levelUp() {
    level++; // Увеличиваем уровень на один

    // Увеличиваем здоровье, выносливость, ману и т.д. на определенное количество при достижении нового уровня
    // Здесь приведен лишь пример - нужно подобрать подходящие значения для вашей игры
    health += 10;
    stamina += 5;
    mana += 8;

    // Выводим сообщение о повышении уровня персонажа
    cout << "Уровень героя " << name << " повышен до " << level << "!\n";
    cout << "Здоровье увеличено до " << health << "\n Выносливость увеличенa до " << stamina << "\nМана увеличенa до " << mana << ".\n";
}