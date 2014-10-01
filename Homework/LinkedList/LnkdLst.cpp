/*
 * Created by Edgar Gonzalez
 * For CIS17C - 48596
 * Implementation of LnkdLst class
 */


#include <LnkdLst.h>
#include <iostream>

LnkdLst::LnkdLst(int firstData){
    head = new Node;
    head->data = firstData;
    head->next = 0;
    head = tail;
}

//TODO fix this function
LnkdLst::LnkdLst(const LnkdLst &copy){
    Node copyWorker;
    if(copy.head != 0){
        head = new Node;
        head->data = copy.head->data;
        copyWorker = copy.head->next;
        worker = head;
        while(copy.worker->next != 0){
            worker->next = new Node;
            worker->data = copy.worker->data;

            temp = copy.worker->next;
        }
    else head = 0;
    }
}

void LnkdLst::append(int data){
    tail->next = new Node;
    tail = tail->next;
    tail->data = data;
    tail->next = 0;
}

void LnkdLst::prepend(int data){
    Node newNode = new Node;
    newNode->next = head;
    newNode->data = data;
    head = newNode;
}

string LnkdLst::toString(){
    worker = head;
    stringstream stream;
    string output;

    while(worker->next !=0){
        stream << worker->data << " ";
        output = stream.str();
        worker = worker->next;
    }
    return output;
}

LnkdLst::~LnkdLst(){
    worker = head;
    while(worker->next != 0){
        head = worker;
        worker = worker->next;
        delete head;
    }
}
