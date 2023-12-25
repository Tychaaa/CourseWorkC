#pragma once
#include <iostream>
#include <Windows.h>
#pragma comment(lib, "winmm")
#include <vector>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

// Функция для вывода заставки игры
void gameTitle();

// Функция для вывода заставки разработчиков
void prodTitle();

// Функция для вывода главного меню игры
void mainMenu();