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
		if (pos <= 1) {  // Fix: Insert at head if pos is 0 or 1
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

		// Fix: If inserted at the last position, update `tail`
		if (newNode->next == NULL) {
			tail = newNode;
		}
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
	return 0;
}