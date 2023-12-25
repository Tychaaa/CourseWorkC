#include "Monster.h"

Monster::Monster() : Character() {
    // ������������� �� ��������� ��� ����������� ��� �������
}

Monster::Monster(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic)
    : Character(name, health, stamina, mana, weapon, magic) {
    // ������������� ������� � ��������� �����������
}

Monster::~Monster() {
    // ���������� �������, ���� ����� ���������� �����-�� �������
}

void Monster::attack(Character& target) {
    // ���������� ������� ����� �������
    // ����� ����� ���� �����-�� ����� ������ ��� ���� ��������
    // ��������:
    int choice = rand() % 3; // ��������� ���������� ����� �� 0 �� 2

    switch (choice) {
    case 0:
        // ����� ������ �����
        // this->bite(target);
        break;
    case 1:
        // ����� ������ �����
        // this->clawAttack(target);
        break;
        // ������ ������ �������� ���� ��� ��������
        // case 2:
        //     // this->anotherAttack(target);
        //     break;
    default:
        // ����� ����� �� ���������
        cout << this->getName() << " ������� " << target.getName() << "!\n";
        // ��������, ����� ������� ������� ����:
        int damage = 10;
        target.takeDamage(damage);
        break;
    }
}