#include "InteractiveObject.h"

// �����������
InteractiveObject::InteractiveObject() : name(""), description("") {}

// ����������� � �����������
InteractiveObject::InteractiveObject(string& n, string& desc) : name(n), description(desc) {}

// ����������
InteractiveObject::~InteractiveObject() {}

// ����� ��� ��������� ����� �������
string InteractiveObject::getName()
{
	return name;
}

// ����� ��� ��������� �������� �������
string InteractiveObject::getDescription()
{
	return description;
}

// ����� ��� ��������� ����� �������
void InteractiveObject::setName(string& n)
{
	name = n;
}

// ����� ��� ��������� �������� �������
void InteractiveObject::setDescription(string& desc)
{
	description = desc;
}
