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
    LnkdLst list(0);
    //Append 3 more chains
    int clinks=10;
    for(int i=1;i<=clinks;i++){
        list.append(i);
    }
    //Print the data
    cout<<list.toString()<<endl;
    //Exit stage right!
    return 0;
}
