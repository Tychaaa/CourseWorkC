#include "CombatSystem.h"

void CombatSystem::initiateCombat(Character& player, Character& enemy) {
    // ������ ������ ���
}

void CombatSystem::playerTurn(Character& player, Character& enemy) {
    // ������ ���� ������
    // ����� ������������ ��� ������������ ��� ��� ������ �������� � ��� ����������
}

void CombatSystem::enemyTurn(Character& enemy, Character& player) {
    // ������ ���� ����������
    // ��������, ��� �����
    if (enemy.getHealth() > 0) {
        enemy.attack(player); // ������� ������� - ���� ������ ������� ������
    }
}

bool CombatSystem::checkVictory(Character& player, Character& enemy) {
    // �������� ������� ������
    if (player.getHealth() <= 0) {
        cout << "���� �������!" << endl;
        return true;
    }
    else if (enemy.getHealth() <= 0) {
        cout << "����� �������!" << endl;
        return true;
    }
    return false;
}

void CombatSystem::applyStatusEffects(Character& character) {
    // ���������� ��������� ��������
    // ��������, ���������� ������������ ��� ���� ����� ������� ����
}