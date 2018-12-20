#include "Student.h"

const std::string DEF_NAME = "student";
Student::Student()
{
	m_name = DEF_NAME;
}

Student::Student(const std::string& name, std::string lastName)
{
	m_name = name;
	m_lastName = lastName;
}

void Student::setName(const std::string& newName)
{
	m_name = newName;
}

void Student::setLastName(const std::string& newLastName)
{
	m_lastName = newLastName;

}

std::string Student::getName()
{
	return m_name;
}

std::string Student::getLastName()
{
	return m_lastName;
}

std::string Student::toString()
{
	return m_name + " " + m_lastName;
}
