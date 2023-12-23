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
