#pragma once
#define ESCAPE 27
#define NOMINMAX

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>  // ��� ������������� ������� exit()
#include <utility>  // ��� ������������� std::pair
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>

#include "Character.h"
#include "Location.h"
#include "NPC.h"
#include "Weapon.h"
#include "Magic.h"
#include "Screen.h"

using namespace std;

// ������� ��� ������ �������� ���� (��������)
void gameTitleSlow();

// ������� ��� ������ �������� ����
void gameTitle();

// ������� ��� ������ �������� �������������
void prodTitle();

// ������� ��� ������ �������� ���� ����
void mainMenu();

// ����������
void introduction(Character& character);

// ����� "������"
void prologue(Character& character);

// �������� ���
void combatTraining(Character& character);

// ������� ��� �������� ������ � ����� � ����������� �� ������
pair<Weapon*, Magic*> createEquipment(string& className);

// ������� ��� �������� �������� �����
Character createMainCharacter();

// ��������� �.�������� ���������� �����������
void createEmerdealNPC(Location emerdeal, Character character);