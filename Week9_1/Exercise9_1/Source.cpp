///////////////////////////////////////////////////////////
// Source.cpp
// CIS554 Object Oriented Programming in C++
// Exercise 9_1 - Simple Intheritance
//                program test 
///////////////////////////////////////////////////////////

#include "CommunityMember.h"
#include "Employee.h"
#include "Student.h"
#include <iostream>
using std::cout;
using std::endl;

// Demonstrate CommunityMember class
void DemonstrateCommunityMember(CommunityMember &);

// Demonstrate Employee class
void DemonstrateEmployee(Employee &);

void DemonstrateStudent(Student& c);

int main()
{
	// demonstrate CommunityMember default constructor
	cout << "***** Demonstrating the default constructor, and member methods, for class CommunityMember" << endl;
	CommunityMember commMember;
	DemonstrateCommunityMember(commMember);
	cout << endl;

	// demonstrate CommunityMember initialization constructor
	cout << "***** Demonstrating the initialization constructor, and member methods, for class CommunityMember" << endl;
	CommunityMember commMemberHarry("Syracuse University", "Harry", "Potter", 1234);
	DemonstrateCommunityMember(commMemberHarry);
	cout << endl;


	// demonstrate Employee default constructor
	cout << "***** Demonstrating the default constructor, and member methods, for class Employee" << endl;
	Employee commMemberEmp;
	DemonstrateEmployee(commMemberEmp);
	cout << endl;


	// demonstrate Employee initialization constructor
	cout << "***** Demonstrating the initialization constructor, and member methods, for class Employee" << endl;
	Employee commMemberEmpHarry("Syracuse University", "Harry", "Potter", 1234, "Janitor", 25000);
	DemonstrateEmployee(commMemberEmpHarry);
	cout << endl;

	cout << "***** Demonstrating the initialization constructor, and member methods, for class Student" << endl;
	Student studentBob("Syracuse University", "Hermonie", "Granger", 1234, "Graduate", 4.0);
	DemonstrateStudent(studentBob);
	cout << endl;
}

void DemonstrateCommunityMember(CommunityMember & c)
{
	cout << c.GetFirstName() << " "
		<< c.GetLastName()
		<< " is a member of the " << c.GetCommunityName() << " community, with member ID " << c.GetMemberID() << endl;
}

void DemonstrateEmployee(Employee & c)
{
	cout << c.GetFirstName() << " "
		<< c.GetLastName()
		<< " is a member of the " << c.GetCommunityName() << " community, " << " with member ID " << c.GetMemberID() << endl
		<< "He/She is an employee with Job Title: " << c.GetJobTitle() << ", making "
		<< c.GetYearlySalary() << " per year." << endl;
}
void DemonstrateStudent(Student& c)
{
	cout << c.GetFirstName() << " "
		<< c.GetLastName()
		<< " is a member of the " << c.GetCommunityName() << " community, " << " with member ID " << c.GetMemberID() << endl
		<< "He/She is an employee at Department: " << c.GetStudentDepartment() << ", with a GPA of "
		<< c.GetStudentGPA() << " per year." << endl;
}
