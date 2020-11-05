#include <iostream>
using namespace std;

class Stack{
	private:
		int size;
		int top;
		int *st;
	public:
		Stack(){
			size = 5;
			top = -1;
			st = new int[5];
		}
		Stack(int sz){
			size = sz;
			top = -1;
			st = new int[size];
		}
		~Stack(){
			delete []st;
		}

		int isEmpty(){
			if(top == -1)
				return 1;
			else
				return 0;
		}
		int isFull(){
			if(top == size-1)
				return 1;
			else
				return 0;
		}
		void push(int data){
			if(isFull())
				cout<<"Stack is Full."<<endl;
			else{
				top++;
				st[top] = data;
			}
		}
		int pop(){
			int value;
			if(isEmpty())
				return -1;
			else{
				value = st[top];
				top--;
				return value;
			}
		}
		int stackTop(){
			if(isEmpty())
				return -1;
			else
				return st[top];
		}
		int peek(int pos){
			if(top-pos+1 < 0)
				return -1;
			else
				return st[top-pos+1];
		}
		void display(){
			if(top == -1)
				cout << "stack is empty" <<endl;
			else{
				for(int i = top; i >= 0  ; i--)
						cout<<st[i]<<" ";
				cout<<endl;
			}
		}
};