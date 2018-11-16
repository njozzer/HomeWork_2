#include <iostream>
#include "NodeData.h"
#include "Node.h"
#include "MyException.h"
#include "List.h"
#include "Queue.h"
#include <string>
const char *path = "\\home\\njozzer\\proj\\lab_1\\data.txt";
int main() {
    char name[32];
    char real_name[32];
    char bd[32];
    int male;
    char ability[32];
    char weaknesses[128];
    int win_amount;
    double strength_rating;
    std::cin >> name;
    std::cin >> real_name;
    std::cin >> bd;
    std::cin >> male;
    std::cin >> ability;
    std::cin >> weaknesses;
    std::cin >> win_amount;
    std::cin >> strength_rating;
    List lst;
    Queue q;
    for(int i = 0; i < 10; i++){
        strcat(name,std::to_string(i).c_str());
        NodeData *nd = new NodeData(name,real_name,bd,male,ability,weaknesses,win_amount,strength_rating);
        Node *d=(Node*)nd;
        lst.addEnd(d);
        q.push_back(d);
    }
    q.print();
    std::cout << q.getFirst()->data_pointer()->getName() << '\n';
    return 0;
}
