#include "Node.h"
#include "NodeData.h"
#include "ListException.h"
#ifndef  LIST_H
#define LIST_H

class List {
private:
    Node *first;
    Node *last;
public:
    void setFirst(Node *target){
        this->first = target;
    }
    Node* getFirst(){
        return this->first;
    }
    void setLast(Node *target){
        this->last = target;
    }
    Node* getLast(){
        return this->last;
    }
    List(){
        this->setFirst(nullptr);
        this->setLast(nullptr);
    }
    void addBegin(Node *target){
        Node *tmp = this->getFirst();
        if ( tmp == nullptr ) {
            this->last = target;
            this->first = target;
        } else {
            tmp->previous = target;
            target->next = tmp;
            this->first = target;
        }
    }
    void addEnd(Node *target){
        Node *tmp = this->getLast();
        if( tmp == nullptr ) {
            this->last = target;
            this->first = target;
        }
        else {
            tmp->next = target;
            target->previous = tmp;
            this->last = target;
        }
    }

    void print(Node * target){
        Data *hero = target->data_pointer();
        std::cout << "**********************************" << std::endl;
        std::cout << "Printing hero stats" << std::endl;
        std::cout << "Hero name : " << hero->getName() << std::endl;
        std::cout << "Hero real name : " << hero->getReal_name() << std::endl;
        std::cout << "Hero birthday : " << hero->getBd() << std::endl;
        std::cout << "Hero male : " << ( ( hero->getMale() == 0 ) ? "Man" : "Woman" ) << std::endl;
        std::cout << "Hero ability : " << hero->getAbility() << std::endl;
        std::cout << "Hero weaknesses : " << hero->getWeaknesses() << std::endl;
        std::cout << "Hero wins : " << hero->getWin_amount() << std::endl;
        std::cout << "Hero strength rating : " << hero->getStrength_rating() << std::endl;
        std::cout << "**********************************" << std::endl;
    }
    void print(){
        Node *current = this->getFirst();
        if ( current == nullptr ) {
            throw ListException();
            return;
        }
        while ( current != nullptr ) {
            print(current);
            current = current->next;
        }
    }
    Node* remove_last(){
        Node *tmp = this->getLast();
        if ( tmp != nullptr ) {
            this->setLast(tmp->previous);
            this->getLast()->next = nullptr;
            tmp->previous = nullptr;
            tmp->next = nullptr;
            return tmp;
        }else{
            throw ListException();
        }
        return nullptr;
    }
    Node* remove_first(){
        Node *tmp = this->getFirst();
        if ( tmp != nullptr ) {
            this->setFirst(tmp->next);
            this->getFirst()->previous = nullptr;
            tmp->previous = nullptr;
            tmp->next = nullptr;
            return tmp;
        }
        else{
            throw ListException();
        }
        return nullptr;
    }
};
#endif
