#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

#include "Location.h"
#include "NPC.h"
#include "Arsenal.h"
#include "Character.h"
#include "Magic.h"
#include "Weapon.h"
#include "Monster.h"
#include "Bestiary.h"
#include "Function.h"
#include "CombatSystem.h"


using namespace std;


int main() {
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Устанавливаем заголовок окна консоли
    SetConsoleTitle(L"Blades of Destiny");

    //Главное меню
    mainMenu();

    // Создаем объект персонажа
    Character mainCharacter;

    // Глава "Вступление"
    introduction(mainCharacter);

    // Глава "Пролог"
    prologue(mainCharacter);

    // Создаем начальную локацию
    Location emerdealLocation("г.Эмердейл", "Город предоставляет разнообразные возможности для приключений, от торговли и заданий до исследования таинственных мест в его окрестностях.\nЭмердейл - место, где начинаются великие истории, и каждый приезжий ощущает волнение перед неизведанным.");

    // Заполняем локацию персонажами
    createEmerdealNPC(emerdealLocation);

    gameTitle();

    emerdealLocation.onEnter();

    return 0;
}