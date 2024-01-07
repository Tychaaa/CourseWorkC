#include "CombatSystem.h"

void CombatSystem::displayTrainingInstructions() {
    cout << "Добро пожаловать в тренировочный бой!" << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Инструкции по боевой системе:" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "- Бой происходит поочередно: сначала ваш ход, затем ход противника." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "- Выберите номер действия:" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "   - Введите '1', чтобы использовать оружие." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "   - Введите '2', чтобы использовать магию." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "   - Любая другая цифра - пропустить ход." << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Карточки характеристик:" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "   - Здоровье: текущий уровень жизненных сил персонажа." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "   - Выносливость: показатель, влияющий на атаки и защиту (+восстановление)." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "   - Мана: ресурс, необходимый для магических атак (+восстановление)." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "   - После каждого хода будут отображены характеристики игрока и врага." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "   - Ваши характеристики слева, характеристики противника - справа." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "   - Восстановление выносливости и маны: ресурсы восстанавливаются после каждого хода." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Желаем удачи в тренировке!" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
}

// Запуск игры: сохраняются начальные характеристики игрока и противника, затем инициируется бой
void CombatSystem::startGame(Character& player, Character& enemy)
{
    isTraining = false;
    // Сохранение начальных характеристик игрока и врага
    prevMaxPlayerHealth = player.getHealth();
    prevMaxPlayerStamina = player.getStamina();
    prevMaxPlayerMana = player.getMana();

    //Запуск боя
    initiateCombat(player, enemy);
}

// Запуск игры: сохраняются начальные характеристики игрока и противника, затем инициируется бой
void CombatSystem::startGameTraining(Character& player, Character& enemy)
{
    isTraining = true;
    // Сохранение начальных характеристик игрока и врага
    prevMaxPlayerHealth = player.getHealth();
    prevMaxPlayerStamina = player.getStamina();
    prevMaxPlayerMana = player.getMana();

    displayTrainingInstructions();
    //Запуск боя
    initiateCombat(player, enemy);
}

// Начало боя: вывод информации, управление ходами игрока и противника
void CombatSystem::initiateCombat(Character& player, Character& enemy)
{
    Screen::displayText("\n\t\tБой начинается!");
    this_thread::sleep_for(chrono::milliseconds(1000));

    displayCharacterInfo(player, enemy);

    // После вывода информации нужно вызвать методы для ходов игрока и противника
    while (!checkVictory(player, enemy))
    {
        playerTurn(player, enemy);

        if (checkVictory(player, enemy)) 
            break;

        cout << endl;

        enemyTurn(player, enemy);

        applyStatusEffects(player, enemy);

        displayCharacterInfo(player, enemy);
    }
}

// Ход игрока: вывод опций, чтение выбора, выполнение соответствующего действия
void CombatSystem::playerTurn(Character& player, Character& enemy)
{
    while (true)
    {
        cout << "\nВыберите действие для героя:" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "1. Использовать " << player.getWeapon()->getName() << " (dmg: " << player.getWeapon()->getDamage() << "  stm : -" << player.getWeapon()->getCost() << ")\n";
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "2. Использовать " << player.getMagic()->getName() << " (dmg: " << player.getMagic()->getDamage() << "  mana: -" << player.getMagic()->getCost() << ")\n";
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "3. Пропустить ход\n";
        this_thread::sleep_for(chrono::milliseconds(100));

        cout << "\nВаше действие: ";


        int choice;
        cin >> choice;

        cout << endl;

        if (choice == 1)
        {
            if (player.getStamina() < player.getWeapon()->getCost())
            {
                Screen::displayCharacterByCharacter("Вы слишком истощены для использования " + player.getWeapon()->getName() + ".\n");
                continue;
            }

            player.attackWeapon(enemy);
            break;
        }
        else if (choice == 2)
        {
            if (player.getMana() < player.getMagic()->getCost())
            {
                Screen::displayCharacterByCharacter("Вы слишком истощены для использования " + player.getMagic()->getName() + ".\n");
                continue;
            }

            player.castSpell(enemy);
            break;
        }
        else if (choice == 3)
        {
            Screen::displayCharacterByCharacter(player.getName() + " начинает отступать.\n");
            break;
        }
        else
        {
            cout << "Промах!" << std::endl;
            break;
        }
    }
}

