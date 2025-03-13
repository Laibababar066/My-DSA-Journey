// first in first out
// push BACK/insert , pop FRONT
#include<iostream>
using namespace std;
// Array implementation
class circularQueue {
public:
	int* arr;
	int front;
	int back; // to insert an element
	int size; // size of array
	int count;
	circularQueue(int n) {
		count = 0;
		size = n;
		arr = new int[n];
		back = -1;
		front = -1;
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}
	void enqueue(int value) {
		if (isFull()) {
			return;
		}
		else if (isEmpty()) {
			front = back = 0; //points to first index
		}
		else {
			//back++ in simple case
			back = (back + 1) % size;  // in case of circular queue
		}
		count++;
		arr[back] = value;
	}
	int dequeue() {
		if (isEmpty()) {
			cout << "NO ELEMENTS IN QUEUE" << endl;
			return -1; // Return a more meaningful value for an empty queue
		}
		int x = arr[front];
		arr[front] = 0; // Optional: Reset value to zero for clarity
		count--;

		if (front == back) { // Queue becomes empty
			front = back = -1;
		}
		else {
			front = (front + 1) % size; // Move `front` forward circularly
		}
		return x;
	}
	int peek() {
		if (isEmpty()) {
			cout << "NO ELEMENTS IN QUEUE" << endl;
			return -1;
		}
		return arr[front];
	}
	bool isEmpty() {
		if (front == -1 || back==-1) {
			return true;
		}
		return false;
	}
	bool isFull() {
		if ((back + 1) % size == front) {
			return true;
		}
		return false;
	}
	int getcount() {
		return count;
	}
	void displayQueue() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		
	}
};
int main() {
	int size, choice, value;
	cout << "Enter the size of the circular queue: ";
	cin >> size;

	circularQueue q(size);

	while (true) {
		cout << "\n--- Circular Queue Menu ---\n";
		cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Check if Empty\n5. Check if Full\n6. Display Queue\n7. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value to enqueue: ";
			cin >> value;
			q.enqueue(value);
			break;
		case 2:
			q.dequeue();
			break;
		case 3:
			cout << "Front element: " << q.peek() << endl;
			break;
		case 4:
			cout << (q.isEmpty() ? "Queue is Empty.\n" : "Queue is NOT Empty.\n");
			break;
		case 5:
			cout << (q.isFull() ? "Queue is Full.\n" : "Queue is NOT Full.\n");
			break;
		case 6:
			q.displayQueue();
			break;
		case 7:
			cout << "Exiting program.\n";
			return 0;
		default:
			cout << "Invalid choice! Try again.\n";
		}
	}
	
	return 0;
}
