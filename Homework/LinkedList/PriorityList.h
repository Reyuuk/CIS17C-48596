/*
 * Created by Edgar Gonzalez
 * For CIS17C - 48596
 * Implementation of LnkdLst class
 */

#ifndef PRIORITYLIST_H
#define PRIORITYLIST_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class PriorityList
{
public:
    PriorityList(T, int);
    PriorityList(const PriorityList &);
    PriorityList &operator=(const PriorityList &);

    void insertWithPriority(T, int pri);

    T peekHighestPriority();
    T popHighestPriority();
    T peekLowestPriority();
    T popLowestPriority();

    virtual ~PriorityList();
private:
    struct Node{
        T data;
        int priority;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *worker;
    Node *tail;
};

#endif // PRIORITYLIST_H



template <class T>
PriorityList<T>::PriorityList(T firstData, int pri){
    head = new Node;
    head->data = firstData;
    head->priority = pri;
    head->next = 0;
    head->prev = 0;
    tail = head;
}

template <class T>
PriorityList<T>::PriorityList(const PriorityList &copy){
    Node *copyWorker;

    if(copy.head != 0){
        //Copy head
        head = new Node;
        head->data = copy.head->data;
        head->priority = copy.head->priority;
        head->prev = 0;
        copyWorker = copy.head->next;

        //Begin iterating through nodes, copying
        worker = head;
        while(copyWorker != 0){
            worker->next = new Node;
            worker->next->prev = worker;
            worker = worker->next;
            worker->data = copyWorker->data;
            worker->priority = copyWorker->priority;
            copyWorker = copyWorker->next;
        }
        tail = worker;
        tail->next = 0;
    }
    else head = 0;
}

template <class T>
PriorityList<T>& PriorityList<T>::operator=(const PriorityList &copy){
    if(this!=&copy){
        //Delete old resources
        worker = head;
        while(worker != 0){
            head = worker;
            worker = worker->next;
            delete head;
        }

        //Copy new head
        head = new Node;
        head->data = copy.head->data;
        head->priority = copy.head->priority;
        head->prev = 0;
        Node *copyWorker = copy.head->next;

        //Begin iterating through nodes, copying
        worker = head;
        while(copyWorker != 0){
            worker->next = new Node;
            worker->next->prev = worker;
            worker = worker->next;
            worker->data = copyWorker->data;
            worker->priority = copyWorker->priority;
            copyWorker = copyWorker->next;
        }
        tail = worker;
        tail->next = 0;
    }
    else head = 0;
}


template <class T>
void PriorityList<T>::insertWithPriority(T data, int pri){
    if(head->priority > pri){
        worker = new Node;
        worker->next = head;
        worker->prev = 0;
        head->prev = worker;
        worker->data = data;
        worker->priority = pri;
        head = worker;
        return;
    }

    worker = head->next;
    while(worker !=0){
        if(worker->priority > pri){
            Node *tempNode = worker->prev;
            worker->prev = new Node;
            worker->prev->next = worker;
            worker = worker->prev;
            worker->data = data;
            worker->priority = pri;
            worker->prev = tempNode;
            tempNode->next = worker;
            return;
        }
        else{
            worker = worker->next;
        }
    }
    //If we got here, new data is the largest node of the set
    tail->next = new Node;
    tail->next->prev = tail;
    tail = tail->next;
    tail->data = data;
    tail->priority = pri;
    tail->next = 0;
}

template <class T>
T PriorityList<T>::peekHighestPriority(){
    return head->data;
}

template <class T>
T PriorityList<T>::peekLowestPriority(){
    return tail->data;
}

template <class T>
T PriorityList<T>::popHighestPriority(){
    worker = head->next;
    T headData = head->data;
    delete head;
    head = worker;
    return headData;
}

template <class T>
T PriorityList<T>::popLowestPriority(){
    worker = tail->prev;
    T tailData = tail->data;
    delete tail;
    tail = worker;
    return tailData;
}


template <class T>
string PriorityList<T>::toString(){
    worker = head;
    stringstream stream;
    string output;

    while(worker !=0){
        stream << worker->priority << "-" << worker->data << " ";
        output = stream.str();
        worker = worker->next;
    }
    return output;
}

template <class T>
PriorityList<T>::~PriorityList(){
    worker = head;
    while(worker != 0){
        head = worker;
        worker = worker->next;
        delete head;
    }
}
