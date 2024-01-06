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

    // �������� ���������� �������
    HWND console = GetConsoleWindow();

    // ������������� ���� �������
    ShowWindow(console, SW_MAXIMIZE);





    // ������������� ��������� ���� �������
    SetConsoleTitle(L"Blades of Destiny");

    //������� ����
    //mainMenu();

    // ������� ������ ���������
    //Character mainCharacter;

    // ����� "����������"
    //introduction(mainCharacter);

    // ����� "������"
    //prologue(mainCharacter);

    // ������� ��������� �������
    //Location emerdealLocation("�.��������", "����� ������������� ������������� ����������� ��� �����������, �� �������� � ������� �� ������������ ������������ ���� � ��� ������������.\n�������� - �����, ��� ���������� ������� �������, � ������ �������� ������� �������� ����� ������������.");

    // ��������� ������� �����������
    //createEmerdealNPC(emerdealLocation, mainCharacter);

    // ������ ���������� ���
    //combatTraining(mainCharacter);

    //Weapon capitan_sword("��� ��������", 70, 5);
    //Magic magicCap("�����", 50, 15);
    //Character enemy("������� ��������", 100, 150, 150, &capitan_sword, nullptr, 100);

    Weapon sword("������� ���", 10, 5);
    Magic magic("�������� ���", 30, 5);
    Character mainCharacter("Shichi", 200, 100, 100, &sword, &magic, "����");
    DarkLord darklord("������� ����", 500, 500, 500);
    CombatSystem fight;

    fight.startGame(mainCharacter, darklord);


    //Wolf wolf("����", 60, 50, 0);

   // Ogre ogre("���", 100, 100, 0);

   // Goblin goblin("������", 60, 100, 100);

   // Skeleton skeleton("������", 40, 100, 100);

   // EarthElemental earthElemental("���������� �����", 100, 100, 150);

   // fight.startGame(mainCharacter, wolf);

    //fight.startGame(mainCharacter, ogre);

   // fight.startGame(mainCharacter, goblin);

    //fight.startGame(mainCharacter, skeleton);

    //fight.startGame(mainCharacter, earthElemental);



    return 0;
}