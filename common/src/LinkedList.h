//
// Created by Oleksandra Baukh on 1/19/18.
//

#ifndef CPP_PLAYGROUND_LINKEDLIST_H
#define CPP_PLAYGROUND_LINKEDLIST_H

#include "List.h"

template<class T>
class LinkedList : public List<T> {
    struct Node {
        T *data;
        Node *prev, *next;

        Node(T *obj) : data(obj), prev(nullptr), next(nullptr) {}
    };

    Node *left = nullptr, *right = nullptr;
    int length = 0;

    void removeNode(Node *node) {
        if (node == nullptr) {
            return;
        }
        Node *previous = node->prev;
        Node *next = node->next;
        if (previous != nullptr) {
            previous->next = next;
        }
        if (next != nullptr) {
            next->prev = previous;
        }
        length--;
    }

    Node *findNode(int index) {
        if (index >= length) {
            return nullptr;
        }

        int startIndex = 0;
        Node *currentNode = right;
        while (startIndex != index) {
            currentNode = currentNode->next;
            startIndex++;
        }
        return currentNode;
    }

public:


    void add(T *e) override {
        if (left == nullptr && right == nullptr) {
            left = new Node(e);
            right = left;
        } else {
            auto *node = new Node(e);
            node->prev = left;
            left->next = node;
            left = node;
        }
        length++;
    }

    int size() override {
        return length;
    }


    T *remove(int index) override {
        Node *node = findNode(index);
        removeNode(node);
        T *data = node->data;
        return data;
    }


    T *get(int index) override {
        Node *pNode = findNode(index);
        if (pNode == nullptr) {
            return nullptr;
        }
        return pNode->data;
    }

    Iterator<T> &iterator() override {
        return *new LinkedListIterator(*this);
    }

    class LinkedListIterator : public Iterator<T> {
        Node *currentNode;
        LinkedList &list;

    public:
        explicit LinkedListIterator(LinkedList &pList) : currentNode(pList.right), list(pList) {

        }

        bool hasNext() override {
            return currentNode != nullptr;
        }

        T *next() override {
            if (currentNode != nullptr) {
                T *data = currentNode->data;
                currentNode = currentNode->next;
                return data;
            } else {
                return nullptr;
            }
        }

        T *remove() override {
            if (currentNode == nullptr) {
                return nullptr;
            }
            T *data = currentNode->data;
            list.removeNode(currentNode);
            currentNode = currentNode->next;
            return data;
        }
    };
};


#endif //CPP_PLAYGROUND_LINKEDLIST_H
