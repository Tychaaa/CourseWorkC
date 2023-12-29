#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

#include "Arsenal.h"
#include "Bestiary.h"
#include "Character.h"
#include "CombatSystem.h"
#include "Function.h"
#include "Location.h"
#include "Magic.h"
#include "Monster.h"
#include "NPC.h"
#include "Weapon.h"

using namespace std;

int main() {
    // ������ ������� ���� � �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������������� ��������� ���� �������
    SetConsoleTitle(L"Blades of Destiny");

    //������� ����
    mainMenu();

    // ������� ������ ���������
    Character mainCharacter;

    // ����� "����������"
    introduction(mainCharacter);

    // ����� "������"
    prologue(mainCharacter);

    // ������� ��������� �������
    Location emerdealLocation("�.��������", "����� ������������� ������������� ����������� ��� �����������, �� �������� � ������� �� ������������ ������������ ���� � ��� ������������.\n�������� - �����, ��� ���������� ������� �������, � ������ �������� ������� �������� ����� ������������.");

    // ��������� ������� �����������
    createEmerdealNPC(emerdealLocation, mainCharacter);

    // ������ ���������� ���
    combatTraining(mainCharacter);

    Weapon capitan_sword("��� ��������", 10, 5);
    Character enemy("������� ��������", 100, 150, 150, &capitan_sword, nullptr, 100);

    CombatSystem fight;

    fight.startGame(mainCharacter, enemy);

    return 0;
}