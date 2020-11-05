#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	Node* left;
	int data;
	Node* right;
};

class Queue {
private:
	int size;
	int front;
	int rear;
	Node** Q;
public:
	Queue() {
		size = 10;
		front = rear = -1;
		Q = new Node*[size];
	}
	Queue(int sz) {
		size = sz;
		front = rear = -1;
		Q = new Node*[size];
	}
	~Queue() {
		delete[]Q;
	}

	int isEmpty() {
		return front == rear;
	}

	int isFull() {
		return rear == (size - 1);
	}

	void enqueue(Node* data) {
		if (isFull())
			cout << "Queue is Full" << endl;
		else {
			rear++;
			Q[rear] = data;
		}
	}

	Node* dequeue() {
		Node* value = NULL;
		if (isEmpty())
			cout << "Queue is Empty" << endl;
		else {
			front++;
			value = Q[front];
		}
		return value;
	}

	void display() {
		if (isEmpty())
			cout << "Queue is empty, no elements to display" << endl;
		else {
			for (int i = front + 1; i <= rear; i++)
				cout << Q[i] << " ";
			cout << endl;
		}
	}

};
