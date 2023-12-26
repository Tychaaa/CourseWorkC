#include <iostream>
#include <Windows.h>

#include "Location.h"
#include "NPC.h"
#include "Arsenal.h"
#include "Character.h"
#include "Magic.h"
#include "Weapon.h"
#include "Monster.h"
#include "Bestiary.h"
#include "Function.h"

using namespace std;

int main() {
    // ������ ������� ���� � �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //prodTitle();

    //mainMenu();

    //// ������� �������
    //Location town("�.�������", "��������� �������, � ������� ��� ����� �������� ���� �����������");
    //Location forest("������", "������ ���... ������ �����������, ������� ������ ���������� ��� ����� ����� ������������ �������� ");

    //NPC guide("������ �������", "������� ������ �������, �������� �� ��������� � ���� ����� ��� ��� ����\n�� ������������ ��� ����� ������ �������");
    //NPC artem("������", "�� ������ ������ ���������� �� �������� ��� �������,\n�� � ������� ��� ������ �������� � ����");
    //NPC vasya("����", "�������, �� ������ ������ ������������ ��� ������.\n�� ��� �� ���?");

    //// ��������� ������ � �������
    //town.addInteractiveObject(&guide);
    //town.addInteractiveObject(&artem);

    //forest.addInteractiveObject(&artem);
    //forest.addInteractiveObject(&vasya);

    //// ��������� ����
    //while (true) {
    //    cout << "�������� ������� (1 - �.�������, 2 - ������, 0 - ����� �� ����): ";
    //    char locationChoice = Input::getUserInput();

    //    switch (locationChoice) {
    //    case '1':
    //        town.onEnter();
    //        break;
    //    case '2':
    //        forest.onEnter();
    //        break;
    //    case '0':
    //        return 0;
    //    default:
    //        cout << "�������� �����. ����������, �������� ������������ �������." << endl;
    //        break;
    //    }
    //}


    Weapon* sword = new Weapon("���", 20, 5);
    Magic* fireball = new Magic("�������� ���", 30, 10);
    Character player("�����", 100, 50, 50, sword, fireball);

    Wolf wolf("����", 80, 30, 0, nullptr, nullptr);




    while (player.getHealth() > 0 && wolf.getHealth() > 0) {
        cout << "�������� �������� ��� �����: \n";
        cout << "1. ��������� �����\n";
        cout << "2. ������������ �����\n";

        int choice;
        cin >> choice;

        if (choice == 1) {
            player.attack(wolf); // ����� �����
        }
        else if (choice == 2) {
            player.castSpell(wolf); // ������������ �����
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



    return 0;
}