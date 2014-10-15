/*
 * Created by Edgar Gonzalez
 * For CIS17C - 48596
 * Implementation of LnkdLst class
 */


#ifndef DBLLNKLST_H
#define DBLLNKLST_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class DblLnkdLst {
public:
    //Constructors
    DblLnkdLst(T);
    DblLnkdLst(const DblLnkdLst &);
    DblLnkdLst& operator=(const DblLnkdLst &);

    //Getters
    T first();
    T last();
    string toString();

    //add Node functions
    void append(T);
    void prepend(T);
    void insertAfter(T, T);
    void insertBefore(T, T);

    virtual ~DblLnkdLst();
private:
    struct Node{
         T data;
         Node *prev;
         Node *next;
    };
    Node *head;
    Node *worker;
    Node *tail;
};



#endif // DBLLNKLST_H


template <class T>
DblLnkdLst<T>::DblLnkdLst(T firstData){
    head = new Node;
    head->data = firstData;
    head->next = 0;
    head->prev = 0;
    tail = head;
}

template <class T>
DblLnkdLst<T>::DblLnkdLst(const DblLnkdLst &orig){
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
DblLnkdLst<T>& DblLnkdLst<T>::operator=(const DblLnkdLst &orig){
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


template <class T>
T DblLnkdLst<T>::first(){
    return head->data;
}

template <class T>
T DblLnkdLst<T>::last(){
    return tail->data;
}

template <class T>
void DblLnkdLst<T>::append(T data){
    tail->next = new Node;
    tail->next->prev = tail;
    tail = tail->next;
    tail->data = data;
    tail->next = 0;
}

template <class T>
void DblLnkdLst<T>::prepend(T data){
    Node *newNode = new Node;
    newNode->next = head;
    newNode->prev = 0;
    newNode->data = data;
    head = newNode;
}

template <class T>
void DblLnkdLst<T>::insertBefore(T beforeData, T data){
    worker = head;

    while(worker !=0){
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
void DblLnkdLst<T>::insertAfter(T afterData, T data){
    worker = head;

    while(worker !=0){
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
string DblLnkdLst<T>::toString(){
    worker = head;
    stringstream stream;
    string output;

    while(worker !=0){
        stream << worker->data << " ";
        output = stream.str();
        worker = worker->next;
    }
    return output;
}

template <class T>
DblLnkdLst<T>::~DblLnkdLst(){
    worker = head;
    while(worker != 0){
        head = worker;
        worker = worker->next;
        delete head;
    }
}
