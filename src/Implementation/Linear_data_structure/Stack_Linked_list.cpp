//insert and deletion must be done from one end only(begining of the Linked list)

/*why choosing the begining? 
because we can do insertion and deletion in O(1) time complexity
if we choose the end of the linked list we have to traverse the whole linked list to reach the end node 
and that will take O(n) time complexity*/

#include <iostream>
#include <stdexcept>
class Node {
public:
    int data;       // Data part of the node
    Node* next;    // Pointer to the next node
    Node(int val) : data(val), next(nullptr) {} // Constructor
};

class Stack_Linked_list
{
private:
    Node* head; // Pointer to the top node of the stack
    
public:
    Stack_Linked_list(){
        head = nullptr;
    };
    ~Stack_Linked_list(){
        while (!isEmpty()) {
            pop();
        }
    };

    //insert an element onto the stack at the begining of the linked list
    void push(int x){
        Node* newNode = new Node(x);
        newNode -> next = head;
        head = newNode;

    };

    //remove an element from the stack from the begining of the linked list
    void pop(){
        if (isEmpty()) {
            throw std::underflow_error("Stack Underflow: Cannot pop from an empty stack");
        }
        Node* temp = head;
        head = head -> next;
        delete temp;
    };

    //get the top element of the stack
    int topElement(){
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty: No top element");
        }
        return head -> data;
    };

    //check if the stack is empty
    bool isEmpty(){
        return head == nullptr;
    };
    //print the elements of the stack
    void printStack(){
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        Node* current = head;
        std::cout << "Stack elements: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    };

    
};



