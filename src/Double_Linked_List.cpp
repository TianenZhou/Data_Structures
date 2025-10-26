struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val):data(val), next(nullptr), prev(nullptr) {}
}

class DoubleLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
    // Constructor to initialize an empty double linked list
    DoubleLinkedList():head(nullptr), tail(nullptr){};

    // Print the entire double linked list from head to tail
    void printListForward(){
        Node* temp = head;
        if(temp == nullptr){
            std::cout << "List is empty" << std::endl;
            return;
        }
        while(temp != nullptr){
            std::cout << temp -> data << " <-> ";
            temp = temp -> next;// Move to the next node
        }
        std::cout << "nullptr" << std::endl;
    }

    // Print the entire double linked list from tail to head
    void printListBackward(){
        Node* temp = tail;
        if(temp == nullptr){
            std::cout << "List is empty" << std::endl;
            return;
        }
        while(temp != nullptr){
            std::cout << temp -> data << " <-> ";
            temp = temp -> prev;// Move to the previous node
        }
        std::cout << "nullptr" << std::endl;
    }

    //Insert a new node with the given value at the end of the double linked list
    void append(int val){
        Node* node = new Node(val);
        if(head == nullptr){
            head = node;
            tail = node;
        }else{
            tail -> next = node;// Link the new node at the end of the list
            node -> prev = tail;// Link the new node back to the current tail
            tail = node;// Update the tail to the new node
        }
    }

    //Insert a new node with the given value at the start of the double linked list
    void prepend(int val){
        Node* node = new Node(val);
        if(head == nullptr){
            head = node;
            tail = node;
        }else{
            head -> prev = node;// Link the current head back to the new node
            node -> next = head;// Link the new node to the current head
            head = node;// Update head to the new node
        }
    }

    //Reverse the double linked list
    void reverse(){
        Node* current = head;
        Node* temp = nullptr;
        while(current != nullptr){
            temp = current -> prev;// Store previous node
            current -> prev = current -> next;// Swap prev and next pointers
            current -> next = temp;
            current = current -> prev;// Move to the next node (which is previous before swap)      
        }
        if(temp != nullptr){
            head = temp -> prev;// Update head to the new first node
        }
    }

}

int main(){
    DoubleLinkedList dlist;
    dlist.append(10);
    dlist.append(20);
    dlist.append(30);
    std::cout << "Double Linked List printed forward: ";
    dlist.printListForward(); // Output: 10 <-> 20 <-> 30 <-> nullptr
    std::cout << "Double Linked List printed backward: ";
    dlist.printListBackward(); // Output: 30 <-> 20 <-> 10 <-> nullptr

    DoubleLinkedList dlist2;
    dlist2.prepend(30);
    dlist2.prepend(20);
    dlist2.prepend(10);
    std::cout << "Double Linked List printed forward: ";
    dlist2.printListForward(); // Output: 10 <-> 20 <-> 30 <-> nullptr
    std::cout << "Double Linked List printed backward: ";
    dlist2.printListBackward(); // Output: 30 <-> 20 <-> 10 <-> nullptr

    return 0;
}