#include <iostream>
#include "NodeData.h"
#include "MyException.h"
const char *path = "D:\\programming\\C_LAB\\LAB_1\\data.txt";
int main() {
    NodeData *nd=new NodeData();
    Node *d=nd;
    d->print();
    return 0;
}
