#include "Node.h"
#include "Data.h"
#include <iostream>
#ifndef NodeData_H
#define NodeData_H
class NodeData : public Node,public Data {
public:
    NodeData(char name[32], char real_name[32],char bd[32],int male,char ability[32],char weaknesses[128], int win_amount, double strength_rating) :
        Data(name, real_name, bd, male, ability, weaknesses, win_amount, strength_rating){
            this->setPrevious(nullptr);
            this->setNext(nullptr);
    }
    Data* data_pointer() override{
        Data *d = this;
        return d;
    }
};
#endif
