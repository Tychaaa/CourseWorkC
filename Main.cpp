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

    cout << "\nДобро пожаловать в увлекательный мир приключений!\n";
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "\nВы оказались в загадочном мире, полном тайн и опасностей.\n";
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nТемный лес, городские переулки, древние руины — перед вами открыты неисследованные земли.\n";
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nОднако, перед тем как начать свое приключение, вам нужно создать своего героя.\n";
    this_thread::sleep_for(chrono::milliseconds(1500));

    // Задержка и создание главного героя
    cout << "\nСекундочку, мы подготовили для вас несколько вопросов...\n";
    this_thread::sleep_for(chrono::milliseconds(2000));

    Character mainCharacter = createMainCharacter();

    cout << "\nТеперь вы готовы начать свое приключение! Удачи, " << mainCharacter.getName() << "!\n";
    this_thread::sleep_for(chrono::milliseconds(1500));

    // Ожидаем нажатия клавиши перед продолжением
    cout << "\nНажмите Enter, чтобы продолжить...";
    cin.get();

    return 0;
}