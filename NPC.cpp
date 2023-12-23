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
