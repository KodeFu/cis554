/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 3_4 - For loops
/////////////////////////////////////////////////////
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int row = 1;
	for (int x = 1; x <= 64; x++)
	{
		cout << "* ";
		if (x % 8 == 0)
		{
			cout << endl;

			if (++row % 2 == 0)
			{
				cout << " ";
			}
		}
	}

	return 0;
}
