#include <iostream>
#include <Windows.h>

#include "Location.h"
#include "NPC.h"
#include "Arsenal.h"
#include "Character.h"
#include "Magic.h"
#include "Weapon.h"
#include "Monster.h"
#include "Function.h"

using namespace std;

int main() {
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    prodTitle();

    gameTitle();

    mainMenu();

    // Создаем объекты
    Location town("г.Барнаул", "Маленький городок, в котором наш герой начинает свое приключение");
    Location forest("АлтГТУ", "Темный лес... Первое препятствие, которое должен преодолеть наш герой перед становлением легендой ");

    NPC guide("Тьютор Санечка", "Санечка первый человек, которого вы встретили в этом новом для вас мире\nОн приветствует вас своей доброй улыбкой");
    NPC artem("Артёмка", "На данный момент совершенно не знакомый вам человек,\nно в будущем ваш верный соратник и друг");
    NPC vasya("Вася", "Человек, на первый взгляд показавшийся вам другом.\nНо так ли это?");

    // Добавляем объект в локацию
    town.addInteractiveObject(&guide);
    town.addInteractiveObject(&artem);

    forest.addInteractiveObject(&artem);
    forest.addInteractiveObject(&vasya);

    // Запускаем игру
    while (true) {
        cout << "Выберите локацию (1 - г.Барнаул, 2 - АлтГТУ, 0 - Выйти из игры): ";
        char locationChoice = Input::getUserInput();

        switch (locationChoice) {
        case '1':
            town.onEnter();
            break;
        case '2':
            forest.onEnter();
            break;
        case '0':
            return 0;
        default:
            cout << "Неверный выбор. Пожалуйста, выберите существующий вариант." << endl;
            break;
        }
    }

    return 0;
}