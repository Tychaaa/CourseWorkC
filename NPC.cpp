#include "NPC.h"

// �����������
NPC::NPC() : InteractiveObject() {}

// ����������� � �����������
NPC::NPC(string& n, string& desc) : InteractiveObject(n, desc) {}

// ����������
NPC::~NPC() {}

// ������� ��� �������������� � �� ������� ����������
void NPC::interact()
{
	Screen::displayText("NPC �������: " + getDescription());
	
	/*
	* TODO: ������ �������������� � NPC
	*/
}
