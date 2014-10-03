/*
 * Created by Edgar Gonzalez
 * For CIS17C - 48596
 * Implementation of LnkdLst class
 */


#ifndef LNKDLST_H
#define	LNKDLST_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class LnkdLst {
public:
    //Constructors
    LnkdLst(T);
    LnkdLst(const LnkdLst &);
    LnkdLst &operator=(const LnkdLst &);

    //Getters
    T first();
    T last();
    string toString();

    //add Node functions
    void append(T);
    void prepend(T);
    void insertAfter(T, T);
    void insertBefore(T, T);

    virtual ~LnkdLst();
private:
    struct Node{
         T data;
         Node *next;
    };
    Node *head;
    Node *worker;
    Node *tail;
};

#endif	/* LNKDLST_H */



template <class T>
LnkdLst<T>::LnkdLst(T firstData){
    head = new Node;
    head->data = firstData;
    head->next = 0;
    tail = head;
}

template <class T>
LnkdLst<T>::LnkdLst(const LnkdLst &copy){
    Node *copyWorker;

    if(copy.head != 0){
        //Copy head
        head = new Node;
        head->data = copy.head->data;
        copyWorker = copy.head->next;

        //Begin iterating through nodes, copying
        worker = head;
        while(copyWorker != 0){
            worker->next = new Node;
            worker = worker->next;
            worker->data = copyWorker->data;
            copyWorker = copyWorker->next;
        }
        tail = worker;
        tail->next = 0;
    }
    else head = 0;
}

template <class T>
T LnkdLst<T>::first(){
    return head->data;
}

template <class T>
T LnkdLst<T>::last(){
    return tail->data;
}

template <class T>
void LnkdLst<T>::append(T data){
    tail->next = new Node;
    tail = tail->next;
    tail->data = data;
    tail->next = 0;
}

template <class T>
void LnkdLst<T>::prepend(T data){
    Node *newNode = new Node;
    newNode->next = head;
    newNode->data = data;
    head = newNode;
}

template <class T>
void LnkdLst<T>::insertBefore(T beforeData, T data){
    worker = head;
    Node *tempNode = worker->next;
    if(head->data == beforeData){
        prepend(data);
        return;
    }

    while(tempNode->next !=0){
        if(tempNode->data == beforeData){
            worker->next = new Node;
            worker = worker->next;
            worker->data = data;
            worker->next = tempNode;
            return;
        }
        else{
            worker = worker->next;
            tempNode = tempNode->next;
        }
    }
    //If we got here, the insert data was never found. Append to the end of the list
    append(data);
}

template <class T>
void LnkdLst<T>::insertAfter(T afterData, T data){
    worker = head;

    while(worker->next !=0){
        if(worker->data == afterData){
            Node *tempNode = worker->next;
            worker->next = new Node;
            worker = worker->next;
            worker->data = data;
            worker->next = tempNode;
            return;
        }
        else worker = worker->next;
    }
    //If we got here, the insert data was never found. Append to the end of the list
    append(data);
}

template <class T>
string LnkdLst<T>::toString(){
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
LnkdLst<T>::~LnkdLst(){
    worker = head;
    while(worker->next != 0){
        head = worker;
        worker = worker->next;
        delete head;
    }
}
