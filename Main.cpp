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
    Character mainCharacter = createMainCharacter();

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

    chapter_final(mainCharacter);

    return 0;
}