/*
 * Created by Edgar Gonzalez
 * For CIS17C - 48596
 * Implementation of Linked list
 */

//System Libraries
#include <iostream>
using namespace std;

//Our Library
#include "LnkdLst.h"

int main(int argc, char** argv) {
    //Create a linked list
    LnkdLst<float> list(0);
    //Append 3 more chains
    int clinks=10;
    for(float i=1.5;i<=clinks;i++){
        list.append(i);
    }

    //Test functions
    list.insertAfter(5.5, 30);
    list.insertBefore(3.5,50);
    list.append(22);
    list.prepend(19);

    //Test copy constructor
    LnkdLst<float> list2(list);
    list2.append(555);
    list2.append(222);

    //Print the data
    cout<<list.toString()<<endl;
    cout<<list2.toString()<<endl;

    cout << list.last() << endl;

    cout << list.first() << endl;

    //Exit stage right!
    return 0;
}
