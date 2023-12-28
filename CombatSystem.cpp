#include "CombatSystem.h"

// Запуск игры: сохраняются начальные характеристики игрока и противника, затем инициируется бой
void CombatSystem::startGame(Character& player, Character& enemy)
{
    // Сохранение начальных характеристик игрока и врага
    prevMaxPlayerHealth = player.getHealth();
    prevMaxPlayerStamina = player.getStamina();
    prevMaxPlayerMana = player.getMana();

    //Запуск боя
    initiateCombat(player, enemy);
}

// Начало боя: вывод информации, управление ходами игрока и противника
void CombatSystem::initiateCombat(Character& player, Character& enemy)
{
    cout << "Бой начинается!" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    displayCharacterInfo(player, enemy);

    // После вывода информации нужно вызвать методы для ходов игрока и противника
    while (!checkVictory(player, enemy))
    {
        playerTurn(player, enemy);
        if (checkVictory(player, enemy)) break;
        enemyTurn(enemy, player);
        applyStatusEffects(player, enemy);
        displayCharacterInfo(player, enemy);
    }
}

// Ход игрока: вывод опций, чтение выбора, выполнение соответствующего действия
void CombatSystem::playerTurn(Character& player, Character& enemy)
{
    cout << "Выберите действие для героя:" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "1. Атаковать мечом (dmg: " << player.getWeapon()->getDamage() << "  stm: -" << player.getWeapon()->getCost() << ")\n";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "2. Использовать магию (dmg: " << player.getMagic()->getDamage() << "  mana: -" << player.getMagic()->getCost() << ")\n";
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
        cout << "Промах!" << std::endl;
    }
}

// Ход противника
void CombatSystem::enemyTurn(Character& enemy, Character& player) {
    enemy.attack(player);
}

// Проверка на победу: проверка условий победы или поражения игрока и противника
bool CombatSystem::checkVictory(Character& player, Character& enemy)
{
    if (player.getHealth() <= 0)
    {
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
        cout << "Бой закончен! Герой победил, но его дыхание тяжелое. Он устал, но чувствует чувство облегчения." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Теперь, в свете победы, он чувствует, что этот особый дар, который он получил, исчезает." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(1000));

        // Восстановление значений здоровья, выносливости и маны игрока
        player.setMaxHealth(prevMaxPlayerHealth);
        player.setMaxStamina(prevMaxPlayerStamina);
        player.setMaxMana(prevMaxPlayerMana);
        player.setHealth(player.getMaxHealth());
        player.setStamina(player.getMaxStamina());
        player.setMana(player.getMaxMana());

        cout << "Победа приносит новый опыт. Ощущение победы наполняет его душу, его путь становится яснее." << std::endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "Опыт: " << player.getExperience() << " + " << enemy.getExperience();
        this_thread::sleep_for(chrono::milliseconds(1000));

        player.setExperience(enemy.getExperience());

        return true;
    }
    return false;
}

// Применение статусных эффектов : восстановление стамины и маны для игрока и противника
void CombatSystem::applyStatusEffects(Character& character, Character& enemy)
{
    character.regenerateStamina();
    character.regenerateMana();
    enemy.regenerateStamina();
    enemy.regenerateMana();
}

// Вывод информации о персонажах на экран
void CombatSystem::displayCharacterInfo(Character& player, Character& enemy)
{
    std::cout << "+----------------------+----------------------+" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "| Информация о Герое:  | Информация о Враге:  |" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "+----------------------+----------------------+" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "| Здоровье: " << std::setw(11) << player.getHealth() << "| Здоровье: " << std::setw(11) << enemy.getHealth() << "|" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "| Выносливость: " << std::setw(7) << player.getStamina() << "| Выносливость: " << std::setw(7) << enemy.getStamina() << "|" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "| Мана: " << std::setw(15) << player.getMana() << "| Мана: " << std::setw(15) << enemy.getMana() << "|" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "+----------------------+----------------------+" << std::endl;
}
