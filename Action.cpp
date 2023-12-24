#include "Action.h"

// Конструктор
Action::Action() : type(), description("") {}

// Конструктор с параметрами
Action::Action(ActionType type, const string& description) : type(type), description(description) {}

// Деструктор
Action::~Action() {}

// Геттер для получения типа действия
Action::ActionType Action::getType() const
{
	return type;
}

// Геттер для получения описания действия
string Action::getDescription() const
{
	return description;
}
