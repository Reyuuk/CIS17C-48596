#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include "DblLnkLst.h"

template <class T>
class SortedList : private DblLnkdLst
{
public:
    SortedList(T);
    SortedList(const SortedList &);
    SortedList& operator=(const SortedList &);

    void addSortedItem(T);
};

#endif // SORTEDLIST_H


template <class T>
SortedList<T>::SortedList(T firstData){
    head = new Node;
    head->data = firstData;
    head->prev = 0;
    head->next = 0;
    tail = head;
}

template <class T>
void SortedList<T>::addSortedItem(T data){
    if(head->data > data){
        worker = new Node;
        worker->next = head;
        worker->prev = 0;
        head->prev = worker;
        worker->data = data;
        head = worker;
        return;
    }

    worker = head->next;
    while(worker !=0){
        if(worker->data > data){
            Node *tempNode = worker->prev;
            worker->prev = new Node;
            worker->prev->next = worker;
            worker = worker->prev;
            worker->data = data;
            worker->prev = tempNode;
            tempNode->next = worker;
            return;
        }
        else{
            worker = worker->next;
        }
    }
    //If we got here, new data is the largest node of the set
    append(data);
}


template <class T>
SortedList<T>::SortedList(const SortedList &orig){
    Node *origWorker;

    if(orig.head != 0){
        //Copy head
        head = new Node;
        head->data = orig.head->data;
        head->prev = 0;
        origWorker = orig.head->next;

        //Begin iterating through nodes, copying
        worker = head;
        while(origWorker != 0){
            worker->next = new Node;
            worker->next->prev = worker;
            worker = worker->next;
            worker->data = origWorker->data;
            origWorker = origWorker->next;
        }
        tail = worker;
        tail->next = 0;
    }
    else head = 0;
}

template <class T>
SortedList<T>& SortedList<T>::operator=(const SortedList &orig){
    if(this!=&orig){
        //Delete old resources
        worker = head;
        while(worker != 0){
            head = worker;
            worker = worker->next;
            delete head;
        }

        //Copy new head
        head = new Node;
        head->data = orig.head->data;
        head->prev = 0;
        Node *origWorker = orig.head->next;

        //Begin iterating through nodes, copying
        worker = head;
        while(origWorker != 0){
            worker->next = new Node;
            worker->next->prev = worker;
            worker = worker->next;
            worker->data = origWorker->data;
            origWorker = origWorker->next;
        }
        tail = worker;
        tail->next = 0;
    }
    return *this;
}
