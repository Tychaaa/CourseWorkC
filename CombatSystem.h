#pragma once

#include "Character.h"

class CombatSystem
{
public:
    void initiateCombat(Character& player, Character& enemy);
    void playerTurn(Character& player, Character& enemy);
    void enemyTurn(Character& enemy, Character& player);
    bool checkVictory(Character& player, Character& enemy);
    void applyStatusEffects(Character& character);
};

