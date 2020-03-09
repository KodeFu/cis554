#pragma once
#include "CommunityMember.h"
class Student :
	public CommunityMember
{
public:
	Student();

	// initialization contstructor
	Student(string cNname, string fName, string lName, int memID, string dept, double dgpa);

	string GetStudentDepartment();
	double GetStudentGPA();

private:
	string department;
	double gpa;
};

