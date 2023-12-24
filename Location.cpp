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
    Screen::displayText("\n�� ���������� � " + name + ".\n" + description);

    while (true) {
        // ������� ���������� � ��������� ��������
        Screen::displayText("\n\t~~��������� ������� ��� ��������������~~\n");

        for (size_t i = 0; i < objects.size(); ++i) {
            Screen::displayText(to_string(i + 1) + ". " + objects[i]->getName());
        }

        // ������� "��������� ��������������"
        Screen::displayText("0. ��������� ��������������");

        cout << "\n��� �����: ";

        // ���� ����� �� ������������ � ������������
        char userInput = Input::getUserInput();

        // ����������� char � int � �������� '0', ����� �������� ������ �������
        int selectedObjectIndex = userInput - '0' - 1;

        if (selectedObjectIndex == -1) {
            // ������������ ������ "��������� ��������������"
            break;
        }

        if (selectedObjectIndex >= 0 && selectedObjectIndex < static_cast<int>(objects.size())) {
            // ������� �������� �������� ��� ���������� �������
            vector<Action> objectActions = objects[selectedObjectIndex]->getAvailableActions();
            Screen::displayText("\n\t~~\"" + objects[selectedObjectIndex]->getName() + "\"~~\n");

            for (size_t i = 0; i < objectActions.size(); ++i) {
                Screen::displayText(to_string(i + 1) + ". " + objectActions[i].getDescription());
            }

            cout << "\n��� �����: ";

            // ���� ������ ���� �� ������������ � ������������
            char userActionInput = Input::getUserInput();

            // ����������� char � int � �������� '0', ����� �������� ������ ��������
            int selectedActionIndex = userActionInput - '0' - 1;

            if (selectedActionIndex >= 0 && selectedActionIndex < static_cast<int>(objectActions.size())) {
                // ��������� ��������� ��������
                Action& selectedAction = objectActions[selectedActionIndex];
                objects[selectedObjectIndex]->performAction(selectedAction);
            }
            else {
                Screen::displayText("�������� ����� ��������.");
            }
        }
        else {
            Screen::displayText("�������� ����� �������.");
        }
    }
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
