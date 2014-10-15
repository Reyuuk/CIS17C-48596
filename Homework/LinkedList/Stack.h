#ifndef STACK_H
#define STACK_H
#include "DblLnkLst.h"

template <class T>
class Stack : private DblLnkdLst
{
public:
    void addItem(T);
    T removeItem();
};

#endif // STACK_H



template <class T>
void Stack<T>::addItem(T){
    append(T);
}

template <class T>
T Stack<T>::removeItem(){
    if(tail->prev != 0){
        worker = tail->prev;
        T tempData = tail->data;
        delete tail;
        tail = worker;
        tail->next = 0;
        return tempData;
    }
    if(tail != 0){
        T tempData = tail->data;
        delete tail;
        return tempData;
    }
    return 0;
}
