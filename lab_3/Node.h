#include <iostream>
#include "Data.h"
class Node{
public:
    Node *next;
    Node *previous;
    virtual void print(){
        std::cout<<"Node class print"<<"\n";
    }
    virtual Data* data_pointer(){
        return nullptr;
    }
};
