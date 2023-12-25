#pragma once
#include "InteractiveObject.h"
#include "Screen.h"
#include <utility>

// Производный класса для NPC (Non-Player Character)
class NPC :
    public InteractiveObject
{
private:

    vector<string>talkPhrases;

public:

    // Перечисление для возможных действий NPC
    enum class NPCAction {
        Talk,
        Examine
        
        /*
        * TODO: добавить по необходимости другие действия
        */
    };

    // Конструктор
    NPC();
    // Конструктор с параметрами
    NPC(const string& n, const string& desc);
    // Деструктор
    ~NPC();

    // Функция для взаимодействия с не игровым персонажем
    void interact() override;

    // Переопределение функции для получения вариантов действий
    vector<Action> getAvailableActions() const override;

    // Переопределение функции для обработки выбранного действия
    void performAction(Action& action) override;
};