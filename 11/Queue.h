#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>
#include <queue>
using namespace std;
// элемент очереди
struct Node {
    int data;
    int priority;
    Node* next;
};
// очередь с приоритетами
struct PriorityQueue {
    Node* head;
    int size;
    int maxSize;
};
// прототипы функций
void initQueue(PriorityQueue& q, int N);
void push(PriorityQueue& q, int value, int priority);
void pop(PriorityQueue& q, int& value, int& priority);
void printQueue(PriorityQueue q);
void clearQueue(PriorityQueue& q);
#endif