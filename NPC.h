#pragma once
#include "InteractiveObject.h"
#include "Screen.h"

// ����������� ������ ��� NPC (Non-Player Character)
class NPC :
    public InteractiveObject
{
public:

    // �����������
    NPC();
    // ����������� � �����������
    NPC(string& n, string& desc);
    // ����������
    ~NPC();

    // ������� ��� �������������� � �� ������� ����������
    void interact() override;
};