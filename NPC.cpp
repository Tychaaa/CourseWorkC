#include "NPC.h"

// �����������
NPC::NPC() : InteractiveObject() {}

// ����������� � �����������
NPC::NPC(const string& n, const string& desc) : InteractiveObject(n, desc) 
{
    // ������������� ���� NPC
    talkPhrases.push_back("������, ������!");
    talkPhrases.push_back("����� ���������� � ���� ���!");
    talkPhrases.push_back("��� ������� ���� ����?");
    talkPhrases.push_back("���� ���������, � ���� ������ �� ������ ��������.");
    talkPhrases.push_back("�� ��� ����� �����?");
    talkPhrases.push_back("�����, ����� ����� ���� ��������� �� ������ �����.");
    talkPhrases.push_back("���� � ���� ���� �������, ���������.");
    talkPhrases.push_back("�� ��� ����� �����, ��� �������.");
    talkPhrases.push_back("�������, � ���� ���� ����� ����.");
    talkPhrases.push_back("���� ����� �� �����.");
}

// ����������
NPC::~NPC() {}

// ������� ��� �������������� � �� ������� ����������
void NPC::interact()
{
    // �������� ��������� ����� �� ������, �������� �����������, ���� ���� ������ �����
    if (!talkPhrases.empty()) {
        int randomIndex = rand() % talkPhrases.size();
        Screen::displayText("\n" + getName() + " �������: " + talkPhrases[randomIndex]);
        // ������� �������������� �����
        talkPhrases.erase(talkPhrases.begin() + randomIndex);
    }
    else {
        Screen::displayText("\n" + getName() + " �������: ��� ����� �������, ������!");
    }
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
    // �������� "����������"
    case Action::ActionType::Talk:
        interact();
        break;

    // �������� "���������"
    case Action::ActionType::Examine:
        Screen::displayText("\n�� ������������ \"" + getName() + "\".\n" + getDescription());
        break;

    default:
        Screen::displayText("���������������� ��������.");
        break;
    }
}
