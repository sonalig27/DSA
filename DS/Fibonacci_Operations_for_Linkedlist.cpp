#include<iostream>
#include <set>
#include <climits>
#include <vector>
using namespace std;

set<int> fibNums;

void createFibSet(int maxElement) {
	int term1 = 0;
	int term2 = 1;
	int newTerm = term1 + term2;
	fibNums.insert(term1);
	fibNums.insert(term2);
	while (newTerm <= maxElement) {
		fibNums.insert(newTerm);
		term1 = term2;
		term2 = newTerm;
		newTerm = term1 + term2;
	}
}

vector<int> fibList(int maxElement) {
    vector<int> fibVec = {1,2};
    int term1 = 1;
    int term2 = 2;
    int newTerm = term1 + term2;
	while (newTerm <= maxElement) {
		fibVec.push_back(newTerm);
		term1 = term2;
		term2 = newTerm;
		newTerm = term1 + term2;
	}
	return fibVec;
}


class Node {
public:
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() {
		head = NULL;
	}
	void printFibNodes() {
		Node* temp = head;
		if (temp == NULL) {
			cout << "List is Empty" << endl;
		}
		cout << "Fib nodes in the List are: ";
		while (temp != NULL) {
			if (fibNums.count(temp->data) != 0)
				cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	
	int countNodes() {
		Node* temp = head;
		int count = 0;
		if (temp == NULL) {
			cout << "There are no nodes in the list" << endl;
			return count;
		}
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}
		return count;
	}
	int countFibNodes() {
		Node* temp = head;
		int count = 0;
		if (temp == NULL) {
			cout << "The list is empty, so it doesn't contain any fibonacci numbers" << endl;
			return count;
		}
		while (temp != NULL) {
			if (fibNums.count(temp->data) != 0)
				count++;
			temp = temp->next;
		}
		return count;
	}
	int minFibNode() {
		Node* temp = head;
		int min = INT_MAX;
		if (temp == NULL) {
			cout << "Can't find minimum fibonacci element in an empty list" << endl;
			return min;
		}
		while (temp != NULL) {
			if (fibNums.count(temp->data) != 0 && temp->data < min) {
				min = temp->data;
			}
			temp = temp->next;
		}
		return min;
	}
	int maxFibNode() {
		Node* temp = head;
		int max = INT_MIN;
		if (temp == NULL) {
			cout << "Can't find maximum fibonacci element in an empty list" << endl;
			return max;
		}
		while (temp != NULL) {
			if (fibNums.count(temp->data) != 0 && temp->data > max) {
				max = temp->data;
			}
			temp = temp->next;
		}
		return max;
	}

	void deleteFibNodes() {
		Node* temp = head;
		if (temp == NULL) {
			cout << "List is empty, so no fibonacci numbers to delete" << endl;
		}
		else {
			Node* follow = NULL;
			while (temp != NULL) {
				if (fibNums.count(temp->data) != 0) {
					if (temp == head) {
						cout << temp->data << endl;
						Node* newNode = new Node();
						newNode = head;
						head = head->next;
						delete newNode;
						temp = head;
					}
					else {
						follow->next = temp->next;
						delete temp;
						temp = follow->next;
					}
				}
				else {
					follow = temp;
					temp = temp->next;
				}
			}

		}
	}
	void display() {
		Node* temp = head;
		if (temp == NULL) {
			cout << "List is Empty" << endl;
		}
		cout << "List is: ";
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	int maxElement() {
		Node* temp = head;
		int max = INT_MIN;
		if (temp == NULL) {
			cout << "Can't find maximum value element in an empty list" << endl;
			return max;
		}
		while (temp != NULL) {
			if (temp->data > max) {
				max = temp->data;
			}
			temp = temp->next;
		}
		return max;
	}
	void addHeadElement(int value) {
		Node* temp = new Node();
		temp->data = value;
		temp->next = head;
		head = temp;
	}
	
	void deleteElement(int index) {
	        if (index == 1) {
			Node* newNode = new Node();
			newNode = head;
			head = head->next;
			delete newNode;
		    }else{
		        Node* temp = head->next;
			    Node* follow = head;
			    for (int i = 1; i < index - 1; i++) {
				    follow = temp;
				    temp = temp->next;
			    }
			    follow->next = temp->next;
			    delete temp;
		    }
	}
	
	void deleteFibIndexNodes() {
		Node* temp = head;
		if (temp == NULL) {
			cout << "List is empty, so no fibonacci numbers to delete" << endl;
		}
		else {
		    vector<int> fibSeries = fibList(this->countNodes());
		    
		    for(int value : fibSeries){
		        if(value < this->countNodes())
		            this->deleteElement(value);
		    }
	    }
	}

};

int main()
{
	LinkedList* list = new LinkedList();
	list->addHeadElement(13);
	list->addHeadElement(21);
	list->addHeadElement(8);
	list->addHeadElement(16);
	list->addHeadElement(15);
	int largest = list->maxElement();
	createFibSet(largest);

	// 	for (set<int>::iterator it = fibNums.begin(); it != fibNums.end(); ++it)
	// 		std::cout << ' ' << *it;
	list->printFibNodes();
	cout << "The number of fibonacci nodes is: " << list->countFibNodes() << endl;
	cout << "Minimum fibonacci node is : " << list->minFibNode() << endl;
	cout << "Maximum fibonacci node is : " << list->maxFibNode() << endl;
	cout << "List before deleting the fibonacci nodes: " << endl;
	list->display();
	list->deleteFibNodes();
	cout << "List after deleting the fibonacci nodes: " << endl;
	list->display();
	
	LinkedList* list2 = new LinkedList();
	
	list2->addHeadElement(2);
	list2->addHeadElement(5);
	list2->addHeadElement(6);
	list2->addHeadElement(8);
	list2->addHeadElement(9);
	list2->addHeadElement(10);
	list2->addHeadElement(1);
	list2->addHeadElement(13);
	list2->addHeadElement(15);
	list2->addHeadElement(7);
	
 	list2->deleteFibIndexNodes();
	list2->display();
	return 0;
}
