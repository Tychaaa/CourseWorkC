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


    Weapon sword("Длинный меч", 10, 30);
    Magic magic("Огненный шар", 30, 30);
    Character mainCharacter("Shichi", 200, 30, 30, &sword, &magic, "Воин");
    DarkLord darklord("Владыка Тьмы", 500, 500, 500);
    Witch witch("Ведьма Лилит", 200, 150, 150);

    CombatSystem fight;
    fight.startGame(mainCharacter, darklord);
    fight.startGame(mainCharacter, witch);

    //Wolf wolf("Волк", 60, 50, 0);

   // Ogre ogre("Огр", 100, 100, 0);

   // Goblin goblin("Гоблин", 60, 100, 100);

   // Skeleton skeleton("Скелет", 40, 100, 100);

   // EarthElemental earthElemental("Элементаль земли", 100, 100, 150);

   // fight.startGame(mainCharacter, wolf);

    //fight.startGame(mainCharacter, ogre);

   // fight.startGame(mainCharacter, goblin);

    //fight.startGame(mainCharacter, skeleton);

    //fight.startGame(mainCharacter, earthElemental);




    return 0;
}