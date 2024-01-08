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
    // ������� ������� ������� � � ��������
    Screen::displayCharacterByCharacter("\n�� ���������� � " + name + ".\n" + description + "\n");
    this_thread::sleep_for(chrono::milliseconds(1000));

    // �������� ����, ����������� �������������� � ���������
    while (true) 
    {
        // ������� ���������� � ��������� ��������
        Screen::displayText("\n\t~~��������� ������� ��� ��������������~~\n");
        this_thread::sleep_for(chrono::milliseconds(500));

        // ������� ����� NPC, ��������� ��� ��������������
        for (size_t i = 0; i < objects.size(); ++i) 
        {
            Screen::displayText(to_string(i + 1) + ". " + objects[i]->getName());
            this_thread::sleep_for(chrono::milliseconds(300));
        }

        // ������� "��������� ��������������"
        Screen::displayText("0. ��������� ��������������");
        this_thread::sleep_for(chrono::milliseconds(700));

        int selectedObjectIndex;
        cout << "\n��� �����: ";
        // �������� ������� ������ ����� � ����� ����
        while (!(cin >> selectedObjectIndex) || (selectedObjectIndex < 0 || selectedObjectIndex > static_cast<int>(objects.size())))
        {
            // ������� ������ �����
            cin.clear();
            // ������������� ���������� �������� � ������ �����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // ������� ��������� �� ������ � ������ ������ ����� ������
            Screen::displayDialog("����������", "�������� �����. ����������, ������� ���������� �����.");
            cout << "\n��� �����: ";
        }

        // ������������ ������ "��������� ��������������"
        if (selectedObjectIndex == 0) {
            break;
        }

        // ������� �������� �������� ��� ���������� �������
        vector<Action> objectActions = objects[selectedObjectIndex - 1]->getAvailableActions();
        this_thread::sleep_for(chrono::milliseconds(300));

        Screen::displayText("\n\t~~\"" + objects[selectedObjectIndex - 1]->getName() + "\"~~\n");
        this_thread::sleep_for(chrono::milliseconds(100));

        for (size_t i = 0; i < objectActions.size(); ++i) {
            Screen::displayText(to_string(i + 1) + ". " + objectActions[i].getDescription());
            this_thread::sleep_for(chrono::milliseconds(500));
        }

        int selectedActionIndex;
        cout << "\n��� �����: ";
        // �������� ������� ������ ����� � ����� ����
        while (!(cin >> selectedActionIndex) || (selectedActionIndex < 0 || selectedActionIndex > static_cast<int>(objectActions.size())))
        {
            // ������� ������ �����
            cin.clear();
            // ������������� ���������� �������� � ������ �����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // ������� ��������� �� ������ � ������ ������ ����� ������
            Screen::displayDialog("����������", "�������� �����. ����������, ������� ���������� �����.");
            cout << "\n��� �����: ";
        }

        // ��������� ��������� ��������
        Action& selectedAction = objectActions[selectedActionIndex - 1];
        objects[selectedObjectIndex - 1]->performAction(selectedAction);
    }
}

// ����� ��� ���������� ������������� ��������
void Location::addInteractiveObject(InteractiveObject* object)
{
    objects.push_back(object);
}
