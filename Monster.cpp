#include "Monster.h"

Monster::Monster() : Character() {
    // Инициализация по умолчанию или специфичная для монстра
}

Monster::Monster(string name, int health, int stamina, int mana, Weapon* weapon, Magic* magic)
    : Character(name, health, stamina, mana, weapon, magic) {
    // Инициализация монстра с заданными параметрами
}

Monster::~Monster() {
    // Деструктор монстра, если нужно освободить какие-то ресурсы
}

void Monster::attack(Character& target) {
    // Реализация функции атаки монстра
    // Здесь может быть какая-то общая логика для всех монстров
    // Например:
    int choice = rand() % 3; // Генерация случайного числа от 0 до 2

    switch (choice) {
    case 0:
        // Вызов первой атаки
        // this->bite(target);
        break;
    case 1:
        // Вызов второй атаки
        // this->clawAttack(target);
        break;
        // Добавь другие варианты атак для монстров
        // case 2:
        //     // this->anotherAttack(target);
        //     break;
    default:
        // Общая атака по умолчанию
        cout << this->getName() << " атакует " << target.getName() << "!\n";
        // Например, можно нанести базовый урон:
        int damage = 10;
        target.takeDamage(damage);
        break;
    }
}