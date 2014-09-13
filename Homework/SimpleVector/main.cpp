/*
 * Written by Edgar Gonzalez
 * For CIS17C - 48596
 */

#include <iostream>
#include <SimpleVector.h>

using namespace std;

int main()
{
    int arraySize = 10;
    SimpleVector<int> viri = SimpleVector<int>(arraySize);
    cout << "Initial array size is " << viri.size() << endl;

    viri[2] = 2;
    viri[9] = 7;

    cout << "Pushing -2.2 as a new element.";
    viri.Push(-2);
    cout << endl;
    cout << "New array size is: " << viri.size() << endl;

    cout << "Displaying new element: " << viri.getElementAt(viri.size()-1) << endl;

    viri.Pull();
    cout << "Removing final element and displaying new size (" << viri.size()
         << ") and final element: " << viri.getElementAt(viri.size()-1) << endl;

    return 0;
}

