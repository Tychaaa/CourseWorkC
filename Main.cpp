#include <iostream>
#include <Windows.h>

#include "Location.h"
#include "NPC.h"
#include "Arsenal.h"
#include "Character.h"
#include "Magic.h"
#include "Weapon.h"
#include "Monster.h"

using namespace std;

int main() {
    // ������ ������� ���� � �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //// ������� �������
    //Location town("�.�������", "��������� �������, � ������� ��� ����� �������� ���� �����������");
    //Location forest("������", "������ ���... ������ �����������, ������� ������ ���������� ��� ����� ����� ������������ �������� ");

    //NPC guide("�������", "����� ���������� � ��� ���� � �����!");

    //// ��������� ������ � �������
    //town.addInteractiveObject(&guide);

    //// ��������� ����
    //town.onEnter();

    //forest.addInteractiveObject(&guide);

    //forest.onEnter();

   // �������� ������ � �����
    //Weapon sword("���", 20, 5);
    //Magic fireball("�������� ���", 30, 10);

    //// �������� ����������
    //Character player("�����", 100, 50, 50, &sword, &fireball);
    //Character enemy("������", 80, 40, 20, nullptr, nullptr);

    //// ����� ������ � ������������� ����� ����������
    //player.attack(enemy);
    //enemy.castSpell(player);

    //// ����� ���������� � ��������� ������ � �����
    //cout << "��������� ������:\n";
    //cout << "��������: " << player.getHealth() << "\n";
    //cout << "�������: " << player.getStamina() << "\n";
    //cout << "����: " << player.getMana() << "\n";

    //cout << "\n��������� �����:\n";
    //cout << "��������: " << enemy.getHealth() << "\n";
    //cout << "�������: " << enemy.getStamina() << "\n";
    //cout << "����: " << enemy.getMana() << "\n";


    Weapon* sword = new Weapon("���", 20, 5);
    Magic* fireball = new Magic("�������� ���", 30, 10);
    Character player("�����", 100, 50, 50, sword, fireball);

    Weapon* fangs = new Weapon("�����", 15, 0);
    Magic* none = new Magic();
    Monster wolf("����", 80, 30, 0, fangs, none);

    while (player.getHealth() > 0 && wolf.getHealth() > 0) {
        cout << "�������� �������� ��� �����: \n";
        cout << "1. ��������� �����\n";
        cout << "2. ������������ �����\n";

        int choice;
        cin >> choice;

        if (choice == 1) {
            player.attack(*wolf.getWeapon()); // ����� �����
        }
        else if (choice == 2) {
            player.castSpell(*wolf.getMagic()); // ������������ �����
        }
        else {
            cout << "������������ �����. ���������� ��� ���." << endl;
            continue; // ���������� ����, ����� �������� ��������� ����� ��������
        }

        if (wolf.getHealth() <= 0) {
            cout << "���� ��������!" << endl;
            break;
        }

        wolf.attack(player);

        if (player.getHealth() <= 0) {
            cout << "����� ��������!" << endl;
            break;
        }

        cout << "�������� �����: " << player.getHealth() << " | �������� �����: " << wolf.getHealth() << endl;
    }

    delete sword;
    delete fireball;
    delete fangs;
    delete none;

    return 0;
}