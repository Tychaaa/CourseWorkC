#include "CombatSystem.h"

void CombatSystem::initiateCombat(Character& player, Character& enemy) {
    // Логика начала боя
}

void CombatSystem::playerTurn(Character& player, Character& enemy) {
    // Логика хода игрока
    // Можно использовать ваш существующий код для выбора действия и его выполнения
}

void CombatSystem::enemyTurn(Character& enemy, Character& player) {
    // Логика хода противника
    // Например, для волка
    if (enemy.getHealth() > 0) {
        enemy.attack(player); // Простой вариант - волк всегда атакует игрока
    }
}

bool CombatSystem::checkVictory(Character& player, Character& enemy) {
    // Проверка условий победы
    if (player.getHealth() <= 0) {
        cout << "Волк победил!" << endl;
        return true;
    }
    else if (enemy.getHealth() <= 0) {
        cout << "Герой победил!" << endl;
        return true;
    }
    return false;
}

void CombatSystem::applyStatusEffects(Character& character) {
    // Применение статусных эффектов
    // Например, уменьшение выносливости или маны после каждого хода
}