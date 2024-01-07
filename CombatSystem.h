#pragma once
#include "Character.h"
#include "Weapon.h"
#include "Magic.h"
#include "Screen.h"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;

// Объявление класса CombatSystem
class CombatSystem
{
private:
    bool isTraining; // Пременная для определение тренировочного боя

    // Переменные для сохранения предыдущих характеристик игрока
    int prevMaxPlayerHealth;
    int prevMaxPlayerStamina;
    int prevMaxPlayerMana;

public:
    // Инструкция к бою
    void displayTrainingInstructions();

    // Запуск игры
    void startGame(Character& player, Character& enemy);

    // Запуск тренировочного боя
    void startGameTraining(Character& player, Character& enemy);

    // Начало боя
    void initiateCombat(Character& player, Character& enemy); 

    // Ход игрока
    void playerTurn(Character& player, Character& enemy); 

    // Ход противника
    void enemyTurn(Character& enemy, Character& player); 

    // Проверка на победу
    bool checkVictory(Character& player, Character& enemy);

    // Отображение информации о персонажах
    void displayCharacterInfo(Character& player, Character& enemy); 
};