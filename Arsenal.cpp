#include "Arsenal.h"

// �����������
Arsenal::Arsenal() : name(""), damage(0), cost(0) {}

// ����������� � �����������
Arsenal::Arsenal(string n, int dmg, int cst) : name(n), damage(dmg), cost(cst) {}

// ����������
Arsenal::~Arsenal() {}

// �������
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

// �������
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

