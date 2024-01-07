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
#include "NPC.h"
#include "Weapon.h"

using namespace std;

int main() 
{
    // Устанавливаем параметры консоли
    consoleSetting();

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
    createEmerdealNPC(emerdealLocation, mainCharacter);

    // Запуск обучающего боя
    combatTraining(mainCharacter);

    // Глава 1
    chapter_one(mainCharacter);

    // Глава 2
    chapter_two(mainCharacter);

    // Глава "Финал"
    chapter_final(mainCharacter);

    // Финальные титры
    displayFinalCredits();

    return 0;
}