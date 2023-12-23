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

    NPC guide("Санечка", "Добро пожаловать в мир меча и магии!");

    // Добавляем объект в локацию
    town.addInteractiveObject(&guide);

    // Запускаем игру
    town.onEnter();

    forest.addInteractiveObject(&guide);

    forest.onEnter();

    return 0;
}