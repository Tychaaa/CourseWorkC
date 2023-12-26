#pragma once
#include "Character.h"
#include "Weapon.h"
#include "Magic.h"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

class CombatSystem
{
public:
    static void initiateCombat(Character& player, Character& enemy);
    static void playerTurn(Character& player, Character& enemy);
    static void enemyTurn(Character& enemy, Character& player);
    static bool checkVictory(Character& player, Character& enemy);
    static void applyStatusEffects(Character& character, Character& enemy);
    static void displayCharacterInfo(Character& player, Character& enemy);
};
