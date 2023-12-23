#pragma once
#include "InteractiveObject.h"
#include "Screen.h"

// Производный класса для NPC (Non-Player Character)
class NPC :
    public InteractiveObject
{
public:

    // Конструктор
    NPC();
    // Конструктор с параметрами
    NPC(string& n, string& desc);
    // Деструктор
    ~NPC();

    // Функция для взаимодействия с не игровым персонажем
    void interact() override;
};