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

    // ������������� ��������� ���� �������
    SetConsoleTitle(L"Blades of Destiny");

    mainMenu();

    cout << "\n����� ���������� � ������������� ��� �����������!\n";
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "\n�� ��������� � ���������� ����, ������ ���� � ����������.\n";
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n������ ���, ��������� ��������, ������� ����� � ����� ���� ������� ��������������� �����.\n";
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n������, ����� ��� ��� ������ ���� �����������, ��� ����� ������� ������ �����.\n";
    this_thread::sleep_for(chrono::milliseconds(1500));

    // �������� � �������� �������� �����
    cout << "\n����������, �� ����������� ��� ��� ��������� ��������...\n";
    this_thread::sleep_for(chrono::milliseconds(2000));

    Character mainCharacter = createMainCharacter();

    cout << "\n������ �� ������ ������ ���� �����������! �����, " << mainCharacter.getName() << "!\n";
    this_thread::sleep_for(chrono::milliseconds(1500));

    // ������� ������� ������� ����� ������������
    cout << "\n������� Enter, ����� ����������...";
    cin.get();

    return 0;
}