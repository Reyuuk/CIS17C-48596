/*
 * File:   LnkdLst.h
 * Author: Dr. Mark E. Lehr
 * Created on September 18, 2014, 3:09 PM
 */

#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
#include <sstream>
using namespace std;

class LnkdLst {
public:
    //Constructors
    LnkdLst(int);
    LnkdLst(const LnkdLst &);
    LnkdLst &operator=(const LnkdLst &);

    //Getters
    int first();
    int last();
    string toString();

    //add Node functions
    void append(int);
    void prepend(int);
    void insertAfter(int, int);
    void insertBefore(int, int);

    virtual ~LnkdLst();
private:
    struct Node{
         int data;
         Node *next;
    };
    Node *head;
    Node *worker;
    Node *tail;
};

#endif	/* LNKDLST_H */

