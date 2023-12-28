#include "CombatSystem.h"

// ������ ����: ����������� ��������� �������������� ������ � ����������, ����� ������������ ���
void CombatSystem::startGame(Character& player, Character& enemy)
{
    // ���������� ��������� ������������� ������ � �����
    prevMaxPlayerHealth = player.getHealth();
    prevMaxPlayerStamina = player.getStamina();
    prevMaxPlayerMana = player.getMana();

    //������ ���
    initiateCombat(player, enemy);
}

// ������ ���: ����� ����������, ���������� ������ ������ � ����������
void CombatSystem::initiateCombat(Character& player, Character& enemy)
{
    cout << "��� ����������!" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    displayCharacterInfo(player, enemy);

    // ����� ������ ���������� ����� ������� ������ ��� ����� ������ � ����������
    while (!checkVictory(player, enemy))
    {
        playerTurn(player, enemy);
        if (checkVictory(player, enemy)) break;
        enemyTurn(enemy, player);
        applyStatusEffects(player, enemy);
        displayCharacterInfo(player, enemy);
    }
}

// ��� ������: ����� �����, ������ ������, ���������� ���������������� ��������
void CombatSystem::playerTurn(Character& player, Character& enemy)
{
    cout << "�������� �������� ��� �����:" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "1. ��������� ����� (dmg: " << player.getWeapon()->getDamage() << "  stm: -" << player.getWeapon()->getCost() << ")\n";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "2. ������������ ����� (dmg: " << player.getMagic()->getDamage() << "  mana: -" << player.getMagic()->getCost() << ")\n";
    this_thread::sleep_for(chrono::milliseconds(100));

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        player.attack(enemy);
    }
    else if (choice == 2) {
        player.castSpell(enemy);
    }
    else {
        cout << "������!" << std::endl;
    }
}

// ��� ����������
void CombatSystem::enemyTurn(Character& enemy, Character& player) {
    enemy.attack(player);
}

// �������� �� ������: �������� ������� ������ ��� ��������� ������ � ����������
bool CombatSystem::checkVictory(Character& player, Character& enemy)
{
    if (player.getHealth() <= 0)
    {
        cout << "������... ������� ������ ���������� �� �����. ���� ����� ����� �����������, �� ���-�� ������ ���� ��� �������..." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "������ ����� �������� ������������ �����. ����� ����� �����������, ������ �� ������� ����� �����." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "�����, ������ ����� ���������� �������, ���������, ��� ��� ���� ��������. �� ���� �������, �������, �������..." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));

        // �������������� �������� ��������, ������������ � ���� ������
        player.setMaxHealth(player.getMaxHealth() * 1.2); // ����������� ������������ �������� � 1.2
        player.setMaxStamina(player.getMaxStamina() * 1.2); // ����������� ������������ ������������ � 1.2
        player.setMaxMana(player.getMaxMana() * 1.2); // ����������� ������������ ������������ � 1.2
        player.setHealth(player.getMaxHealth());
        player.setStamina(player.getMaxStamina());
        player.setMana(player.getMaxMana());

        // �������������� �������� ��������, ������������ � ���� ����������
        enemy.setHealth(enemy.getMaxHealth());
        enemy.setStamina(enemy.getMaxStamina());
        enemy.setMana(enemy.getMaxMana());

        // ���������� ��� � ������������ ����������
        initiateCombat(player, enemy);
        return true; // ���������� true, ����� ��� ��������������
    }
    else if (enemy.getHealth() <= 0)
    {
        cout << "��� ��������! ����� �������, �� ��� ������� �������. �� �����, �� ��������� ������� ����������." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "������, � ����� ������, �� ���������, ��� ���� ������ ���, ������� �� �������, ��������." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));

        // �������������� �������� ��������, ������������ � ���� ������
        player.setMaxHealth(prevMaxPlayerHealth);
        player.setMaxStamina(prevMaxPlayerStamina);
        player.setMaxMana(prevMaxPlayerMana);
        player.setHealth(player.getMaxHealth());
        player.setStamina(player.getMaxStamina());
        player.setMana(player.getMaxMana());

        cout << "������ �������� ����� ����. �������� ������ ��������� ��� ����, ��� ���� ���������� �����." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "����: " << player.getExperience() << " + " << enemy.getExperience();
        this_thread::sleep_for(chrono::milliseconds(1000));

        player.setExperience(enemy.getExperience());

        return true;
    }
    return false;
}

// ���������� ��������� �������� : �������������� ������� � ���� ��� ������ � ����������
void CombatSystem::applyStatusEffects(Character& character, Character& enemy)
{
    character.regenerateStamina();
    character.regenerateMana();
    enemy.regenerateStamina();
    enemy.regenerateMana();
}

// ����� ���������� � ���������� �� �����
void CombatSystem::displayCharacterInfo(Character& player, Character& enemy)
{
    std::cout << "+----------------------+----------------------+" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "| ���������� � �����:  | ���������� � �����:  |" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "+----------------------+----------------------+" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "| ��������: " << std::setw(11) << player.getHealth() << "| ��������: " << std::setw(11) << enemy.getHealth() << "|" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "| ������������: " << std::setw(7) << player.getStamina() << "| ������������: " << std::setw(7) << enemy.getStamina() << "|" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "| ����: " << std::setw(15) << player.getMana() << "| ����: " << std::setw(15) << enemy.getMana() << "|" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "+----------------------+----------------------+" << std::endl;
}
