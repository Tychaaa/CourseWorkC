#pragma once
#define ESCAPE 27
#define NOMINMAX

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>  // Для использования функции exit()
#include <utility>  // Для использования std::pair
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

// Устанавливаем параметры консоли
void consoleSetting();

// Функция для вывода заставки игры (медленно)
void gameTitleSlow();

// Функция для вывода заставки игры
void gameTitle();

// Функция для вывода заставки разработчиков
void prodTitle();

// Функция для вывода главного меню игры
void mainMenu();

// Вступление
void introduction(Character& character);

// Глава "Пролог"
void prologue(Character& character);

// Обучение бою
void combatTraining(Character& character);

// Глава 1
void chapter_one(Character& character);

// Глава 2
void chapter_two(Character& character);

// Глава "Финал"
void chapter_final(Character& character);

// Функция для выбора концовки игры
void chooseGameEnding(Character& character);

// Функция для "хорошей" концовки
void goodEnding(Character& character);

// Функция для "плохой" концовки
void badEnding(Character& character);

// Функция для создания оружия и магии в зависимости от класса
pair<Weapon*, Magic*> createEquipment(string& className);

// Функция для создания главного героя
Character createMainCharacter();

// Заполнить г.Эмердейл неигровыми персонажами и посещение локации
void createEmerdealNPC(Location emerdeal, Character character);