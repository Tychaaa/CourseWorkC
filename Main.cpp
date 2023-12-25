#include <iostream>
#include <Windows.h>

#include "Location.h"
#include "NPC.h"
#include "Arsenal.h"
#include "Character.h"
#include "Magic.h"
#include "Weapon.h"
#include "Monster.h"
#include "Function.h"

using namespace std;

int main() {
    // ������ ������� ���� � �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    prodTitle();

    gameTitle();

    mainMenu();

    // ������� �������
    Location town("�.�������", "��������� �������, � ������� ��� ����� �������� ���� �����������");
    Location forest("������", "������ ���... ������ �����������, ������� ������ ���������� ��� ����� ����� ������������ �������� ");

    NPC guide("������ �������", "������� ������ �������, �������� �� ��������� � ���� ����� ��� ��� ����\n�� ������������ ��� ����� ������ �������");
    NPC artem("������", "�� ������ ������ ���������� �� �������� ��� �������,\n�� � ������� ��� ������ �������� � ����");
    NPC vasya("����", "�������, �� ������ ������ ������������ ��� ������.\n�� ��� �� ���?");

    // ��������� ������ � �������
    town.addInteractiveObject(&guide);
    town.addInteractiveObject(&artem);

    forest.addInteractiveObject(&artem);
    forest.addInteractiveObject(&vasya);

    // ��������� ����
    while (true) {
        cout << "�������� ������� (1 - �.�������, 2 - ������, 0 - ����� �� ����): ";
        char locationChoice = Input::getUserInput();

        switch (locationChoice) {
        case '1':
            town.onEnter();
            break;
        case '2':
            forest.onEnter();
            break;
        case '0':
            return 0;
        default:
            cout << "�������� �����. ����������, �������� ������������ �������." << endl;
            break;
        }
    }

    return 0;
}