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
       this->next = NULL;
    }
    LinkListNode(){
        this->next = NULL;
    }
};

template<typename T>
using LinklistCallback = void (*)(T);

template<typename T>
class SinglyLinkList {
public:
    SinglyLinkList(){
        start = new LinkListNode<T>();
    }
    ~SinglyLinkList();

public:
    void addData(T data){
        auto node = new LinkListNode<T>(data);

        LinkListNode<T>* cur = start;
        while (cur->next != NULL) {
            cur = cur->next;
        };
        cur->next = node;
    }
    void foreach(LinklistCallback<T> cb) {
        LinkListNode<T> *currentNode = start->next;
        while (currentNode != NULL) {
            cb(currentNode->data);
            currentNode = currentNode->next;
        }
    }

    LinkListNode<T>* deleteNode(int idx) {
        int curIdx = 0;
        LinkListNode<T> *prev = start;
        LinkListNode<T> *cur = prev->next;
        while (cur != NULL){
            if(curIdx == idx) {
                prev->next = cur->next;
                cur->next = NULL;
                return cur;
            }

            prev = cur;
            cur = cur->next;
            curIdx++;
        }

        return nullptr;
    }

    int length(){
        int curIdx = 0;
        LinkListNode<T> *currentNode = start->next;
        while (currentNode != NULL) {
            curIdx++;
            currentNode = currentNode->next;
        }
        return curIdx;
    }

    void findIndex(int idx, LinklistCallback<T> cb) {
        int curIdx = 0;
        LinkListNode<T> *currentNode = start->next;
        while (currentNode != NULL) {
            if(curIdx == idx) {
                cb(currentNode->data);
            }
            curIdx++;
            currentNode = currentNode->next;
        }
    }

    void deleteList(){
        int len = this->length();
        for(int i = len - 1; i >= 0; i--){
            this->deleteNode(i);
        }
    }

private:
    LinkListNode<T> *start = NULL;
};
#endif //ALGORITHM_AND_DATA_STRUCTURE_SINGLY_LINKLIST_H
