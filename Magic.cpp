#include "Magic.h"

// �����������
Magic::Magic() : Arsenal() {}

// ����������� � �����������
Magic::Magic(string n, int dmg, int cst) : Arsenal(n, dmg, cst) {}

// ����������
Magic::~Magic() {}

void Magic::use(Character& target) {
    cout << "Casting " << getName() << " on " << target.getName() << ".\n";
    target.takeDamage(getDamage());
    target.decreaseMana(getCost()); // ��������� ���� ���������
}