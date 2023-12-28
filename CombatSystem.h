#pragma once
#include "Character.h"
#include "Weapon.h"
#include "Magic.h"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

// Объявление класса CombatSystem
class CombatSystem
{
private:
    // Переменные для сохранения предыдущих характеристик игрока
    int prevMaxPlayerHealth;
    int prevMaxPlayerStamina;
    int prevMaxPlayerMana;

public:
    // Объявление открытых методов класса CombatSystem
    void startGame(Character& player, Character& enemy); // Запуск игры
    void initiateCombat(Character& player, Character& enemy); // Начало боя
    void playerTurn(Character& player, Character& enemy); // Ход игрока
    void enemyTurn(Character& enemy, Character& player); // Ход противника
    bool checkVictory(Character& player, Character& enemy); // Проверка на победу
    void applyStatusEffects(Character& character, Character& enemy); // Применение эффектов
    void displayCharacterInfo(Character& player, Character& enemy); // Отображение информации о персонажах
};