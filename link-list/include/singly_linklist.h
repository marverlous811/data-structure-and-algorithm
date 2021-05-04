//
// Created by marverlous on 5/4/2021.
//

#ifndef ALGORITHM_AND_DATA_STRUCTURE_SINGLY_LINKLIST_H
#define ALGORITHM_AND_DATA_STRUCTURE_SINGLY_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

template<typename T>
struct LinkListNode {
    T data;
    LinkListNode *next;

    LinkListNode(T data) {
       this->data = data;
    }
};

template<typename T>
using LinklistCallback = void (*)(T);

template<typename T>
class SinglyLinkList {
public:
    SinglyLinkList();
    ~SinglyLinkList();

public:
    void addData(T data){
        LinkListNode<T>* node = new LinkListNode<T>(data);
        if(start == nullptr) {
            start = node;
            return;
        }

        LinkListNode<T>* cur = start;
        while (cur->next != nullptr) {
            cur = cur->next;
        };
        cur->next = node;
    }
    void traversalNode(LinklistCallback<T> cb) {
        LinkListNode<T> *currentNode = start;
        do {
            cb(currentNode->data);
            currentNode = currentNode->next;
        }
        while (currentNode->next != nullptr);
    }

private:
    LinkListNode<T> *start = nullptr;
};
#endif //ALGORITHM_AND_DATA_STRUCTURE_SINGLY_LINKLIST_H
