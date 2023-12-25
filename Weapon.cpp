#include "Weapon.h"

// Конструктор
Weapon::Weapon() : Arsenal() {}

// Конструктор с параметрами
Weapon::Weapon(string n, int dmg, int cst) : Arsenal(n, dmg, cst) {}

// Деструктор
Weapon::~Weapon() {}

void Weapon::use(Character& target) {
    cout << "Attacking " << target.getName() << " with " << getName() << ".\n";
    target.takeDamage(getDamage());
    target.decreaseStamina(getCost()); // Уменьшаем выносливость персонажа
}