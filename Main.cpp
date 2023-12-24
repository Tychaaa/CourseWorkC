#include <iostream>
#include <Windows.h>

#include "Location.h"
#include "NPC.h"

using namespace std;

int main() {
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Создаем объекты
    Location town("г.Барнаул", "Маленький городок, в котором наш герой начинает свое приключение");
    Location forest("АлтГТУ", "Темный лес... Первое препятствие, которое должен преодолеть наш герой перед становлением легендой ");

    NPC guide("Тьютор Санечка", "Санечка первый человек которого вы встретили в этом новом для вас мире\nОн приветствует вас своей доброй улыбкой");
    NPC artem("Артёмка", "На данный момент совершенно не знакомый вам человек,\nно в будущем ваш верный соратник и друг");
    NPC vasya("Вася", "Человек, на первый взгялд показавшийся вам другом.\nНо так ли это?");

    // Добавляем объект в локацию
    town.addInteractiveObject(&guide);
    town.addInteractiveObject(&artem);

    // Запускаем игру
    town.onEnter();

    forest.addInteractiveObject(&artem);
    forest.addInteractiveObject(&vasya);

    forest.onEnter();

    return 0;
}