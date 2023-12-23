#include "Location.h"

// �����������
Location::Location() : name(""), description("") {}

// ����������� � ����������� 1
Location::Location(const string& n, const string& desc) : name(n), description(desc) {}

// ����������� � ����������� 2
Location::Location(const string& n, const string& desc, const vector<InteractiveObject*>& objs) : name(n), description(desc), objects(objs) {}

// ����������
Location::~Location() {}

// �����, ���������� ��� ����� � �������
void Location::onEnter()
{
    Screen::displayText("�� ���������� � " + name + ". " + description);

    // ���������� ������ �������� ��� �������� � �������
    vector<string> options;
    for (size_t i = 0; i < objects.size(); ++i) {
        options.push_back(objects[i]->getDescription());
    }

    /*
    * TODO: ��������� ������ ���� ��� NPC
    */

    Screen::displayOptions(options);

    // ���� ����� �� ������������ � ������������
    char userInput = Input::getUserInput();
    handleUserInput(userInput);
}

// ��������� ����� �� ������������
void Location::handleUserInput(char userInput)
{
    size_t choice = userInput - '0';

    if (choice > 0 && choice <= objects.size()) {
        // ������������ ������ ��������, ��������������� � ��������
        objects[choice - 1]->interact();
    }
    else {
        Screen::displayText("�������� ����. ����������, �������� ������������ �������.");
        handleUserInput(Input::getUserInput());
    }
}

// ����� ��� ���������� ������������� ��������
void Location::addInteractiveObject(InteractiveObject* object)
{
    objects.push_back(object);
}
