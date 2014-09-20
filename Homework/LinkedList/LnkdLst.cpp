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
}

void LnkdLst::append(int data){
    worker = head;
    while(worker->next != 0){
        worker = worker->next;
    }
    worker->next = new Node;
    worker = worker->next;
    worker->data = data;
    worker->next = 0;
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
        delete []head;
    }
}
