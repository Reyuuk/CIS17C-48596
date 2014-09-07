/*
 * Created by Edgar Gonzalez
 * For CIS17C - 48596
 */

#include <TriMatrix.h>
#include <iostream>

using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {

    int rows=5;
    int cols=10;
    int perLine=10;
    int maxRand = 20;

    //Define and create class objects
    TriMatrix<int> oneDIntArry = TriMatrix<int>(rows,maxRand);
    TriMatrix<int> twoDIntArry = TriMatrix<int>(rows, cols,maxRand);
    TriMatrix<int> threeDIntArry = TriMatrix<int>(rows, oneDIntArry.getArray(),maxRand);

    TriMatrix<float> oneDFloatArry = TriMatrix<float>(rows,maxRand);
    TriMatrix<float> twoDFloatArry = TriMatrix<float>(rows, cols, maxRand);
    TriMatrix<float> threeDFloatArry = TriMatrix<float>(rows, oneDIntArry.getArray(), maxRand);

    //Print the arrays
    cout << "Printing Integer arrays-------------" << endl;
    oneDIntArry.printArray(perLine);
    twoDIntArry.printArray();
    threeDIntArry.printArray(oneDIntArry.getArray());

    cout << endl << "Printing Float arrays------------" << endl;
    oneDFloatArry.printArray(perLine);
    twoDFloatArry.printArray();
    threeDFloatArry.printArray(oneDIntArry.getArray());

    //Exit stage right
    return 0;
}

