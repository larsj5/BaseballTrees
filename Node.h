/**
 * Lars Jensen
 * CS 124
 * Section C
 */

#ifndef PROJECT1_NODE_H
#define PROJECT1_NODE_H
template<typename Object> //template

class Node{
private:
    Object item;
    //Declare a pointer to the next node
    Node* next;
public:
    Node(Object newItem){
        item = newItem;
        next = nullptr;
    }

    Node(Object newItem, Node* nextNode){
        item = newItem;
        next = nextNode;
    }

    Object getItem(){
        return item;
    }

    Node* getNext(){
        return next;
    }

    void setItem(Object newItem){
        item = newItem;
    }

    void setNext(Node* nextNode){
        next = nextNode;
    }
};

#endif //PROJECT1_NODE_H
