#include "Weapon.h"

// �����������
Weapon::Weapon() : Arsenal() {}

// ����������� � �����������
Weapon::Weapon(string n, int dmg, int cst) : Arsenal(n, dmg, cst) {}

// ����������
Weapon::~Weapon() {}
