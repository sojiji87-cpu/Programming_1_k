#include "Queue.h"
#include <iostream>
#include <queue>
using namespace std;

// инициализация очереди
void initQueue(PriorityQueue& q, int N) {
    q = { nullptr, 0, N };
}
// добавление элемента
void push(PriorityQueue& q, int value, int priority) {
    if (q.size == q.maxSize) {
        cout << "Очередь уже заполнена! Новый элемент не будет добавлен.\n";
        return;
    }
    Node* newNode = new Node{ value, priority, nullptr };
    Node** cur = &q.head;
    // ищем место вставки: пока существует элемент и его приоритет >= нового
    while (*cur && (*cur)->priority >= priority) cur = &(*cur)->next;
    newNode->next = *cur;
    *cur = newNode;

    q.size++;
}
// вывод очереди
void printQueue(PriorityQueue q) {
    Node* cur = q.head;
    if (cur != nullptr) {
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    else cout << "Очередь пуста!" << endl;
}
// функция top, возвращает данные из головы очереди
void top(const PriorityQueue& q, int& value, int& priority) {
    if (q.size == 0) return;  // очередь пуста
    value = q.head->data;
    priority = q.head->priority;
}
//выбор элемента из очереди (из начала списка) 
void pop(PriorityQueue& q, int& value, int& priority) {
    if (q.size == 0) {
        cout << "Очередь пуста!\n";
        return;
    }
    value = q.head->data;
    priority = q.head->priority;
    Node* temp = q.head;
    q.head = q.head->next;
    delete temp;
    q.size--;
}

void clearQueue(PriorityQueue& q) {
    while (q.head) {
        Node* temp = q.head;
        q.head = q.head->next;
        delete temp;
    }
    q.size = 0;
}