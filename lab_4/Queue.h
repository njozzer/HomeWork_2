#include <iostream>
template < typename T >
class Node {
    T data;
    Node < T > *next;
    Node < T > *prev;
public:
    Node < T > *getNext(){
        return next;
    }
    Node < T > *getPrev(){
        return prev;
    }
    void setNext(Node < T > *tmp){
        next = tmp;
    }
    void setPrev(Node < T > *tmp){
        prev = tmp;
    }
    T getData(){
        return data;
    }
    void setData(T tmp){
        data = tmp;
    }
    Node(T tmp){
        setData(tmp);
        next = nullptr;
        prev = nullptr;
    }
};

template < typename T >
int less(T a, T b ){
    return a < b ? 1 : 0;
}

template < typename T >
int greater(T a, T b ){
    return a > b ? 1 : 0;
}

template < typename T >
int equal(T a, T b ){
    return a == b ? 1 : 0;
}

template < typename T,size_t capacity = -1 >
class Queue {
    Node < T > *first;
    Node < T > *last;
public:
    void setFirst(Node < T > *tmp){
        first = tmp;
    }
    Node < T >* getFirst(){
        return first;
    }
    void setLast(Node < T > *tmp){
        last = tmp;
    }
    Node < T >* getLast(){
        return last;
    }
    Queue(){
        first = nullptr;
        last = nullptr;
    }
    void push_back(T t){
        Node < T > *curr = getLast();
        if( curr == nullptr ) {

            Node < T > *node = new Node < T > (t);
            setLast(node);
            setFirst(node);
        }else{
            Node < T > *node = new Node < T > (t);
            curr->setNext(node);
            node->setPrev(curr);
            setLast(node);
        }
    }
    void push_front(T t){
        Node < T > *curr = getFirst();
        if( curr == nullptr ) {
            Node < T > *node = new Node < T > (t);
            setLast(node);
            setFirst(node);
        }else{
            Node < T > *node = new Node < T > (t);
            curr->setPrev(node);
            node->setNext(curr);
            setFirst(node);
        }
    }
    void print(){
        Node < T > *curr = getFirst();
        while( curr != nullptr ) {
            std::cout << curr->getData() << '\n';
            curr = curr->getNext();
        }
    }
    Queue < T > filter(T data,int ( *func )(T a,T b) ){
        Queue < T > q;
        Node < T > *curr = getFirst();
        while( curr != nullptr ) {
            if( ( *func )(curr->getData(),data) ) {
                q.push_back(curr->getData() );
            }
            curr = curr->getNext();
        }
        return q;
    }
    Queue < T > search(T data,int ( *func )(T a,T b) ){
        Queue < T > q;
        Node < T > *curr = getFirst();
        while( curr != nullptr ) {
            if( ( *func )(curr->getData(),data) ) {
                q.push_back(curr->getData() );
            }
            curr = curr->getNext();
        }
        return q;
    }
};
