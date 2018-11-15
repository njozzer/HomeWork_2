#include "Node.h"
#include "NodeData.h"

class List{
private:
    Node *first;
    Node *last;
public:
    List(){
        this->first = nullptr;
        this->last = nullptr;
    }
    void add(){

    }
    void addBegin(Node *target){
        Node *tmp = this->first;
        if (tmp == nullptr) {
            this->last = target;
            this->first = target;
        } else {
            tmp->previous = target;
            target->next = tmp;
            this->first = target;
        }
    }
    void addEnd(Node *target){
        Node *tmp = this->last;
        if(tmp == nullptr){
            this->last = target;
            this->first = target;
        }
        else {
            tmp->next = target;
            target->previous = tmp;
            this->last = target;
        }
    }
    Node *remove_first(){
        return this->first;
    }
    void print(Node * target){
        Data *hero=target->data_pointer();
        std::cout << "**********************************" << std::endl;
        std::cout << "Printing hero stats" << std::endl;
        std::cout << "Hero name : " << hero->getName() << std::endl;
        std::cout << "Hero real name : " << hero->getReal_name() << std::endl;
        std::cout << "Hero birthday : " << hero->getBd() << std::endl;
        std::cout << "Hero male : " << ((hero->getMale() == 0) ? "Man" : "Woman") << std::endl;
        std::cout << "Hero ability : " << hero->getAbility() << std::endl;
        std::cout << "Hero weaknesses : " << hero->getWeaknesses() << std::endl;
        std::cout << "Hero wins : " << hero->getWin_amount() << std::endl;
        std::cout << "Hero strength rating : " << hero->getStrength_rating() << std::endl;
        std::cout << "**********************************" << std::endl;
    }
};
