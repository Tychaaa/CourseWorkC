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
#include "NPC.h"
#include "Weapon.h"

using namespace std;

int main() 
{
    // ������������� ��������� �������
    consoleSetting();

    ////������� ����
    //mainMenu();

    // ������� ������ ���������
    //Character mainCharacter = createMainCharacter();

    //// ����� "����������"
    //introduction(mainCharacter);

    //// ����� "������"
    //prologue(mainCharacter);

    //// ������� ��������� �������
    //Location emerdealLocation("�.��������", "����� ������������� ������������� ����������� ��� �����������, �� �������� � ������� �� ������������ ������������ ���� � ��� ������������.\n�������� - �����, ��� ���������� ������� �������, � ������ �������� ������� �������� ����� ������������.");

    //// ��������� ������� �����������
    //createEmerdealNPC(emerdealLocation, mainCharacter);

    //// ������ ���������� ���
    //combatTraining(mainCharacter);

    //chapter_one(mainCharacter);

    //chapter_two(mainCharacter);

    //chapter_final(mainCharacter);


    Weapon sword("������� ���", 10, 30);
    Magic magic("�������� ���", 30, 30);
    Character mainCharacter("Shichi", 500, 500, 500, &sword, &magic, "����");
    Demon darklord("�����-��������", 500, 500, 500);

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