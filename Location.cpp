#include "Location.h"

// �����������
Location::Location() : name(""), description("") {}

// ����������� � �����������
Location::Location(string& n, string& desc) : name(n), description(desc) {}

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
