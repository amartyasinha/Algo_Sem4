//
// Created by amartya on 14/03/22.
//

#include <iostream>
#include <list>

using namespace std;

class Node {
public:
    int destination;
    int weight;

    Node *next;

    Node() {
        destination = 0;
        weight = 0;
        next = nullptr;
    }

    Node(int destination, int weight) {
        this->destination = destination;
        this->weight = weight;
        next = nullptr;
    }
};

class ListNode {
    Node *head;
    Node *tail;
public:
    void insertEdges(int destination, int weight) {
        Node *newNode = new Node(destination, weight);

        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {

        }
    }
};