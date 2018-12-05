#include <iostream>
#include "Queue.h"
int main() {
    Queue < int > lst;
    lst.push_back(2);
    lst.push_back(1);
    lst.push_back(5);
    lst.push_back(0);
    lst.print();
    Queue < int > lst2 = lst.filter(3,&greater);
    std::cout << "****" << '\n';
    lst2.print();

    return 0;
}
