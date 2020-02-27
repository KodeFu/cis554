#include <iostream>
#include <array>
#include <ctime>

using namespace std;

const size_t rows = 10;
const size_t columns = 10;
void printArray(const array<array<int, columns>, rows> &a);
void populateArray(array <array<int, columns>, rows>& a);

void main()
{
    array< array< int, columns >, rows > array1;

    populateArray(array1);

    cout << "Values in array1 by row are: " << endl;
    printArray(array1);
}

void printArray(const array <array<int, columns>, rows> &a)
{
    for (auto const& row : a)
    {
        for (auto const& element : row)
        {
            cout << element << ' ';
        }

        cout << endl;
    }
}

void populateArray(array <array<int, columns>, rows> &a)
{
    srand(time(NULL));

    for (auto & row : a)
    {
        for (auto & element : row)
        {
            element = rand() % 100;
        }
    }
}