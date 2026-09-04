#ifndef QUEUE_H
#define QUEUE_H    
#include <iostream>
#include <ostream>
#include <initializer_list> 
using namespace std;

template <typename T>
class PriorityQueue {

	struct It {
		T value;
		int priority;
		It(T v, int p) : value(v), priority(p) {}
	};

private:
	class Node {
	public:
		T data; //значение
		int p; //приоритет
		Node* next; //указатель на следующий элемент
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
	void print() const; //вывод
	void clear(); //очистка
	int size() const { //длина очереди
		return size0;
	}
	PriorityQueue(initializer_list<It> list);

	//перегрузка присваивания
	PriorityQueue& operator=(const PriorityQueue<T>& other);

	//перегрузка вывода
	template <typename U>
	friend ostream& operator<<(ostream& cout, const PriorityQueue<U>& q);

	//бинарный плюс
	PriorityQueue<T> operator+(const PriorityQueue<T>& other);
};
#endif

//объединенный конструктор с параметрами по умолчанию
template <typename T>
PriorityQueue<T>::PriorityQueue(int N) : head(nullptr), size0(0), maxSize(N) {}

//копирование
template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& q) : head(nullptr), size0(q.size0), maxSize(q.maxSize)
{
	if (q.head == nullptr) return;
	head = new Node(q.head->data, q.head->p);
	Node* newq = head;
	Node* curQ = q.head->next;
	while (curQ != nullptr) {
		newq->next = new Node(curQ->data, curQ->p);
		newq = newq->next; 
		curQ = curQ->next;
	}
}

//деструктор
template <typename T>
PriorityQueue<T>::~PriorityQueue() { clear(); }

//добавление элемента
template <typename T>
void PriorityQueue<T>::push(T v, int p) {
	if (size0 == maxSize) {
		cout << "Очередь уже заполнена! Новый элемент не будет добавлен.";
		return;
	}
	Node* newNode = new Node(v, p);
	if (!head || p > head->p) {
		newNode->next = head;
		head = newNode;
	}
	else {
		Node* cur = head;
		while (cur->next && cur->next->p >= p ) {
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
		cout << "Очередь пуста!";
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

//вывод
template <typename T>
void PriorityQueue<T>::print() const {
	if (!head) {
		cout << "Очередь пуста!";
		return;
	}
	Node* cur = head;
	while (cur != nullptr) {
		cout << cur->data << "," << cur->p << "\t";
		cur = cur->next;
	}
	cout << endl;
}

//initializer_list
template <typename T>
PriorityQueue<T>::PriorityQueue(std::initializer_list<It> list) : head(nullptr), size0(0), maxSize(static_cast<int>(list.size())) {
	for (const auto& it : list) push(it.value, it.priority);
}

//=
template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& q) {
	if (this == &q) return *this;		//если самокопирование
	clear();
	maxSize = q.maxSize;
	size0 = q.size0;

	if (!q.head) {						//если исходная очередь пустая
		head = nullptr;
		return *this;
	}
	head = new Node(q.head->data, q.head->p); //создаем 1 узел
	Node* endNew = head; 
	Node* curQ = q.head->next; //сдвиг до 2 эл-а

	while (curQ) {
		endNew->next = new Node(curQ->data, curQ->p);
		endNew = endNew->next;		
		curQ = curQ->next;
	}
	return *this;
}

//<<
template <typename U>
std::ostream& operator<<(std::ostream& cout, const PriorityQueue<U>& q) {
	typename PriorityQueue<U>::Node* cur = q.head;
	if (!cur) {			//если очередь пуста
		cout << "Очередь пуста!";
		return cout;
	}
	while (cur) {
		cout << cur->data << "," << cur->p << "\t";
		cur = cur->next;
	}
	cout << endl;
	return cout;
}

//+
template <typename T>
PriorityQueue<T> PriorityQueue<T>::operator+(const PriorityQueue<T>& q2) {
	PriorityQueue<T> result = *this;
	Node* curq1 = result.head;
	while (curq1) {
		Node* curq2 = q2.head;
		while (curq2) { 
			if (curq2->p == curq1->p) {
				curq1->data += curq2->data;
				break;
			}
			curq2 = curq2->next;
		}
		curq1 = curq1->next;
	}
	return result;
}