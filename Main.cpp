#include <iostream>
#include <Windows.h>

#include "Location.h"
#include "NPC.h"
#include "Arsenal.h"
#include "Character.h"
#include "Magic.h"
#include "Weapon.h"
#include "Monster.h"

using namespace std;

int main() {
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //// Создаем объекты
    //Location town("г.Барнаул", "Маленький городок, в котором наш герой начинает свое приключение");
    //Location forest("АлтГТУ", "Темный лес... Первое препятствие, которое должен преодолеть наш герой перед становлением легендой ");

    //NPC guide("Санечка", "Добро пожаловать в мир меча и магии!");

    //// Добавляем объект в локацию
    //town.addInteractiveObject(&guide);

    //// Запускаем игру
    //town.onEnter();

    //forest.addInteractiveObject(&guide);

    //forest.onEnter();

   // Создание оружия и магии
    //Weapon sword("Меч", 20, 5);
    //Magic fireball("Огненный шар", 30, 10);

    //// Создание персонажей
    //Character player("Герой", 100, 50, 50, &sword, &fireball);
    //Character enemy("Монстр", 80, 40, 20, nullptr, nullptr);

    //// Атака игрока и использование магии противника
    //player.attack(enemy);
    //enemy.castSpell(player);

    //// Вывод информации о состоянии игрока и врага
    //cout << "Состояние игрока:\n";
    //cout << "Здоровье: " << player.getHealth() << "\n";
    //cout << "Стамина: " << player.getStamina() << "\n";
    //cout << "Мана: " << player.getMana() << "\n";

    //cout << "\nСостояние врага:\n";
    //cout << "Здоровье: " << enemy.getHealth() << "\n";
    //cout << "Стамина: " << enemy.getStamina() << "\n";
    //cout << "Мана: " << enemy.getMana() << "\n";


    Weapon* sword = new Weapon("Меч", 20, 5);
    Magic* fireball = new Magic("Огненный шар", 30, 10);
    Character player("Герой", 100, 50, 50, sword, fireball);

    Weapon* fangs = new Weapon("Клыки", 15, 0);
    Magic* none = new Magic();
    Monster wolf("Волк", 80, 30, 0, fangs, none);

    while (player.getHealth() > 0 && wolf.getHealth() > 0) {
        cout << "Выберите действие для героя: \n";
        cout << "1. Атаковать мечом\n";
        cout << "2. Использовать магию\n";

        int choice;
        cin >> choice;

        if (choice == 1) {
            player.attack(*wolf.getWeapon()); // Атака мечом
        }
        else if (choice == 2) {
            player.castSpell(*wolf.getMagic()); // Использовать магию
        }
        else {
            cout << "Некорректный выбор. Попробуйте еще раз." << endl;
            continue; // Продолжить цикл, чтобы повторно запросить выбор действия
        }

        if (wolf.getHealth() <= 0) {
            cout << "Волк побежден!" << endl;
            break;
        }

        wolf.attack(player);

        if (player.getHealth() <= 0) {
            cout << "Герой побежден!" << endl;
            break;
        }

        cout << "Здоровье героя: " << player.getHealth() << " | Здоровье волка: " << wolf.getHealth() << endl;
    }

    delete sword;
    delete fireball;
    delete fangs;
    delete none;

    return 0;
}