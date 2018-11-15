#include "Node.h"
#include "Data.h"
#include <iostream>
class NodeData:public Node,public Data{
public:
    NodeData(){

    }
    void print(){
        std::cout<<"NodeData class print"<<"\n";
    }
    Data* data_pointer(){
        Data *d=this;
        return d;
    }
};
