#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

#include "Location.h"
#include "NPC.h"
#include "Arsenal.h"
#include "Character.h"
#include "Magic.h"
#include "Weapon.h"
#include "Monster.h"
#include "Bestiary.h"
#include "Function.h"
#include "CombatSystem.h"


using namespace std;


int main() {
    // ������ ������� ���� � �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������������� ��������� ���� �������
    SetConsoleTitle(L"Blades of Destiny");


    //Character mainCharacter = createMainCharacter();

    //introduction(mainCharacter);


        // �������� ������ � �����
    Weapon sword("���", 20, 15);
    Magic fireball("�������� ���", 30, 25);

        // �������� ����������
    Character player("shichi", 100, 100, 50, &sword, &fireball, "����");
    Wolf enemy("����", 80, 80, 30);

    // �������� ���������� ������� ���
    CombatSystem combatSystem;

    // ������������� ���
    combatSystem.initiateCombat(player, enemy);

    return 0;





    return 0;
}