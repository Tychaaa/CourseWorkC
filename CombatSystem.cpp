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
    Screen::displayText("\n\t\t��� ����������!");
    this_thread::sleep_for(chrono::milliseconds(1000));

    displayCharacterInfo(player, enemy);

    // ����� ������ ���������� ����� ������� ������ ��� ����� ������ � ����������
    while (!checkVictory(player, enemy))
    {
        playerTurn(player, enemy);

        if (checkVictory(player, enemy)) 
            break;

        cout << endl;

        enemyTurn(enemy, player);

        applyStatusEffects(player, enemy);

        displayCharacterInfo(player, enemy);
    }
}

// ��� ������: ����� �����, ������ ������, ���������� ���������������� ��������
void CombatSystem::playerTurn(Character& player, Character& enemy)
{
    cout << "\n�������� �������� ��� �����:" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "1. ������������ " << player.getWeapon()->getName() << " (dmg: " << player.getWeapon()->getDamage() << "  stm : -" << player.getWeapon()->getCost() << ")\n";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "2. ������������ "<< player.getMagic()->getName() <<" (dmg: " << player.getMagic()->getDamage() << "  mana: -" << player.getMagic()->getCost() << ")\n";
    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "\n���� ��������: ";

    int choice;
    cin >> choice;

    cout << endl;

    if (choice == 1) {
        player.attackWeapon(enemy);
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
    bool playerDefeat = false;
    if (player.getHealth() <= 0)
    {
        playerDefeat = true;
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
        cout << "\n��� ��������! ����� �������, �� ��� ������� �������. �� �����, �� ��������� ������� ����������." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        if (playerDefeat)
        {
            cout << "������, � ����� ������, �� ���������, ��� ���� ������ ���, ������� �� �������, ��������." << std::endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            player.setMaxHealth(prevMaxPlayerHealth);
            player.setMaxStamina(prevMaxPlayerStamina);
            player.setMaxMana(prevMaxPlayerMana);
        }
        // �������������� �������� ��������, ������������ � ���� ������
        player.setHealth(player.getMaxHealth());
        player.setStamina(player.getMaxStamina());
        player.setMana(player.getMaxMana());

        cout << "������ �������� ����� ����. �������� ������ ��������� ��� ����, ��� ���� ���������� �����." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "����: " << player.getExperience() << " (+" << enemy.getExperience() << ")" << endl;
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
    cout << "\n+------------------------+------------------------+" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "| ���������� � �����:    | ���������� � �����:    |" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "+------------------------+------------------------+" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "| ��������: " << setw(13) << player.getHealth() << "| ��������: " << setw(13) << enemy.getHealth() << "|" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "| ������������: " << setw(4) << player.getStamina() << "(+" << 10 + 10 * player.getLevel() << ")" << "| ������������: " << setw(4) << enemy.getStamina() << "(+" << 10 + 10 * enemy.getLevel() << ")" << "|" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "| ����: " << setw(12) << player.getMana() << "(+" << 10 + 10 * player.getLevel() << ")" << "| ����: " << setw(12) << enemy.getMana() << "(+" << 10 + 10 * enemy.getLevel() << ")" << "|" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "+------------------------+------------------------+" << endl;
}
