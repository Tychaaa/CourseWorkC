#include "NPC.h"

// �����������
NPC::NPC() : InteractiveObject() {}

// ����������� � ����������� 1
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

// ����������� � ����������� 2
NPC::NPC(const string& n, const string& desc, vector<string> phrases) : InteractiveObject(n, desc)
{
    // ������������� ���� NPC
    talkPhrases = move(phrases);
}

// ����������
NPC::~NPC() {}

// ������� ��� �������������� � �� ������� ����������
void NPC::interact()
{
    // ������� ����� �� �������
    if (!talkPhrases.empty()) {
        cout << "\n" << getName() << ":";
        this_thread::sleep_for(chrono::milliseconds(500));
        Screen::displayCharacterByCharacter(talkPhrases.front() + "\n");

        // ������� �������������� �����
        talkPhrases.erase(talkPhrases.begin());
    }
    else {
        cout << "\n" << getName() << ":";
        this_thread::sleep_for(chrono::milliseconds(500));
        Screen::displayCharacterByCharacter("- ��� ����� �������, ������!\n");
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
        Screen::displayCharacterByCharacter("\n�� ������������ \"" + getName() + "\".\n" + getDescription());
        cout << endl;
        break;

    default:
        Screen::displayText("���������������� ��������.");
        break;
    }
}
