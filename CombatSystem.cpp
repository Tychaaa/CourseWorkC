#include "CombatSystem.h"

// ���������� � ���
void CombatSystem::displayTrainingInstructions()
{
    cout << "����� ���������� � ������������� ���!" << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "���������� �� ������ �������:" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "- ��� ���������� ����������: ������� ��� ���, ����� ��� ����������." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "- �������� ����� ��������:" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "   - ������� '1', ����� ������������ ������." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "   - ������� '2', ����� ������������ �����." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "   - ������� '3', ����� ���������� ���." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "   - ����� ������ ����� - �������� ������." << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "�������� �������������:" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "   - ��������: ������� ������� ��������� ��� ���������." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "   - ������������: ����������, �������� �� ����� � ������ (+��������������)." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "   - ����: ������, ����������� ��� ���������� ���� (+��������������)." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "   - ����� ������� ���� ����� ���������� �������������� ������ � �����." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "   - ���� �������������� �����, �������������� ���������� - ������." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "   - �������������� ������������ � ����: ������� ����������������� ����� ������� ����." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "������ ����� � ����������!" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "\n������� Enter, ����� ����������...";
    cin.ignore();
    cin.get();
}

// ������ ����: ����������� ��������� �������������� ������ � ����������, ����� ������������ ���
void CombatSystem::startGame(Character& player, Character& enemy)
{
    isTraining = false;
    // ���������� ��������� ������������� ������ � �����
    prevMaxPlayerHealth = player.getHealth();
    prevMaxPlayerStamina = player.getStamina();
    prevMaxPlayerMana = player.getMana();

    //������ ���
    initiateCombat(player, enemy);
}

// ������ �������������� ���
void CombatSystem::startGameTraining(Character& player, Character& enemy)
{
    isTraining = true;
    // ���������� ��������� ������������� ������ � �����
    prevMaxPlayerHealth = player.getHealth();
    prevMaxPlayerStamina = player.getStamina();
    prevMaxPlayerMana = player.getMana();

    displayTrainingInstructions();
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

        enemyTurn(player, enemy);

        displayCharacterInfo(player, enemy);
    }
}

// ��� ������: ����� �����, ������ ������, ���������� ���������������� ��������
void CombatSystem::playerTurn(Character& player, Character& enemy)
{
    while (true)
    {
        cout << "\n�������� �������� ��� �����:" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "1. ��������� � ������� " << player.getWeapon()->getName() << " (dmg: " << player.getWeapon()->getDamage() << "  stm : -" << player.getWeapon()->getCost() << ")\n";
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "2. ������������ ����� " << player.getMagic()->getName() << " (dmg: " << player.getMagic()->getDamage() << "  mana: -" << player.getMagic()->getCost() << ")\n";
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "3. ���������� ���\n";
        this_thread::sleep_for(chrono::milliseconds(100));

        cout << "\n���� ��������: ";

        int choice;
        // �������� ������� ������ ����� ����
        while (!(cin >> choice))
        {
            // ������� ������ �����
            cin.clear();
            // ������������� ���������� �������� � ������ �����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\n���� ��������: ";
        }

        cout << endl;

        if (choice == 1)
        {
            if (player.getStamina() < player.getWeapon()->getCost())
            {
                Screen::displayCharacterByCharacter("�� ������� �������� ��� ������������� " + player.getWeapon()->getName() + ".\n");
                continue;
            }

            player.attackWeapon(enemy);
            break;
        }
        else if (choice == 2)
        {
            if (player.getMana() < player.getMagic()->getCost())
            {
                Screen::displayCharacterByCharacter("�� ������� �������� ��� ������������� " + player.getMagic()->getName() + ".\n");
                continue;
            }

            player.castSpell(enemy);
            break;
        }
        else if (choice == 3)
        {
            Screen::displayCharacterByCharacter(player.getName() + " �������� ���������.\n");
            break;
        }
        else
        {
            cout << "������!" << std::endl;
            break;
        }
    }
}

// ��� ����������
void CombatSystem::enemyTurn(Character& player, Character& enemy)
{
    enemy.attack(player);
}

// �������� �� ������: �������� ������� ������ ��� ��������� ������ � ����������
bool CombatSystem::checkVictory(Character& player, Character& enemy)
{
    if (player.getHealth() <= 0)
    {
        if (isTraining) 
        {
            cout << "\n������... ������� ������ ���������� �� �����. ���� ����� ����� �����������, �� ���-�� ������ ���� ��� �������..." << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "\n��������� �������������� ���.\n" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));

            // �������������� �������� ��������, ������������ � ���� ������
            restoreCharacterStats(player);

            //��������� ��� ������������
            return true;
        }
        cout << "\n������... ������� ������ ���������� �� �����. ���� ����� ����� �����������, �� ���-�� ������ ���� ��� �������..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "������ ����� �������� ������������ �����. ����� ����� �����������, ������ �� ������� ����� �����." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "�����, ������ ����� ���������� �������, ���������, ��� ��� ���� ��������. �� ���� �������, �������, �������..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));

        // �������������� �������� ��������, ������������ � ���� ������
        player.setMaxHealth(player.getMaxHealth() * 1.2); // ����������� ������������ �������� � 1.2
        player.setMaxStamina(player.getMaxStamina() * 1.2); // ����������� ������������ ������������ � 1.2
        player.setMaxMana(player.getMaxMana() * 1.2); // ����������� ������������ ������������ � 1.2
        playerGetBonus = true;

        // �������������� �������� ��������, ������������ � ���� ������
        restoreCharacterStats(player);

        // �������������� �������� ��������, ������������ � ���� ����������
        restoreCharacterStats(enemy);

        // ���������� ��� � ������������ ����������
        initiateCombat(player, enemy);

        return true; // ���������� true, ����� ��� ��������������
    }
    else if (enemy.getHealth() <= 0)
    {
        cout << "\n��� ��������! ����� �������, �� ��� ������� �������. �� �����, �� ��������� ������� ����������." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        if (playerGetBonus)
        {
            cout << "������, � ����� ������, �� ���������, ��� ���� ������ ���, ������� �� �������, ��������." << std::endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            player.setMaxHealth(prevMaxPlayerHealth);
            player.setMaxStamina(prevMaxPlayerStamina);
            player.setMaxMana(prevMaxPlayerMana);
        }

        // �������������� �������� ��������, ������������ � ���� ������
        restoreCharacterStats(player);

        cout << "������ �������� ����� ����. �������� ������ ��������� ��� ����, ��� ���� ���������� �����." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "����: " << player.getExperience() << " (+" << enemy.getExperience() << ")" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        player.setExperience(enemy.getExperience());

        return true;
    }
    return false;
}

// �������������� �������� ��������, ������������ � ���� ������
void CombatSystem::restoreCharacterStats(Character& character) {
    character.setHealth(character.getMaxHealth());
    character.setStamina(character.getMaxStamina());
    character.setMana(character.getMaxMana());
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
    cout << "| ������������: " << setw(4) << player.getStamina() << "(+" << player.regenerateStamina() << ")" << "| ������������: " << setw(4) << enemy.getStamina() << "(+" << enemy.regenerateStamina() << ")" << "|" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "| ����: " << setw(12) << player.getMana() << "(+" << player.regenerateMana() << ")" << "| ����: " << setw(12) << enemy.getMana() << "(+" << enemy.regenerateMana() << ")" << "|" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "+------------------------+------------------------+" << endl;
}
