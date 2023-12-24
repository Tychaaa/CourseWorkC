#include "NPC.h"

// �����������
NPC::NPC() : InteractiveObject() {}

// ����������� � �����������
NPC::NPC(const string& n, const string& desc) : InteractiveObject(n, desc) {}

// ����������
NPC::~NPC() {}

// ������� ��� �������������� � �� ������� ����������
void NPC::interact()
{
	Screen::displayText(getName() + " �������: " + getDescription());
	
	/*
	* TODO: ������ �������������� � NPC
	*/
}

// ������� ��� ��������� ��������� ��������
vector<Action> NPC::getAvailableActions() const
{
	// ���������� �������� ��� NPC
	vector<Action> actions;
	actions.push_back(Action(Action::ActionType::Talk, "����������"));
	actions.push_back(Action(Action::ActionType::Examine, "���������"));
	return actions;
}

// ���������� ��������� ���������� ��������
void NPC::performAction(Action& action)
{
    switch (action.getType()) {
    case Action::ActionType::Talk:

        /*
        * TODO: ����������� ��� ������� NPC ���� ����������� ����� ����
        */

        Screen::displayText("\n" + getName() + " �������: ������, ������!");
        // ������ ��� �������� "����������"
        break;

    case Action::ActionType::Examine:
        Screen::displayText("\n�� ������������ \"" + getName() + "\".\n" + getDescription());
        // ������ ��� �������� "���������"
        break;

    default:
        Screen::displayText("���������������� ��������.");
        break;
    }
}
