#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* prev;
	node* next;
	node(int value) {
		data = value;
		prev = NULL;
		next = NULL;
	}
};
class doublyLinkedList {
public:
	node* head;
	node* tail;
	doublyLinkedList() {
		head = NULL;
		tail = NULL;
	}
	void insertAtHead(int valueToInsert) {
		node* newNode = new node(valueToInsert);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		return;
	}
	void insertAtTail(int valueToInsert) {
		node* newNode = new node(valueToInsert);
		newNode->next = NULL;
		if (tail == NULL) {
			head = newNode;
			tail = newNode;
			return;
		}
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	void insertAtPosition(int valueToInsert, int pos) {
		if (pos <= 1) {  //Insert at head if pos is 0 or 1
			insertAtHead(valueToInsert);
			return;
		}

		node* temp = head;
		int count = 1;

		while (count < pos - 1 && temp->next != NULL) {
			temp = temp->next;
			count++;
		}

		node* newNode = new node(valueToInsert);
		newNode->next = temp->next;
		if (temp->next != NULL) {
			temp->next->prev = newNode;
		}
		temp->next = newNode;
		newNode->prev = temp;

		//  If inserted at the last position, update `tail`
		if (newNode->next == NULL) {
			tail = newNode;
		}
	}
	void deleteAtStart() {
		if (head == NULL) {
			cout << "linked list is empty" << endl;
			return;
		}
		node* temp = head;
		head = head->next;
		if (head == NULL) {
			tail = NULL;
		}
		else {
			head->prev = NULL;
		}
		delete temp;
		return;
	}
	void deleteAtEnd() {
		if (head == NULL) {
			cout << "Linked list is empty" << endl;
			return;
		}

		node* temp = tail;

		if (head == tail) {  // If only one node exists
			head = NULL;
			tail = NULL;
		}
		else {
			tail = tail->prev;
			tail->next = NULL;
		}

		delete temp;  
	}
	void deleteAtPosition(int position) {
		node* temp = head;
		int count = 1;
		while (count < position) {
			temp = temp->next;
			count++;
		}
		//temp is now at position
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		return;
	}
	void display() {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " <-> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};
int main() {
	doublyLinkedList dll;
	dll.insertAtHead(1);
	dll.display();
	dll.insertAtHead(2);
	dll.display();
	dll.insertAtHead(3);
	dll.display();
	dll.insertAtPosition(0, 0);
	dll.display();
	dll.deleteAtStart();
	dll.display();
	return 0;
}