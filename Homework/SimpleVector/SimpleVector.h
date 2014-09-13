// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   int maxSize;      // Current maximum size of the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}

   // Constructor declaration
   SimpleVector(int);

   // Copy constructor declaration
   SimpleVector(const SimpleVector &);

   // Destructor declaration
   ~SimpleVector();

   //Add a value to top of stack
   void Push(T);

   //Remove a value from top of stack
   T Pull();

   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   maxSize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   maxSize = obj.maxSize;

   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();

   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Push function. The argument is a value of type T,    *
// which is any primitive data type. The value is added *
// to the top of the array in stack fashion.            *
//*******************************************************

template <class T>
void SimpleVector<T>::Push(T element)
{
    T *newArry = NULL;

    //Resize array if there is no space
    if(arraySize==maxSize){
        //double size in a new array
        try{
           newArry = new T[arraySize*2];
        }
        catch (bad_alloc){
           memError();
        }

        maxSize = arraySize*2;

        //copy old elements and initialize new ones
        for(int elem=0;elem<arraySize;elem++){
            newArry[elem] = aptr[elem];
            newArry[arraySize+elem] = 0;
        }

        //delete old array
        delete [] aptr;
        aptr = newArry;
    }

    //Add the new value to the array
    aptr[arraySize] = element;
    arraySize++;

}

//*******************************************************
// Pull function. The final element in the array stack  *
// is removed and the array is resized. This function   *
// returns the value that is removed from the array.    *
//*******************************************************

template <class T>
T SimpleVector<T>::Pull()
{
    //Remove final element and resize array.
    if(arraySize>=0){
        T element = aptr[arraySize];
        aptr[arraySize] = 0;
        arraySize--;
        return element;
    }
    else return NULL;
}

#endif // SIMPLEVECTOR_H
