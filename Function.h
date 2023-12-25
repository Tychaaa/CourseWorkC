#pragma once
#define ESCAPE 27

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>  // ��� ������������� ������� exit()
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "Character.h"
#include "Weapon.h"
#include "Magic.h"

using namespace std;

// ������� ��� ������ �������� ����
void gameTitle();

// ������� ��� ������ �������� �������������
void prodTitle();

// ������� ��� ������ �������� ���� ����
void mainMenu();

// ������� ��� �������� �������� �����
Character createMainCharacter();