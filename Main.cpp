#include <iostream>
#include <Windows.h>

#include "Location.h"
#include "NPC.h"

using namespace std;

int main() {
    // ������ ������� ���� � �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������� �������
    Location town("�.�������", "��������� �������, � ������� ��� ����� �������� ���� �����������");
    Location forest("������", "������ ���... ������ �����������, ������� ������ ���������� ��� ����� ����� ������������ �������� ");

    NPC guide("������ �������", "������� ������ ������� �������� �� ��������� � ���� ����� ��� ��� ����\n�� ������������ ��� ����� ������ �������");
    NPC artem("������", "�� ������ ������ ���������� �� �������� ��� �������,\n�� � ������� ��� ������ �������� � ����");
    NPC vasya("����", "�������, �� ������ ������ ������������ ��� ������.\n�� ��� �� ���?");

    // ��������� ������ � �������
    town.addInteractiveObject(&guide);
    town.addInteractiveObject(&artem);

    // ��������� ����
    town.onEnter();

    forest.addInteractiveObject(&artem);
    forest.addInteractiveObject(&vasya);

    forest.onEnter();

    return 0;
}