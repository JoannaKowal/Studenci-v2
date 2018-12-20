#include "Manager.h"
const double EXPAND_NUMBER = 2;
Manager::Manager()
{
	m_students = new Student*[DEF_LEN];
	m_tableLength = DEF_LEN;
	for (int i = 0; i < m_tableLength; i++)
	{
		m_students[i] = nullptr;
	}
}

Manager::~Manager()
{
	for (int i = 0; i < m_tableLength; i++)
	{
		delete m_students[i];
	}
	delete m_students;
}

void Manager::addStudent(const std::string& name,const std::string& lastName)
{
	int index = 0;
	while (m_students[index] != nullptr && index < m_tableLength)
	{
		
			index++;
		
	}
	if (index < m_tableLength)
	{
		if (!checkDuplicate(name, lastName))
		{
			m_students[index] = new Student(name, lastName);
		}
		else
		{
			std::cout << PROMPT_DUPLICATE << std::endl;
		}
	}
	else
	{
		expandTable();
		addStudent(name, lastName);
	}
	
}

void Manager::deleteStudent(int index)
{
	if (m_students[index] != nullptr)
	{
		delete m_students[index];
		m_students[index] = nullptr;
	}
	
}

std::string Manager::printStudents()
{
	std::string students = "";
	for (int i = 0; i < m_tableLength; i++)
	{
		if (m_students[i] != nullptr)
		{
			students += std::to_string(i + 1);
			students += ".";
			students += m_students[i]->toString();
			students += "\n";
		}	
	}
	return students;
}

void Manager::changeStudentData(int index, const std::string& name, const std::string& lastName)
{
	if (index >= 0 && index < m_tableLength)
	{
		if (m_students[index] != nullptr)
		{
			if (!checkDuplicate(name, lastName))
			{
				m_students[index]->setName(name);
				m_students[index]->setLastName(lastName);
			}
			else
			{
				std::cout << PROMPT_DUPLICATE << std::endl;
			}
		}
	}
}

void Manager::expandTable()
{
	Student** temp = new Student*[EXPAND_NUMBER + m_tableLength];
	for (int i = 0; i < m_tableLength; i++)
	{
		temp[i] = m_students[i];
	}
	for (int i = 0; i < m_tableLength; i++)
	{
		delete m_students[i];
	}
	delete m_students;
	m_students = temp;
	m_tableLength = EXPAND_NUMBER +  m_tableLength;
}

bool Manager::checkDuplicate(const std::string& name, const std::string& lastName)
{
	bool found = false;
	for (int i = 0; i < m_tableLength; i++)
	{
		if (m_students[i] != nullptr)
		{
			if (m_students[i]->getName() == name && m_students[i]->getLastName() == lastName)
			{
				found = true;
			}
		}	
	}
	return found;
}

