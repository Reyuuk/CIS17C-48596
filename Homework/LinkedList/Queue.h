#ifndef QUEUE_H
#define QUEUE_H
#include "LnkdLst.h"

template <class T>
class Queue : private LnkdLst
{
public:
    void addItem(T);
    T removeItem();
};

#endif // QUEUE_H


template <class T>
void Queue<T>::addItem(T){
    append(T);
}

template <class T>
T Queue<T>::removeItem(){
    if(head->next !=0){
        worker = head->next;
        T tempData = head->data;
        delete head;
        head = worker;
        return tempData;
    }
    if(head !=0){
        T tempData = head->data;
        delete head;
        return tempData;
    }
    return 0;
}
