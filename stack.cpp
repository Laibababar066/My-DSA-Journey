#include <iostream>
using namespace std;
class stack {
private:
    int top;
    int* arr;
    int arrSize;

public:
    stack() {
        top = -1;
        arrSize = 0;
        arr = nullptr;
    }

    ~stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == arrSize - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack is full" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
    }

    void inputSizeOfStack() {
        cout << "Enter size of stack you want to make: ";
        cin >> arrSize;

        if (arr != nullptr) {
            delete[] arr;
        }

        arr = new int[arrSize];
        top = -1;
    }

    void input() {
        for (int i = 0; i < arrSize; i++) {
            int value;
            cout << "Enter " << i + 1 << " element: ";
            cin >> value;
            push(value);
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        for (int i = 0; i <= top; i++) {
            cout << arr[i] << endl;
        }
    }
    void reverseArray() {
        cout << "reversed array: " << endl;
        for (int i = arrSize; i>0; i--) {
            cout << arr[i]<<endl;
        }
    }
};

int main() {
    stack myStack;
    myStack.inputSizeOfStack();
    myStack.input();
    myStack.display();
    myStack.reverseArray();
    myStack.pop();
    myStack.display();

    return 0;
}
