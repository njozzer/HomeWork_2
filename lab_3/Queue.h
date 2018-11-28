#include "List.h"
#include "Node.h"
#include "Data.h"
#include "ListWrongIndexException.h"
#include "ListFileReadException.h"
#include "NodeData.h"
class Queue : private List {
private:
    using List::addEnd;
    using List::addBegin;
    using List::remove_first;
    using List::remove_last;
public:

    using List::print;
    using List::getFirst;
    using List::setFirst;
    using List::getLast;
    using List::setLast;
    Queue(){

    }
    Node* pop_front(){
        return remove_first();
    }
    Node* pop_back(){
        return remove_last();
    }
    void push_back(Node * target){
        addEnd(target);
    }
    void push_front(Node * target){
        addBegin(target);
    }
    Node *copy(Node *target){
        Data *sh=target->data_pointer();
        return new NodeData(sh->getName(), sh->getReal_name(), sh->getBd(), sh->getMale(), sh->getAbility(),
                             sh->getWeaknesses(), sh->getWin_amount(), sh->getStrength_rating());
    }

    Queue search(char *name){
        Queue q;
        Node *current = this->getFirst();
        if (current == nullptr) {
            std::cout << getFirst()->data_pointer() << '\n';
            throw ListException();
        }
        while (current != nullptr) {
            int cmp = strcmp(name, current->data_pointer()->getName());
            if (cmp == 0) {

                q.push_back(copy(current));
            }
            current = current->next;
        }
        return q;
    }
    Queue filter(double strength_rating, char c){
        Queue q;
        Node *current = getFirst();
        if (current == nullptr) {
            return q;
        } else {
            switch (c) {
                case '<': {
                    while (current != nullptr) {
                        if (current->data_pointer()->getStrength_rating() < strength_rating) {
                            q.push_back(copy(current));
                        }
                        current = current->next;
                    }
                    break;
                }
                case '=': {
                    while (current != nullptr) {
                        if (current->data_pointer()->getStrength_rating() == strength_rating) {
                            q.push_back(copy(current));
                        }
                        current = current->next;
                    }
                    break;
                }
                case '>': {
                    while (current != nullptr) {
                        if (current->data_pointer()->getStrength_rating() > strength_rating) {
                            q.push_back(copy(current));
                        }
                        current = current->next;
                    }
                    break;
                }
            }
        }
        return q;
    }
    Node *operator[](int i) {

        if (i >= 0){
            Node *curr = getFirst();
            int j = 0;
            while (curr != nullptr && i != j) {
                curr = curr->next;
                j++;
            }
            if(curr==nullptr){
                throw ListWrongIndexException();
            }
            if(abs(i)!=j){
                throw ListWrongIndexException();
            }
            return curr;
        }
        if(i < 0){
            Node *curr = getLast();
            int j = 0;
            while (curr != nullptr && abs(i) != j) {
                curr = curr->previous;
                j++;
            }
            if(curr == nullptr){
                throw ListWrongIndexException();
            }
            if(abs(i)!=j){
                throw ListWrongIndexException();
            }
            return curr;
        }

        return nullptr;
    }
};
