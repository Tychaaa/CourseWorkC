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

// ���������� ������ CombatSystem
class CombatSystem
{
private:
    bool isTraining; // ��������� ��� ����������� �������������� ���
    bool playerGetBonus = false; // ���������� ��� ����������� ������

    // ���������� ��� ���������� ���������� ������������� ������
    int prevMaxPlayerHealth;
    int prevMaxPlayerStamina;
    int prevMaxPlayerMana;

public:
    // ���������� � ���
    void displayTrainingInstructions();

    // ������ ����
    void startGame(Character& player, Character& enemy);

    // ������ �������������� ���
    void startGameTraining(Character& player, Character& enemy);

    // ������ ���
    void initiateCombat(Character& player, Character& enemy); 

    // ��� ������
    void playerTurn(Character& player, Character& enemy); 

    // ��� ����������
    void enemyTurn(Character& enemy, Character& player); 

    // �������� �� ������
    bool checkVictory(Character& player, Character& enemy);

    // �������������� �������� ��������, ������������ � ���� ������
    void restoreCharacterStats(Character& character);

    // ����������� ���������� � ����������
    void displayCharacterInfo(Character& player, Character& enemy); 
};