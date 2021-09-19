//
// Created by marverlous on 5/6/2021.
//

#ifndef ALGORITHM_AND_DATA_STRUCTURE_DOUBLY_LINKLIST_H
#define ALGORITHM_AND_DATA_STRUCTURE_DOUBLY_LINKLIST_H

#include "singly_linklist.h"

template<typename T>
struct DLinklistNode {
    T data;
    DLinklistNode *next = NULL, *prev = NULL;

    DLinklistNode(T data) {
        this->data = data;
    }
    DLinklistNode(){}
};

template<typename T>
class DoublyLinklist {
public:
    DoublyLinklist(){
        start = new DLinklistNode();
        end = new DLinklistNode();

        start->next = end;
        end->prev = start;
    }

private:
    DLinklistNode<T> *start = NULL, *end = NULL;
};

#endif //ALGORITHM_AND_DATA_STRUCTURE_DOUBLY_LINKLIST_H
