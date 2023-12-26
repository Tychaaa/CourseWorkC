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

    // Устанавливаем заголовок окна консоли
    SetConsoleTitle(L"Blades of Destiny");

    mainMenu();

    Character mainCharacter = createMainCharacter();

    //introduction(mainCharacter);

    return 0;
}