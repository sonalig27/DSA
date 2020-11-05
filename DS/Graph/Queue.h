#pragma once
#include <iostream>
using namespace std;

class Queue {
private:
	int size;
	int front;
	int rear;
	int* Q;
public:
	Queue() {
		size = 10;
		front = rear = -1;
		Q = new int[size];
	}
	Queue(int sz) {
		size = sz;
		front = rear = -1;
		Q = new int[size];
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

	void enqueue(int data) {
		if (isFull())
			cout << "Queue is Full" << endl;
		else {
			rear++;
			Q[rear] = data;
		}
	}

	int dequeue() {
		int value = -1;
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
