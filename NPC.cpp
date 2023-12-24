#include "NPC.h"

// Конструктор
NPC::NPC() : InteractiveObject() {}

// Конструктор с параметрами
NPC::NPC(const string& n, const string& desc) : InteractiveObject(n, desc) {}

// Деструктор
NPC::~NPC() {}

// Функция для взаимодействия с не игровым персонажем
void NPC::interact()
{
	Screen::displayText(getName() + " говорит: " + getDescription());
	
	/*
	* TODO: Логика взаимодействия с NPC
	*/
}

// Функция для получения вариантов действий
vector<Action> NPC::getAvailableActions() const
{
	// Возвращаем действия для NPC
	vector<Action> actions;
	actions.push_back(Action(Action::ActionType::Talk, "Поговорить"));
	actions.push_back(Action(Action::ActionType::Examine, "Осмотреть"));
	return actions;
}

// Функциядля обработки выбранного действия
void NPC::performAction(Action& action)
{
    switch (action.getType()) {
    case Action::ActionType::Talk:

        /*
        * TODO: реализовать для каждого NPC свой собственный набор фраз
        */

        Screen::displayText("\n" + getName() + " говорит: Привет, путник!");
        // Логика для действия "Поговорить"
        break;

    case Action::ActionType::Examine:
        Screen::displayText("\nВы осматриваете \"" + getName() + "\".\n" + getDescription());
        // Логика для действия "Осмотреть"
        break;

    default:
        Screen::displayText("Неподдерживаемое действие.");
        break;
    }
}
