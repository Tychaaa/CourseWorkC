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

    NPC guide("�������", "����� ���������� � ��� ���� � �����!");

    // ��������� ������ � �������
    town.addInteractiveObject(&guide);

    // ��������� ����
    town.onEnter();

    forest.addInteractiveObject(&guide);

    forest.onEnter();

    return 0;
}