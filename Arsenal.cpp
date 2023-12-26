#include "Arsenal.h"

// Конструктор
Arsenal::Arsenal() : name(""), damage(0), cost(0) {}

// Конструктор с параметрами
Arsenal::Arsenal(string n, int dmg, int cst) : name(n), damage(dmg), cost(cst) {}

// Деструктор
Arsenal::~Arsenal() {}

// Геттеры
string Arsenal::getName() const
{
    return name;
}

int Arsenal::getDamage() const
{
    return damage;
}

int Arsenal::getCost() const
{
    return cost;
}

// Сеттеры
void Arsenal::setName(string n)
{
    name = n;
}

void Arsenal::setDamage(int dmg)
{
    damage = dmg;
}

void Arsenal::setCost(int cst)
{
    cost = cst;
}

