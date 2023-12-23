#include "InteractiveObject.h"

// Конструктор
InteractiveObject::InteractiveObject() : name(""), description("") {}

// Конструктор с параметрами
InteractiveObject::InteractiveObject(const string& n, const string& desc) : name(n), description(desc) {}

// Деструктор
InteractiveObject::~InteractiveObject() {}

// Метод для получения имени объекта
string InteractiveObject::getName()
{
	return name;
}

// Метод для получения описания объекта
string InteractiveObject::getDescription()
{
	return description;
}

// Метод для установки имени объекта
void InteractiveObject::setName(string& n)
{
	name = n;
}

// Метод для установки описания объекта
void InteractiveObject::setDescription(string& desc)
{
	description = desc;
}
