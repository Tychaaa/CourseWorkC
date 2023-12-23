#include "Location.h"

// Конструктор
Location::Location() : name(""), description("") {}

// Конструктор с параметрами 1
Location::Location(const string& n, const string& desc) : name(n), description(desc) {}

// Конструктор с параметрами 2
Location::Location(const string& n, const string& desc, const vector<InteractiveObject*>& objs) : name(n), description(desc), objects(objs) {}

// Деструктор
Location::~Location() {}

// Метод, вызываемый при входе в локацию
void Location::onEnter()
{
    Screen::displayText("Вы находитесь в " + name + ". " + description);

    // Составляем список действий для объектов в локации
    vector<string> options;
    for (size_t i = 0; i < objects.size(); ++i) {
        options.push_back(objects[i]->getDescription());
    }

    /*
    * TODO: Составить список фраз для NPC
    */

    Screen::displayOptions(options);

    // Ждем ввода от пользователя и обрабатываем
    char userInput = Input::getUserInput();
    handleUserInput(userInput);
}

// Обработка ввода от пользователя
void Location::handleUserInput(char userInput)
{
    size_t choice = userInput - '0';

    if (choice > 0 && choice <= objects.size()) {
        // Пользователь выбрал действие, взаимодействуем с объектом
        objects[choice - 1]->interact();
    }
    else {
        Screen::displayText("Неверный ввод. Пожалуйста, выберите существующий вариант.");
        handleUserInput(Input::getUserInput());
    }
}

// Метод для добавления интерактивных объектов
void Location::addInteractiveObject(InteractiveObject* object)
{
    objects.push_back(object);
}
