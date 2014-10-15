/*
 * Created by Edgar Gonzalez
 * For CIS17C - 48596
 * Implementation of LnkdLst class
 */



#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class CircularList {
public:
    //Constructors
    CircularList(T);
    CircularList(const CircularList &);
    CircularList operator=(const CircularList &);

    //Getters
    T first();
    T last();
    string toString();

    //add Node functions
    void append(T);
    void prepend(T);
    void insertAfter(T, T);
    void insertBefore(T, T);

    virtual ~CircularList();
private:
    struct Node{
         T data;
         Node *prev;
         Node *next;
    };
    Node *head;
    Node *worker;
};


#endif // CIRCULARLIST_H


template <class T>
CircularList<T>::CircularList(T firstData){
    head = new Node;
    head->data = firstData;
    head->next = head;
    head->prev = head;
}

template <class T>
CircularList<T>::CircularList(const CircularList &orig){
    if(orig.head != 0){
        //Copy head
        head = new Node;
        head->data = orig.head->data;
        head->next = head;
        head->prev = head;

        Node *origWorker = orig.head;
        worker = head;

        //Begin iterating through nodes, copying
        while(origWorker->next != head){
            worker->next = new Node;
            worker->next->prev = worker;
            worker = worker->next;
            worker->data = origWorker->data;
            origWorker = origWorker->next;
        }
        worker->next = head;
        head->prev = worker;
    }
    else head = 0;
}

template <class T>
CircularList<T>& CircularList<T>::operator=(const CircularList &orig){
    if(this!=&orig){
        //Delete old resources
        worker = head;
        head->prev->next = 0;
        while(worker->next != 0){
            head = worker;
            worker = worker->next;
            delete head;
        }

        //Copy new head
        head = new Node;
        head->data = orig.head->data;
        head->next = head;
        head->prev = head;

        Node *origWorker = orig.head;
        worker = head;

        //Begin iterating through nodes, copying
        while(origWorker->next != head){
            worker->next = new Node;
            worker->next->prev = worker;
            worker = worker->next;
            worker->data = origWorker->data;
            origWorker = origWorker->next;
        }
        worker->next = head;
        head->prev = worker;
    }
    return *this;
}

template <class T>
T CircularList<T>::first(){
    return head->data;
}

template <class T>
T CircularList<T>::last(){
    return head->prev->data;
}

template <class T>
void CircularList<T>::append(T data){
    worker = head->prev;
    worker->next = new Node;
    worker = worker->next;
    worker->data = data;
    worker->next = head;
    head->prev = worker;
}

template <class T>
void CircularList<T>::prepend(T data){
    worker = new Node;
    worker->next = head;
    worker->prev = head->prev;
    worker->data = data;
    head = worker;
}

template <class T>
void CircularList<T>::insertBefore(T beforeData, T data){
    worker = head;

    while(worker->next != head){
        if(worker->data == beforeData){
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
    //If we got here, the insert data was never found. Append to the end of the list
    append(data);
}

template <class T>
void CircularList<T>::insertAfter(T afterData, T data){
    worker = head;

    while(worker->next != head){
        if(worker->data == afterData){
            Node *tempNode = worker->next;
            worker->next = new Node;
            worker->next->prev = worker;
            worker = worker->next;
            worker->data = data;
            worker->next = tempNode;
            tempNode->prev = worker;
            return;
        }
        else worker = worker->next;
    }
    //If we got here, the insert data was never found. Append to the end of the list
    append(data);
}

template <class T>
string CircularList<T>::toString(){
    worker = head;
    stringstream stream;
    string output;

    while(worker->next != head){
        stream << worker->data << " ";
        output = stream.str();
        worker = worker->next;
    }
    return output;
}

template <class T>
CircularList<T>::~CircularList(){
    worker = head;
    head->prev->next = 0;
    while(worker != 0){
        head = worker;
        worker = worker->next;
        delete head;
    }
}
