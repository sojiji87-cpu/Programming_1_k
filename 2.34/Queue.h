#pragma once
#include <iostream>
#include <initializer_list> 
using namespace std;

template <typename T>
class PriorityQueue {

private:
    class Node {
    public:
        T data; //значение
        int p; //приоритет
        Node* next; //указатель на след
        Node(T d, int p, Node* n = nullptr) : data(d), p(p), next(n) {}
    };
    Node* head; //голова
    int size0; //счетчик
    int maxSize;

public:
    PriorityQueue(int N = 0); //объединенный конструктор с параметрами по умолчанию
    PriorityQueue(const PriorityQueue& other); // конструктор копирования
    ~PriorityQueue(); //деструктор
    void push(T v, int p); //добавление элемента
    void pop(T& v, int& p); //удаление элемента
    //void print() const; //вывод
    void clear(); //очистка
    int size() const { //длина очереди
        return size0;
    }
    PriorityQueue(initializer_list <T> list); //конструктор инициализации через initializer_list

    // =
    PriorityQueue& operator=(const PriorityQueue& other);
    // оператор вывода
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const PriorityQueue<U>& q);
    // бинарный +
    PriorityQueue operator+(const PriorityQueue& other) const;
};

//объединенный конструктор с параметрами по умолчанию
template <typename T>
PriorityQueue<T>::PriorityQueue(int N) : head(nullptr), size0(0), maxSize(N) {}

//копирование
template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& other) : head(nullptr), size0(other.size0), maxSize(other.maxSize)
{
    if (other.head == nullptr) return;
    head = new Node(other.head->data, other.head->p);
    Node* cur = head;
    Node* curOther = other.head->next;
    while (curOther != nullptr) {
        cur->next = new Node(curOther->data, curOther->p);
        cur = cur->next;
        curOther = curOther->next;
    }
}

//деструктор
template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    clear();
}

//добавление элемента
template <typename T>
void PriorityQueue<T>::push(T v, int p) {
    if (maxSize != 0 && size0 == maxSize) {
        cout << "Очередь уже заполнена! Новый элемент не будет добавлен.\n";
        return;
    }
    Node* newNode = new Node(v, p);
    if (!head || p > head->p) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* cur = head;
        while (cur->next && cur->next->p >= p) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
    size0++;
}

//удаление элемента
template <typename T>
void PriorityQueue<T>::pop(T& v, int& p) {
    if (!head) {
        cout << "Очередь пуста! Новый элемент не будет добавлен";
        return;
    }
    v = head->data;
    p = head->p;
    Node* temp = head;
    head = head->next;
    delete temp;
    size0--;
}

//очистка
template <typename T>
void PriorityQueue<T>::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size0 = 0;
}

//конструктор инициализации через initializer_list
template <typename T>
PriorityQueue<T>::PriorityQueue(initializer_list <T> list) : head(nullptr), size0(0), maxSize(static_cast<int>(list.size())) {
    for (const T& v : list) {     //maxSize(list.size) возвращает size_t - поэтому static_cast<int>
        push(v, v); // приоритет=значение
    }
}

//=
template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& other) {
    if (this == &other) return *this;
    clear();
    maxSize = other.maxSize;
    size0 = other.size0;
    if (!other.head) {
        head = nullptr;
        return *this;
    }
    head = new Node(other.head->data, other.head->p);
    Node* curThis = head;
    Node* curOther = other.head->next;
    while (curOther) {
        curThis->next = new Node(curOther->data, curOther->p);
        curThis = curThis->next;
        curOther = curOther->next;
    }
    return *this;
}

//<<
template <typename U>
std::ostream& operator<<(std::ostream& os, const PriorityQueue<U>& q){
    typename PriorityQueue<U>::Node* cur = q.head;
    if (!cur) {
        os << "Очередь пуста!";
        return os;
    }
    while (cur) {
        os << cur->data << " ";
        cur = cur->next;
    }
    os << endl;
    return os;
}

//+
template <typename T>
PriorityQueue<T> PriorityQueue<T>::operator+(const PriorityQueue<T>& other) const {
    PriorityQueue<T> result(*this);
    if (!other.head) return result;
    Node* cur = other.head;
    Node* maxNode = cur;
    while (cur) {
        if (cur->p > maxNode->p) maxNode = cur;
        cur = cur->next;
    }
    T addValue = maxNode->data;
    Node* curRes = result.head;
    while (curRes) {
        curRes->data += addValue;
        curRes = curRes->next;
    }
    return result;
}