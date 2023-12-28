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
    Screen::displayCharacterByCharacter("\n�� ���������� � " + name + ".\n" + description + "\n");
    //Screen::displayText("\n�� ���������� � " + name + ".\n" + description);
    this_thread::sleep_for(chrono::milliseconds(1000));

    while (true) {
        // ������� ���������� � ��������� ��������
        Screen::displayText("\n\t~~��������� ������� ��� ��������������~~\n");
        this_thread::sleep_for(chrono::milliseconds(500));

        for (size_t i = 0; i < objects.size(); ++i) {
            Screen::displayText(to_string(i + 1) + ". " + objects[i]->getName());
            this_thread::sleep_for(chrono::milliseconds(300));
        }

        // ������� "��������� ��������������"
        Screen::displayText("0. ��������� ��������������");
        this_thread::sleep_for(chrono::milliseconds(700));

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
            this_thread::sleep_for(chrono::milliseconds(300));
            Screen::displayText("\n\t~~\"" + objects[selectedObjectIndex]->getName() + "\"~~\n");
            this_thread::sleep_for(chrono::milliseconds(100));

            for (size_t i = 0; i < objectActions.size(); ++i) {
                Screen::displayText(to_string(i + 1) + ". " + objectActions[i].getDescription());
                this_thread::sleep_for(chrono::milliseconds(500));
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

// ����� ��� ���������� ������������� ��������
void Location::addInteractiveObject(InteractiveObject* object)
{
    objects.push_back(object);
}
