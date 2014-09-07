/*
 * Created by Edgar Gonzalez
 * For CIS17C - 48596
 */

//Class Specification and implementation for TriMatrix

#ifndef TRIMATRIX_H
#define TRIMATRIX_H


//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

//Global Constants


template <class T>
class TriMatrix
{
private:
    T* oneArray;
    T** twoArray;
    int rows;
    int cols;
    int randSize;

    void fillArray(int);
    void fillArray(int,int);
    void fillArray(int,int*);

public:
    //Constructors
    TriMatrix(int, int);
    TriMatrix(int, int, int);
    TriMatrix(int, int*, int);

    //Destructor
    ~TriMatrix();

    //Methods
    void printArray(int); //print single dimensional array
    void printArray();  //print 2d array
    void printArray(int*); //print tri array
    T* getArray(); //Gets single array


};



/*
 *
 * Implementations for TriMatrix Below
 *
 */



//Constructor single dimensional array
template <class T>
TriMatrix<T>::TriMatrix(int columns, int max){
    twoArray = NULL;
    if(columns < 1){
        cols = 1;
    }
    else cols = columns;
    if(max < 1){
        randSize = 20;
    }
    else randSize = max;

    fillArray(cols);
}

//Fill single Dimension array
template <class T>
void TriMatrix<T>::fillArray(int cols){

    //initialize random number generator
    srand(static_cast<T>(time(0)));
    //Declare the 1-D Array
    T* array=new T[cols];
    //Fill the array with random 2 digit numbers
    for(int col=0;col<cols;col++){
        array[col]=static_cast<T>(rand())/(static_cast<T>(RAND_MAX/randSize));
    }
    oneArray = array;
}

//Print one dimensional array
template <class T>
void TriMatrix<T>::printArray(int perLine){
    //Print the Array
    cout<<endl;
    for(int col=0;col<cols;col++){
       cout<<oneArray[col]<<" ";
       if(col%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Gets one dimensional array - needed for Triarray
template <class T>
T* TriMatrix<T>::getArray(){
    return oneArray;
}

//Constructor two dimensional array
template <class T>
TriMatrix<T>::TriMatrix(int row, int columns, int max){
    oneArray = NULL;
    if(columns < 1){
        cols = 1;
    }
    else cols = columns;
    if(row < 1){
        rows = 1;
    }
    else rows = row;
    if(max < 1){
        randSize = 20;
    }
    else randSize = max;

    fillArray(rows, cols);
}

//Fill two dimensional array
template <class T>
void TriMatrix<T>::fillArray(int rows,int cols){

    //initialize random number generator
    srand(static_cast<T>(time(0)));
    //Declare the 2-D Array
    T** array=new T*[rows];
    for(int row=0;row<rows;row++){
        array[row]=new T[cols];
    }
    //Fill the array with random 2 digit numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            array[row][col]=static_cast<T>(rand())/(static_cast<T>(RAND_MAX/randSize));
        }
    }
    twoArray = array;
}

//Print 2D array
template <class T>
void TriMatrix<T>::printArray(){
    //Print the Array
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<<setw(6)<<setfill(' ')<<setprecision(4)<<twoArray[row][col]<<" ";
        }
        cout<<endl;
    }
}

//Constructor for Tri array
template <class T>
TriMatrix<T>::TriMatrix(int row, int *colAry, int max){
    oneArray = NULL;
    if(row < 1){
        rows = 1;
    }
    else rows = row;
    if(max < 1){
        randSize = 20;
    }
    else randSize = max;

    fillArray(rows, colAry);
}

//Fill tri array
template <class T>
void TriMatrix<T>::fillArray(int rows,int *colAry){

    //initialize random number generator
    srand(static_cast<T>(time(0)));
    //Declare the 2-D Array
    T** array=new T*[rows];
    for(int row=0;row<rows;row++){
        array[row]=new T[colAry[row]];
    }
    //Fill the array with random 2 digit numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
            array[row][col]=static_cast<T>(rand())/(static_cast<T>(RAND_MAX/randSize));
        }
    }
    twoArray = array;
}

//Print Tri array
template <class T>
void TriMatrix<T>::printArray(int *colAry){
    //Print the Array
    cout << endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
            cout<<twoArray[row][col]<<" ";
        }
        cout<<endl;
    }
}

//destructor deallocates array memory
template <class T>
TriMatrix<T>::~TriMatrix(){

    //deallocates twoArray
    if(twoArray!=NULL){
        for(int row=0; row<rows; row++){
            delete []twoArray[row];
        }
        delete []twoArray;
    }
    //deallocates singleArray
    if(oneArray!=NULL){
        delete []oneArray;
    }
}


            //make github folders book, homework, project, lab, class


#endif // TRIMATRIX_H






















