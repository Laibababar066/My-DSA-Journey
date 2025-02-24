//#include<iostream>
//using namespace std;
////stack implementation using linked List
//class Node {
//public:
//    int data;
//    Node* next;
//};
//class Stack {
//private:
//    Node* top;
//
//public:
//    Stack() {
//        top = nullptr;  // Initialize top as null (empty stack)
//    }
//
//    ~Stack() {
//        makeNull();  // Free memory when object is destroyed
//    }
//
//    void Push(int newElement) {
//        Node* newNode = new Node();
//        newNode->data = newElement;
//        newNode->next = top;
//        top = newNode;
//    }
//
//    bool Pop(int& poppedValue) {
//        if (IsEmpty()) {
//            cout << "Stack is empty!" << endl;
//            return false;
//        }
//        Node* temp = top;
//        poppedValue = top->data;
//        top = top->next;
//        delete temp;
//        return true;
//    }
//
//    bool IsEmpty() {
//        return top == nullptr;
//    }
//
//    void makeNull() {
//        while (!IsEmpty()) {
//            int tempValue;
//            Pop(tempValue);
//        }
//    }
//
//    void display() {
//        if (IsEmpty()) {
//            cout << "Stack is empty!" << endl;
//            return;
//        }
//        Node* current = top;
//        cout << "Stack elements: ";
//        while (current) {
//            cout << current->data << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//};
//int main() {
//    Stack myStack;
//
//    myStack.Push(10);
//    myStack.Push(20);
//    myStack.Push(30);
//    myStack.display();
//	return 0;
//}