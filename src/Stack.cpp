//Using array to achieve stack
#include <iostream>
#include <stdexcept>
class Stack {
private:
    int* arr;          // Array to store stack elements
    int capacity;     // Maximum number of elements stack can hold
    int top;          // Index of the top element in the stack
public:
    // Constructor to initialize stack
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1; // Stack is initially empty
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int x){
        if (top == capacity - 1) {
            throw std::overflow_error("Stack Overflow: Cannot push to a full stack");
        }
        top++;// Increment top index
        arr[top] = x;// Add new element at the top
    }

    // Pop an element from the stack
    void pop(){
        if (isEmpty()) {
            throw std::underflow_error("Stack Underflow: Cannot pop from an empty stack");
        }
        top--;// Decrement top index to remove the top element
    }

    // Get the top element of the stack
    int top(){
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty: No top element");
        }
        return arr[top];// Return the top element
    }

    // Check if the stack is empty
    bool isEmpty(){
        return top == -1;// Stack is empty if top index is -1
    }

    // Get the current size of the stack
    int size(){
        return top + 1;// Size is top index + 1
    }

    // Print the elements of the stack
    void printStack(){
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    } 
};