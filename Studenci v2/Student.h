#pragma once
#pragma once
#include<string>

class Student
{
public:
	Student();
	Student(const std::string& name, std::string lastName);
	void setName(const std::string& newName);
	void setLastName(const std::string& newLastName);
	std::string getName();
	std::string getLastName();
	std::string toString();
private:
	std::string m_name;
	std::string m_lastName;
};
