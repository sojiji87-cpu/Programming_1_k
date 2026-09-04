//#include "Queue.h"
//
////объединенный конструктор с параметрами по умолчанию
//PriorityQueue::PriorityQueue(int N) : head(nullptr), size0(0), maxSize(N) {} 
//
////копирование
//PriorityQueue::PriorityQueue(const PriorityQueue& q): head(nullptr), size0(q.size0), maxSize(q.maxSize)
//	{
//	if (q.head == nullptr) return;
//	head = new Node(q.head->data, q.head->p);
//	Node* cur = head;
//	Node* curQ = q.head->next;
//	while (curQ != nullptr) {
//			cur->next = new Node(curQ->data, curQ->p);
//			cur = cur->next;
//			curQ = curQ->next;
//	}
//}
//
////деструктор
//PriorityQueue::~PriorityQueue() {clear();}
//
////добавление элемента
//void PriorityQueue::push(int v, int p) {
//	if (size0 == maxSize) {
//		cout << "Очередь уже заполнена! Новый элемент не будет добавлен.";
//		return;
//	}
//	Node* newNode = new Node(v, p);
//	if (!head || p > head->p) {
//		newNode->next = head;
//		head = newNode;
//	}
//	else {
//		Node* cur = head;
//		while (cur->next && cur->next->p >= p) {
//			cur = cur->next;
//		}
//		newNode->next = cur->next;
//		cur->next = newNode;
//	}
//	size0++;
//}
//
////удаление элемента
//void PriorityQueue::pop(int& v, int& p) {
//	if (!head) {
//		cout << "Очередь пуста!";
//		return;
//		}
//	v = head->data;
//	p = head->p;
//	Node* temp = head;
//	head = head->next;
//	delete temp;
//	size0--;
//}
//
////очистка
//void PriorityQueue::clear() {
//	while (head) {
//		Node* temp = head;
//		head = head->next;
//		delete temp;
//	}
//	size0 = 0;
//}
//
////вывод
//void PriorityQueue::print() const {
//	if (!head) {
//		cout << "Очередь пуста!";
//		return;
//	}
//	Node* cur = head;
//	while (cur != nullptr) {
//		cout << cur->data << " ";
//		cur = cur->next;
//	}
//	cout << endl;
//}
//
////конструктор инициализации через initializer_list
//PriorityQueue::PriorityQueue(initializer_list <int> list): head(nullptr), size0(0), maxSize(static_cast<int>(list.size()))
//{									//maxSize(list.size) возвращает size_t - поэтому static_cast<int>
//	for (int v : list) {
//		push(v, v); // приоритет=значение
//	}
//}