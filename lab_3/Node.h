#include <iostream>
#include "Data.h"
#ifndef NODE_H
#define NODE_H
class Node {
public:
    Node *next;
    Node *previous;
    void setNext(Node *next){
        this->next=next;
    }
    Node* getNext(){
        return this->next;
    }
    void setPrevious(Node *previous){
        this->previous=previous;
    }
    Node* getPrevious(){
        return this->previous;
    }
    virtual Data* data_pointer() = 0;
};
#endif
