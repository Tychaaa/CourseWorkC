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


    //Character mainCharacter = createMainCharacter();

    //introduction(mainCharacter);


        // Создание оружия и магии
    Weapon sword("Меч", 20, 15);
    Magic fireball("Огненный шар", 30, 25);

        // Создание персонажей
    Character player("shichi", 100, 100, 50, &sword, &fireball, "Воин");
    Wolf enemy("Волк", 80, 80, 30);

    // Создание экземпляра системы боя
    CombatSystem combatSystem;

    // Инициализация боя
    combatSystem.initiateCombat(player, enemy);

    return 0;





    return 0;
}