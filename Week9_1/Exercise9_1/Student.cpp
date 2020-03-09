#include "Student.h"

// default constructor 
// initialize our data to something meaningful
Student::Student()
	: department("Non-matriculated"), gpa(0.0)
{
	// no body needed. everthing was done in the initialization list
}

// initialization constructor
// initialize our base class with pertinent information
// then initialize this derived class data with the remaining pertinent data
Student::Student(string cName, string fName, string lName, int memID, string dept, double dgpa)
	: CommunityMember(cName, fName, lName, memID), department(dept), gpa(dgpa)
{
	// no body needed. everthing was done in the initialization list
}

string Student::GetStudentDepartment()
{
	return department;
}

double Student::GetStudentGPA()
{
	return gpa;
}