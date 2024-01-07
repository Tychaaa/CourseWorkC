#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

#include "Arsenal.h"
#include "Bestiary.h"
#include "Character.h"
#include "CombatSystem.h"
#include "Function.h"
#include "Location.h"
#include "Magic.h"
#include "Monster.h"
#include "NPC.h"
#include "Weapon.h"

using namespace std;

int main() 
{
    // Устанавливаем параметры консоли
    consoleSetting();

    ////Главное меню
    //mainMenu();

    // Создаем объект персонажа
    //Character mainCharacter = createMainCharacter();

    //// Глава "Вступление"
    //introduction(mainCharacter);

    //// Глава "Пролог"
    //prologue(mainCharacter);

    //// Создаем начальную локацию
    //Location emerdealLocation("г.Эмердейл", "Город предоставляет разнообразные возможности для приключений, от торговли и заданий до исследования таинственных мест в его окрестностях.\nЭмердейл - место, где начинаются великие истории, и каждый приезжий ощущает волнение перед неизведанным.");

    //// Заполняем локацию персонажами
    //createEmerdealNPC(emerdealLocation, mainCharacter);

    //// Запуск обучающего боя
    //combatTraining(mainCharacter);

    //chapter_one(mainCharacter);

    //chapter_two(mainCharacter);

    //chapter_final(mainCharacter);

    Weapon sword("Длинный меч", 10, 5);
    Magic magic("Огненный шар", 30, 5);
    Character mainCharacter("Тучка Стальной", 200, 100, 100, &sword, &magic, "Воин");
    Witch witch("Ведьма Лилит", 200, 150, 150);
    CombatSystem fight;

    fight.startGame(mainCharacter, witch);

    return 0;
}