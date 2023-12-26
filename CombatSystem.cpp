#include "CombatSystem.h"

void CombatSystem::initiateCombat(Character& player, Character& enemy) {
    std::cout << "��� ����������!" << std::endl;
    displayCharacterInfo(player, enemy);

    // ����� ������ ���������� ����� ������� ������ ��� ����� ������ � ����������
    while (!checkVictory(player, enemy)) {
        playerTurn(player, enemy);
        if (checkVictory(player, enemy)) break;
        enemyTurn(enemy, player);
        applyStatusEffects(player, enemy);
    }
}

void CombatSystem::playerTurn(Character& player, Character& enemy) {
    std::cout << "�������� �������� ��� �����:" << std::endl;
    std::cout << "1. ��������� ����� (dmg: " << player.getWeapon()->getDamage() << "  stm: -" << player.getWeapon()->getCost() << ")\n";
    std::cout << "2. ������������ ����� (dmg: " << player.getMagic()->getDamage() << "  mana: -" << player.getMagic()->getCost() << ")\n";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        player.attack(enemy);
    }
    else if (choice == 2) {
        player.castSpell(enemy);
    }
    else {
        std::cout << "������!" << std::endl;
    }
}

void CombatSystem::enemyTurn(Character& enemy, Character& player) {
    enemy.attack(player);
    displayCharacterInfo(player, enemy);
}

bool CombatSystem::checkVictory(Character& player, Character& enemy) {
    if (player.getHealth() <= 0) {
        std::cout << "���� �������!" << std::endl;
        return true;
    }
    else if (enemy.getHealth() <= 0) {
        std::cout << "����� �������!" << std::endl;
        return true;
    }
    return false;
}

void CombatSystem::applyStatusEffects(Character& character, Character& enemy) {
    character.regenerateStamina();
    character.regenerateMana();
    enemy.regenerateStamina();
    enemy.regenerateMana();
}

void CombatSystem::displayCharacterInfo(Character& player, Character& enemy) {
    std::cout << "+----------------------+----------------------+" << std::endl;
    std::cout << "| ���������� � �����:  | ���������� � �����:  |" << std::endl;
    std::cout << "+----------------------+----------------------+" << std::endl;
    std::cout << "| ��������: " << std::setw(11) << player.getHealth() << "| ��������: " << std::setw(11) << enemy.getHealth() << "|" << std::endl;
    std::cout << "| ������������: " << std::setw(7) << player.getStamina() << "| ������������: " << std::setw(7) << enemy.getStamina() << "|" << std::endl;
    std::cout << "| ����: " << std::setw(15) << player.getMana() << "| ����: " << std::setw(15) << enemy.getMana() << "|" << std::endl;
    std::cout << "+----------------------+----------------------+" << std::endl;
}