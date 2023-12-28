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
private:

    int prevMaxPlayerHealth;
    int prevMaxPlayerStamina;
    int prevMaxPlayerMana;

public:

    void startGame(Character& player, Character& enemy);
    void initiateCombat(Character& player, Character& enemy);
    void playerTurn(Character& player, Character& enemy);
    void enemyTurn(Character& enemy, Character& player);
    bool checkVictory(Character& player, Character& enemy);
    void applyStatusEffects(Character& character, Character& enemy);
    void displayCharacterInfo(Character& player, Character& enemy);
};
