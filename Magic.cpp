#include "Magic.h"

// Конструктор
Magic::Magic() : Arsenal() {}

// Конструктор с параметрами
Magic::Magic(string n, int dmg, int cst) : Arsenal(n, dmg, cst) {}

// Деструктор
Magic::~Magic() {}

void Magic::use(Character& target) {
    cout << "Casting " << getName() << " on " << target.getName() << ".\n";
    target.takeDamage(getDamage());
    target.decreaseMana(getCost()); // Уменьшаем ману персонажа
}