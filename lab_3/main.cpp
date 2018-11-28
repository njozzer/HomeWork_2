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
    Queue q;
    for(int i = 0; i < 10; i++){
        strcat(name,std::to_string(i).c_str());
        NodeData *nd = new NodeData(name,real_name,bd,male,ability,weaknesses,win_amount,strength_rating);
        Node *d=(Node*)nd;
        q.push_back(d);
    }
    //asd awoidja; lkw;ld 1 alwkdj 2mclke 34 321

    char *casd=new char[10];
    /*strcpy(casd,"asd0");
    q.print();
    try{
        Queue p=q.search(casd);
        std::cout << casd << '\n';
        p.print();
    }catch(ListException e){
        std::cout << e.what() << '\n';
    }*/

    try{
        Queue p=q.filter(321,'=');
        std::cout << casd << '\n';
        p.print();
    }catch(ListException e){
        std::cout << e.what() << '\n';
    }

    try{
        Node *d=q[10];
        std::cout << d->data_pointer()->getName() << '\n';
    }catch(ListWrongIndexException e){
        std::cout << e.what() << '\n';
    }

    return 0;
}
