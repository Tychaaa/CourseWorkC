#include "NPC.h"

// Конструктор
NPC::NPC() : InteractiveObject() {}

// Конструктор с параметрами
NPC::NPC(string& n, string& desc) : InteractiveObject(n, desc) {}

// Деструктор
NPC::~NPC() {}

// Функция для взаимодействия с не игровым персонажем
void NPC::interact()
{
	Screen::displayText("NPC говорит: " + getDescription());
	
	/*
	* TODO: Логика взаимодействия с NPC
	*/
}
