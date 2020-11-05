#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class LinkedList{
private:
	Node* head;
	Node* tail;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
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
	void addHeadElement(int value) {
		Node* temp = new Node();
		temp->data = value;
		temp->next = head;
		head = temp;
		if (head->next == NULL) {
			tail = head;
		}
	}
	void addTailElement(int value) {
		Node* temp = new Node();
		temp->data = value;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
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
	int sumAllElements() {
		Node* temp = head;
		int sum = 0;
		if (temp == NULL) {
			cout << "List has no elements to sum" << endl;
			return sum;
		}
		while (temp != NULL) {
			sum += temp->data;
			temp = temp->next;
		}
		return sum;
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

	int minElement() {
		Node* temp = head;
		int min = INT_MAX;
		if (temp == NULL) {
			cout << "Can't find minimum value element in an empty list" << endl;
			return min;
		}
		while (temp != NULL) {
			if (temp->data < min) {
				min = temp->data;
			}
			temp = temp->next;
		}
		return min;
	}

	int searchElement(int key) {
		Node* temp = head;
		int index = 0;
		if (temp == NULL) {
			cout << "List is Empty, element not found" << endl;
			return -1;
		}
		while (temp != NULL) {
			if (temp->data == key) {
				return index;
			}
			temp = temp->next;
			index++;
		}
		return -1;
	}
	int improvedSearchElement(int key) {
		Node* temp = head;
		Node* follow = NULL;
		int index = 0;
		if (temp == NULL) {
			cout << "List is Empty, element not found" << endl;
			return -1;
		}else if (temp->data == key) {
			return index;
		}
		else {
			while (temp != NULL) {
				if (temp->data == key) {
					follow->next = temp->next;
					temp->next = head;
					head = temp;
					if (follow->next == NULL) {
						tail = follow;
					}
					return index;
				}
				follow = temp;
				temp = temp->next;
				index++;
			}
			return -1;
		}
		
	}

	bool isSorted() {

		if (head == NULL) {
			cout << "Empty list, can't check if it is sorted" << endl;
			return false;
		}
		Node* temp = head->next;
		int x = head->data;
		while (temp != NULL) {
			if (temp->data < x) {
				return false;
			}
			x = temp->data;
			temp = temp->next;
		}
		return true;
	}
	bool isReverseSorted() {

		if (head == NULL) {
			cout << "Empty list, can't check if it is reverse sorted" << endl;
			return false;
		}
		Node* temp = head->next;
		int x = head->data;
		while (temp != NULL) {
			if (temp->data > x) {
				return false;
			}
			x = temp->data;
			temp = temp->next;
		}
		return true;
	}

	Node* getHead() {
		return head;
	}
	Node* getTail() {
		return tail;
	}

	void concatenateList(LinkedList* list1) {
		Node* temp = head;
		if (temp == NULL) {
			head = list1->head;
			tail = list1->tail;
		}else{
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = list1->head;
			tail = list1->tail;
		}
	}
	void insertElement(int value,int index) {
		Node* temp = head;
		//Node* follow = NULL;
		int length = this->countNodes();
		if (index < 0 || index > length) {
			cout << "Invalid index to insert the element" << endl;
		}
		else if (index == 0) {
			this->addHeadElement(value);
		}
		else if (index == length) {
			this->addTailElement(value);
		}
		else {
			Node* newNode = new Node();
			newNode->data = value;
			for (int i = 1; i < index; i++) {
				//follow = temp;
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}

	void sortedInsert(int value) {
		Node* temp = head;
		Node* follow = NULL;
		int length = this->countNodes();
		if (!this->isSorted() && temp!= NULL) {
			cout << "Sorry, this functionality doesn't work for unsorted list" << endl;
			return;
		}
		if (temp == NULL || value < head->data) {
			this->addHeadElement(value);
		}
		else {
				Node* newNode = new Node();
				newNode->data = value;
				while (temp != NULL) {
					if (value < temp->data) {
						newNode->next = follow->next;
						follow->next = newNode;
						return;
					}
					follow = temp;
					temp = temp->next;
				}
				if (temp == NULL && follow->next == NULL) {
					this->addTailElement(value);
				}

			}

	}

	void deleteElement(int value) {
		int index = searchElement(value);
		if (index == -1) {
			cout << "can't delete element not present in the list" << endl;
			return;
		}
		if (index == 0) {
			Node* newNode = new Node();
			newNode = head;
			head = head->next;
			delete newNode;
		}
		else {
			Node* temp = head->next;
			Node* follow = head;
			for (int i = 1; i < index; i++) {
				follow = temp;
				temp = temp->next;
			}
			follow->next = temp->next;
			delete temp;
			if (follow->next == NULL) {
				tail = follow;
			}
		}
	}

	void removeDuplicates() {
		Node* temp = head;
		if (temp == NULL) {
			cout << "List is empty, so no duplicates found to delete" << endl;
			return;
		}
		if (this->isSorted() || this->isReverseSorted()) {
			cout << "No duplicate elements found to delete" << endl;
			return;
		}
		else {
			Node* follow = temp;
			temp = temp->next;
			while(temp != NULL){
				if (follow->data == temp->data) {
					follow->next = temp->next;
					delete temp;
					temp = follow->next;
					if (follow->next == NULL) {
						tail = follow;
					}
				}
				else {
					follow = temp;
					temp = temp->next;
				}
			}
		}
	}

	void reverseList() {
		Node* first = head;
		Node* second = NULL;
		Node* third = NULL;
		while (first != NULL) {
			third = second;
			second = first;
			first = first->next;
			second->next = third;
		}
		tail = head;
		head = second;

	}

	void mergeList(LinkedList* list1) {
		Node* first = head;
		Node* second = list1->head;
		Node* third = NULL;
		Node* last = NULL;
		if (first->data < second->data) {
			third = first;
			last = first;
			first = first->next;
			third->next = NULL;
		}
		else {
			third = second;
			last = second;
			second = second->next;
			third->next = NULL;
		}
		while(first != NULL && second != NULL) {
			if (first->data < second->data) {
				last->next = first;
				last = first;
				first = first->next;
				last->next = NULL;
			}
			else {
				last->next = second;
				last = second;
				second = second->next;
				last->next = NULL;
			}
		}
		if (first != NULL) {
			last->next = first;
		}
		if (second != NULL) {
			last->next = second;
			tail = list1->tail;
		}
		head = third;
	}

	bool isCircular() {
		Node* temp = head;
		Node* follow = head;
		do {
			temp = temp->next;
			follow = follow->next;
			follow = follow ? follow->next : follow;

		} while (temp && follow && temp != follow);
		if (temp == follow) {
			return true;
		}
		else {
			return false;
		}
	}
};


int main() {
	LinkedList* list = new LinkedList();
	int n = 4;
	int data;
	cout << "add " << n << " integer elements to the head of the list" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Element " << i + 1 << ": ";
		cin >> data;
		list->addHeadElement(data);

	}
	cout << "add " << n << " integer elements to the tail of the list" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Element " << i + 1 << ": ";
		cin >> data;
		list->addTailElement(data);

	}
	cout << "You'r list is: ";
	list->display();
	Node* start = list->getHead();
	Node* end = list->getTail();
	cout << "Head of the list is: " << start->data << endl;
	cout << "Tail of the list is: " << end->data << endl;
	cout << "The list consists of " << list->countNodes() << " nodes" << endl;
	cout << "The sum of all the elements in the list: " << list->sumAllElements() << endl;
	cout << "The maximum value in the list is: " << list->maxElement() << endl;
	cout << "The minimum value in the list is: " << list->minElement() << endl;
	if (list->isSorted()) {
		cout << "You'r list is sorted" << endl;
	}
	else {
		cout << "The list is not sorted" << endl;
	}
	if (list->isReverseSorted()) {
		cout << "You'r list is reverse sorted" << endl;
	}
	else {
		cout << "The list is not reverse sorted" << endl;
	}
	cout << "Enter the element you want to search for: ";
	cin >> data;
	int found = list->searchElement(data);
	if (found != -1) {
		cout << "The element " << data << " is located at index " << found << endl;
		list->display();
	}
	else {
		cout << "The element that you are looking for doesn't exist" << endl;
	}
	cout << "Enter another element you want to search for: ";
	cin >> data;
	int improvedFound = list->improvedSearchElement(data);
	if (improvedFound != -1) {
		cout << "The element " << data << " is located at index " << improvedFound << endl;
		cout << "after moving the element to the head the list is now" << endl;
		list->display();
		start = list->getHead();
		end = list->getTail();
		cout << "Head of the list is: " << start->data << endl;
		cout << "Tail of the list is: " << end->data << endl;
	}
	else {
		cout << "The element that you are looking for doesn't exist" << endl;
	}
	cout << "The reverse of the above list is" << endl;
	list->reverseList();
	list->display();
	start = list->getHead();
	end = list->getTail();
	cout << "Head of the list is: " << start->data << endl;
	cout << "Tail of the list is: " << end->data << endl;
	int index;
	cout << "Enter the value you would like to insert into the list: ";
	cin >> data;
	cout << "\nEnter the index you want to inert at: ";
	cin >> index;
	list->insertElement(data, index);
	list->display();
	start = list->getHead();
	end = list->getTail();
	cout << "Head of the list is: " << start->data << endl;
	cout << "Tail of the list is: " << end->data << endl;

	cout << "Enter the value you would like to insert into the sorted list: ";
	cin >> data;
	list->sortedInsert(data);
	list->display();
	start = list->getHead();
	end = list->getTail();
	cout << "Head of the list is: " << start->data << endl;
	cout << "Tail of the list is: " << end->data << endl;

	cout << "Enter the value you would like to delete from the list: ";
	cin >> data;
	list->deleteElement(data);
	list->display();
	start = list->getHead();
	end = list->getTail();
	cout << "Head of the list is: " << start->data << endl;
	cout << "Tail of the list is: " << end->data << endl;

	cout << "After removing duplicates from the list: ";
	list->removeDuplicates();
	list->display();
	start = list->getHead();
	end = list->getTail();
	cout << "Head of the list is: " << start->data << endl;
	cout << "Tail of the list is: " << end->data << endl;
	LinkedList* anotherList = new LinkedList();
	anotherList->addHeadElement(20);
	anotherList->addTailElement(40);
	anotherList->addTailElement(60);
	anotherList->addTailElement(80);
	anotherList->display();
	list->concatenateList(anotherList);
	cout << "after concatenating the above 2 list, the final list looks like: " << endl;
	list->display();
	start = list->getHead();
	end = list->getTail();
	cout << "Head of the list is: " << start->data << endl;
	cout << "Tail of the list is: " << end->data << endl;
	LinkedList* first = new LinkedList();
	first->addHeadElement(10);
	first->addTailElement(30);
	first->addTailElement(50);
	first->addTailElement(70);
	LinkedList* second = new LinkedList();
	second->addHeadElement(20);
	second->addTailElement(40);
	second->addTailElement(60);
	second->addTailElement(80);
	first->display();
	second->display();
	first->mergeList(second);
	cout << "after merging the above 2 list, the final list looks like: " << endl;
	first->display();
	start = first->getHead();
	end = first->getTail();
	cout << "Head of the list is: " << start->data << endl;
	cout << "Tail of the list is: " << end->data << endl;
	Node* circular = new Node();

	circular = list->getTail();
	//circular->next = list->getHead();
	if (list->isCircular()) {
		cout << "\nList is Circular" << endl;
	}
	else {
		cout << "\nList doesn't have a loop" << endl;
	}

}