// Ход противника
void CombatSystem::enemyTurn(Character& player, Character& enemy) {
    enemy.attack(player);
}

// Проверка на победу: проверка условий победы или поражения игрока и противника
bool CombatSystem::checkVictory(Character& player, Character& enemy)
{
    bool playerGetBonus = false;
    if (player.getHealth() <= 0)
    {
        if (isTraining) {
            cout << "Смерть... горькая тишина опустилась на битву. Тело героя лежит бездыханное, но что-то внутри него еще борется..." << std::endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "Окончание тренировочного боя." << std::endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            //Рализация без воскрешщения
            return true;
        }
        cout << "Смерть... горькая тишина опустилась на битву. Тело героя лежит бездыханное, но что-то внутри него еще борется..." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Слабый пульс начинает пульсировать вновь. Глаза героя открываются, словно он получил новую жизнь." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Герой, смутно помня предыдущие события, чувствует, что его сила возросла. Он стал сильнее, быстрее, живучее..." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));

        // Восстановление значений здоровья, выносливости и маны игрока
        player.setMaxHealth(player.getMaxHealth() * 1.2); // Увеличиваем максимальное здоровье в 1.2
        player.setMaxStamina(player.getMaxStamina() * 1.2); // Увеличиваем максимальную выносливость в 1.2
        player.setMaxMana(player.getMaxMana() * 1.2); // Увеличиваем максимальную выносливость в 1.2
        player.setHealth(player.getMaxHealth());
        player.setStamina(player.getMaxStamina());
        player.setMana(player.getMaxMana());
        playerGetBonus = true;

        // Восстановление значений здоровья, выносливости и маны противника
        enemy.setHealth(enemy.getMaxHealth());
        enemy.setStamina(enemy.getMaxStamina());
        enemy.setMana(enemy.getMaxMana());

        // Перезапуск боя с сохраненными значениями
        initiateCombat(player, enemy);
        return true; // Возвращаем true, чтобы бой перезапустился
    }
    else if (enemy.getHealth() <= 0)
    {
        cout << "\nБой закончен! Герой победил, но его дыхание тяжелое. Он устал, но чувствует чувство облегчения." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        if (playerGetBonus)
        {
            cout << "Теперь, в свете победы, он чувствует, что этот особый дар, который он получил, исчезает." << std::endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            player.setMaxHealth(prevMaxPlayerHealth);
            player.setMaxStamina(prevMaxPlayerStamina);
            player.setMaxMana(prevMaxPlayerMana);
        }
        // Восстановление значений здоровья, выносливости и маны игрока
        player.setHealth(player.getMaxHealth());
        player.setStamina(player.getMaxStamina());
        player.setMana(player.getMaxMana());

        cout << "Победа приносит новый опыт. Ощущение победы наполняет его душу, его путь становится яснее." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Опыт: " << player.getExperience() << " (+" << enemy.getExperience() << ")" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        player.setExperience(enemy.getExperience());

        return true;
    }
    return false;
}

// Применение статусных эффектов : восстановление стамины и маны для игрока и противника
void CombatSystem::applyStatusEffects(Character& player, Character& enemy)
{
    player.regenerateStamina();
    player.regenerateMana();
    enemy.regenerateStamina();
    enemy.regenerateMana();
}

// Вывод информации о персонажах на экран
void CombatSystem::displayCharacterInfo(Character& player, Character& enemy)
{
    cout << "\n+------------------------+------------------------+" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "| Информация о Герое:    | Информация о Враге:    |" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "+------------------------+------------------------+" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "| Здоровье: " << setw(13) << player.getHealth() << "| Здоровье: " << setw(13) << enemy.getHealth() << "|" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "| Выносливость: " << setw(4) << player.getStamina() << "(+" << player.regenerateStamina() << ")" << "| Выносливость: " << setw(4) << enemy.getStamina() << "(+" << enemy.regenerateStamina() << ")" << "|" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "| Мана: " << setw(12) << player.getMana() << "(+" << player.regenerateMana() << ")" << "| Мана: " << setw(12) << enemy.getMana() << "(+" << enemy.regenerateMana() << ")" << "|" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "+------------------------+------------------------+" << endl;
}
