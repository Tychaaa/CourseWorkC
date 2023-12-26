#include "Weapon.h"

// Конструктор
Weapon::Weapon() : Arsenal() {}

// Конструктор с параметрами
Weapon::Weapon(string n, int dmg, int cst) : Arsenal(n, dmg, cst) {}

// Деструктор
Weapon::~Weapon() {}
