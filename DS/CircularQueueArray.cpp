#include <iostream>
using namespace std;

class Queue{
	private:
		int size;
		int front;
		int rear;
		int *Q;
	public:
		Queue(){
			size = 10;
			front = rear = 0;
			Q = new int[size];
		}
		Queue(int sz){
			size = sz;
			front = rear = 0;
			Q = new int[size];
		}
		~Queue(){
			delete []Q;
		}

		int isEmpty(){
			return front == rear;
		}

		int isFull(){
			return ((rear + 1) % size) == front;
		}

		void enqueue(int data){
			if(isFull())
				cout <<"Queue is Full"<<endl;
			else{
				rear= (rear + 1) % size;
				Q[rear] = data;
			}
		}

		int dequeue(){
			int value = -1;
			if(isEmpty())
				cout<<"Queue is Empty"<<endl;
			else{
				front = (front + 1) % size;
				value = Q[front];
			}
			return value;
		}

		void display(){
			if(isEmpty())
				cout <<"Queue is empty, no elements to display"<<endl;
			else{
			    int i = front + 1;
				do{
					cout<<Q[i]<<" ";
					i = (i + 1) % size;
				}while(i != (rear + 1) % size);
				cout<<endl;
			}
		}

};


int main(){
	Queue* q1 = new Queue(5);
	cout << q1->isEmpty() << endl;
	cout << q1->isFull() << endl;
	q1->enqueue(10);
	q1->enqueue(8);
	q1->enqueue(6);
	q1->enqueue(4);
	q1->enqueue(2);
	q1->enqueue(0);
	q1->display();
	cout << q1->isEmpty() << endl;
	cout << q1->isFull() << endl;
	cout << q1->dequeue() << endl;
	cout << q1->dequeue() << endl;
	q1->display();
	return 0;
}
