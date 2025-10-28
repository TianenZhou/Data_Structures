#include <iostream>
#include <string>
#include <stdexcept>
#include<stack>
class Node {
public:
    int data;       // Data part of the node
    Node* next;    // Pointer to the next node
    Node(int val) : data(val), next(nullptr) {} // Constructor
};

Node* head = nullptr;

//Reverse a string using stack data structure
/*First push all char into to the stack in the order of index
 Then let the index go back to 0
 And pop from the top of the stack to insert the element into the String char by char*/

 void ReverseString(std::string &str){
    if(str.empty()) {
        return; // Empty string, nothing to reverse
    }
    std::stack<char> stack;
    int n = str.length();

    // Push all characters of the string into the stack
    for (int i = 0; i < n; i++) {
        stack.push(str[i]);
    }

    // Pop all characters from the stack and put them back into the string
    for (int i = 0; i < n; i++) {
        str[i] = stack.top();
        stack.pop();
    }
}

//Reverse a linked list using stack data structure
/*First use a temp ptr to traverse the linked list 
push all the address of the element into the stack stack<Node*>
then using temp to reorder the linked list */

//It is like the kind of using Recursion to reverse a linked list
//Actually using Recursion is also using the stack data structure in the underlying layer

void push_back(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void printList(const std::string& msg = "") {
    if (!msg.empty()) {
        std::cout << msg << " ";
    }
    if (head == nullptr) {
        std::cout << "empty" << std::endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;


void ReverseLinkedList(){
    if (head == nullptr|| head->next == nullptr) {
        return; // Empty list, nothing to reverse
    }
    std::stack<Node*> stack;
    Node* temp = head;
    // Push all nodes of the linked list into the stack
    while (temp != nullptr) {
        stack.push(temp);
        temp = temp -> next;
    }

    // Pop nodes from the stack to reorder the linked list
    Node* temp = stack.top();
    stack.pop();
    Node* temp = head;// Reset temp to the new head
    while (!stack.empty()) {
        temp -> next = stack.top();//
        stack.pop();
        temp = temp -> next;
    }
    temp -> next = nullptr; // Set the next of the last node to nullptr
    
}


int main(){
    std::cout << "Enter a string to be reversed: ";
    std::string str;
    std::getline(std::cin, str);
    ReverseString(str);


    //reverse linked list
    push_back(1);
    push_back(2);
    push_back(3);
    push_back(4);
    push_back(5);
    printList("Original linked list:");
    ReverseLinkedList();
    printList("Reversed linked list:");
    
    return 0;
}

