#pragma once
#include "InteractiveObject.h"
#include "Screen.h"
#include <utility>

// ����������� ������ ��� NPC (Non-Player Character)
class NPC :
    public InteractiveObject
{
private:

    vector<string>talkPhrases;

public:

    // ������������ ��� ��������� �������� NPC
    enum class NPCAction {
        Talk,
        Examine
        
        /*
        * TODO: �������� �� ������������� ������ ��������
        */
    };

    // �����������
    NPC();
    // ����������� � �����������
    NPC(const string& n, const string& desc);
    // ����������
    ~NPC();

    // ������� ��� �������������� � �� ������� ����������
    void interact() override;

    // ��������������� ������� ��� ��������� ��������� ��������
    vector<Action> getAvailableActions() const override;

    // ��������������� ������� ��� ��������� ���������� ��������
    void performAction(Action& action) override;
};