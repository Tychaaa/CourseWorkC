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
#include <limits>
#include <chrono>
#include <thread>
#include <iomanip>
#include <random>

#include "Character.h"
#include "Location.h"
#include "NPC.h"
#include "Weapon.h"
#include "Magic.h"
#include "Screen.h"
#include "CombatSystem.h"
#include "Bestiary.h"

using namespace std;

// ������������� ��������� �������
void consoleSetting();

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

// ����� 1
void chapter_one(Character& character);

// ����� 2
void chapter_two(Character& character);

// ����� "�����"
void chapter_final(Character& character);

// ������� ��� ������ �������� ����
void chooseGameEnding(Character& character);

// ������� ��� "�������" ��������
void goodEnding(Character& character);

// ������� ��� "������" ��������
void badEnding(Character& character);

// ������� ��� �������� ������ � ����� � ����������� �� ������
pair<Weapon*, Magic*> createEquipment(string& className);

// ������� ��� �������� �������� �����
Character createMainCharacter();

// ��������� �.�������� ���������� ����������� � ��������� �������
void createEmerdealNPC(Location emerdeal, Character character);