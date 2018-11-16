#include "List.h"
#include "Node.h"
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
    Queue search(char *name){
        Queue q;
        Node *tmp = this->getFirst();
        if (current == nullptr) {
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
    Queue filter(){

    }
};
