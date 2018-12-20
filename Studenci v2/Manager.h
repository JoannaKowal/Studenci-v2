#pragma once
#include "Student.h"
#include <iostream>
const int DEF_LEN = 1;
const std::string PROMPT_DUPLICATE = "Taki student jest ju¿ wpisany!";
class Manager
{
public:
	Manager();
	~Manager();
	void addStudent(const std::string& name,const std::string& lastName);
	void deleteStudent(int index);
	std::string printStudents();
	void changeStudentData(int index,const std::string& name,const std::string& lastName);

private:
	Student** m_students;
	int m_tableLength;
	void expandTable();
	//void setStudentData(const std::string& name, const std::string& lastName);
	bool checkDuplicate(const std::string& name, const std::string& lastName);
};
