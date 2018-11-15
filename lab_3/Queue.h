#include "List.h"
class Queue:private List{
public:
    Queue(){

    }
    Node* pop_front();
    Node* pop_back();
    void push_back();
    void push_front();
    Queue search();
    Queue filter();
}
