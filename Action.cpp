#include "Action.h"

// �����������
Action::Action() : type(), description("") {}

// ����������� � �����������
Action::Action(ActionType type, const string& description) : type(type), description(description) {}

// ����������
Action::~Action() {}

// ������ ��� ��������� ���� ��������
Action::ActionType Action::getType() const
{
	return type;
}

// ������ ��� ��������� �������� ��������
string Action::getDescription() const
{
	return description;
}
