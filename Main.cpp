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

    // ����� 1
    chapter_one(mainCharacter);

    // ����� 2
    chapter_two(mainCharacter);

    // ����� "�����"
    chapter_final(mainCharacter);

    // ��������� �����
    displayFinalCredits();

    return 0;
}