#include <iostream>
#include "SuperHero.h"
#include <cstring>

using namespace Heroes;
const char *path = "D:\\programming\\C_LAB\\LAB_1\\data.txt";

//search name
//filter strength_rating
int main() {
    SuperHero *sh = new SuperHero();
    std::cin >> sh;
    std::cout << sh;
    /*DeQuSH dq;
    dq.load(path);
    dq.print();*/
    return 0;
}