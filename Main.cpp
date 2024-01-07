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

    Weapon sword("������� ���", 10, 5);
    Magic magic("�������� ���", 30, 5);
    Character mainCharacter("����� ��������", 200, 100, 100, &sword, &magic, "����");
    Witch witch("������ �����", 200, 150, 150);
    CombatSystem fight;

    fight.startGame(mainCharacter, witch);

    return 0;
}