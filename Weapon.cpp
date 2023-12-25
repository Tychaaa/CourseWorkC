#include "Weapon.h"

// �����������
Weapon::Weapon() : Arsenal() {}

// ����������� � �����������
Weapon::Weapon(string n, int dmg, int cst) : Arsenal(n, dmg, cst) {}

// ����������
Weapon::~Weapon() {}

void Weapon::use(Character& target) {
    cout << "Attacking " << target.getName() << " with " << getName() << ".\n";
    target.takeDamage(getDamage());
    target.decreaseStamina(getCost()); // ��������� ������������ ���������
}