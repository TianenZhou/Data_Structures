#include <iostream>

// Definition of a singly linked list node
struct Node
{   int data;
    Node* next;

    Node(int val):data(val), next(nullptr) {}
};

// Definition of the LinkedList class
class LinkedList
{
private:
    Node* head;
    Node* tail;
public:
    // Constructor to initialize an empty linked list
    LinkedList():head(nullptr), tail(nullptr){};

    // Print the entire linked list
    void printList(){
        Node* temp = head;
        if (temp == nullptr)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        
        while(temp != nullptr){
            std::cout << temp -> data << " ->";
            temp = temp -> next;
        }
        std::cout <<"nullptr"<< std::endl;
    }

    // Append a new node with the given value to the end of the list
    void append(int val){
        Node* node = new Node(val);
        if(head == nullptr){
            head = node;
            tail = node;
        }else{
            tail -> next = node;// Link the new node at the end of the list
            tail = node;// Update the tail to the new node
        }

    }

    // Prepend a new node with the given value to the start of the list
    void prepend(int val){
        Node* node = new Node(val);
        if(tail == nullptr){
            tail = node;// If the list was empty, update tail as well
        }
        node -> next = head;// Link the new node to the current head
        head = node;// Update head to the new node
        
    }
    // Insert a new node with the given value at the specified position
    void insert(int val, int position){
        Node* temp1 = new Node(val);
       
        if(position == 1){// Insert at the head
            temp1 -> next = head;
            head = temp1;
            return;
        }

        Node* temp2 = head;
        for(int i = 0; i < position -2;i++){// Move temp2 to the node just before the desired position
            temp2 = temp2 -> next;// Traverse the list
        }
        temp1 -> next = temp2 -> next;// Link the new node to the next node
        temp2 -> next = temp1;// Link the previous node to the new node
    }

    void deleteNode(int position){
        if(head == nullptr){// List is empty
            return;
        }
        Node* temp1 = head;
        if(position == 1){
            head = temp1 -> next;// Update head to the next node
            if (head == nullptr) {
                tail = nullptr;// If the list becomes empty, update tail as well
            }
        delete temp1;
        return;
        }
        for(int i = 0; i < position - 2;i++){
            temp1 = temp1 -> next;// Traverse to the node just before the one to be deleted
        }
        Node* deleteNode = temp1 -> next;// Node to be deleted

        temp1 -> next = deleteNode -> next;// Bypass the node to be deleted
        if (temp1 -> next == nullptr) {
            tail = temp1;// If the deleted node was the tail, update tail
        
        delete(deleteNode);// Free memory
        }
    }
    
    // Reverse the linked list
    void reverse(){
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(current != NULL){
            next = current -> next;// Store next node
            current -> next = prev;// Reverse current node's pointer
            prev = current;// Move pointers one position ahead
            current = next;// Move to next node
        }
        head = prev;// Update head to the new first node
    }

    //Use recursion to print the linked list
    void printLinkedListRecursively(Node* node){
        if(node == nullptr){//Important to exit the recursion
            std::cout << "nullptr" << std::endl;// Base case: end of the list
            return;
        }
        std::cout << node -> data << " -> ";
        printLinkedListRecursively(node -> next);// Recursive call for the next node
    }

    //Use recursion to reverse print the linked list
    void reversePrintLinkedListRecursively(Node* node){
        if(node == nullptr){//Important to exit the recursion
            return;// Base case: end of the list
        }
        reversePrintLinkedListRecursively(node -> next);// Recursive call for the next node
        std::cout << node -> data << " -> ";
    }
    
    //Use recursion to reverse the linked list
    void reverseLinkedListRecursively(Node* current, Node* prev){
        if(current == nullptr){
            head = prev;// Update head to the new first node
            return;
        }
        Node* next = current -> next;// Store next node
        current -> next = prev;// Reverse current node's pointer
        reverseLinkedListRecursively(next, current);// Recursive call for the next node
    }

    

    Node* getHead() {
        return head;
    }

};

int main()
{
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    std::cout<<"my linked list: ";
    list.printList(); // Output: 10 -> 20 -> 30 -> nullptr

    LinkedList list2;
    list2.prepend(30);
    list2.prepend(20);
    list2.prepend(10);
    std::cout<<"my linked list: ";
    list2.printList(); // Output: 10 -> 20 -> 30 -> nullptr

    LinkedList list3;
    list3.insert(20,1);
    list3.insert(30,2);
    list3.insert(10,1);
    std::cout<<"my linked list: ";
    list3.printList(); // Output: 10 -> 20 -> 30 -> nullptr
    LinkedList list4;
    list4.append(10);
    list4.append(20);
    list4.append(30);
    std::cout<<"my linked list before deletion: ";
    list4.printList(); // Output: 10 -> 20 -> 30 -> nullptr
    list4.deleteNode(1);
    std::cout<<"my linked list after deletion: ";
    list4.printList(); // Output: 20 -> 30 -> nullptr

    LinkedList list5;
    list5.append(10);
    list5.append(20);
    list5.append(30);
    std::cout<<"my linked list before reversal: ";
    list5.printLinkedListRecursively(list5.getHead()); // Output: 10 -> 20 -> 30 -> nullptr
    std::cout<<"my linked list after reversal: ";
    list5.reverseLinkedListRecursively(list5.getHead(), nullptr);
    list5.printLinkedListRecursively(list5.getHead()); // Output: 30 -> 20 -> 10 -> nullptr


   
   
    return 0;
}