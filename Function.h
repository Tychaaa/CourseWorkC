#pragma once
#define ESCAPE 27

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>  // Для использования функции exit()
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "Character.h"
#include "Weapon.h"
#include "Magic.h"

using namespace std;

// Функция для вывода заставки игры
void gameTitle();

// Функция для вывода заставки разработчиков
void prodTitle();

// Функция для вывода главного меню игры
void mainMenu();

// Глава "Пролог"
void introduction(Character character);

// Функция для создания главного героя
Character createMainCharacter();