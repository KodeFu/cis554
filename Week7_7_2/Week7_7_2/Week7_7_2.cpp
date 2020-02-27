#include <iostream>
#include <stdexcept>
#include "Time.h"

using namespace std;

int main()
{
    Time t;
    Time* ptrT = &t;

    cout << "The initial universal time is ";
    ptrT->printUniversal();
    cout << "\nThe initial standard time is ";
    ptrT->printStandard();

    ptrT->setTime(12, 27, 6);
    cout << "\n\nUniversal time after setTime is";
    ptrT->printUniversal();
    cout << "\n\Standard time after setTime is";
    ptrT->printStandard();

    try
    {
        ptrT->setTime(99, 99, 99); // values out of range
    }
    catch (invalid_argument & e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    cout << "\n\nAfter attempting invalid settings:"
        << "\nUniversal time: ";
    ptrT->printUniversal();
    cout << "\nStandard time: ";
    ptrT->printStandard();
    cout << endl;
}
