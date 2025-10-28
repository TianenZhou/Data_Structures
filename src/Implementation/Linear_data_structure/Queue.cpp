/*Queue is a kind of ADT which is First-In-First-Out
    deletion on the one side and insertion at another side
    Enqueue/push
    Dequeue/pop
    front()/peek()
    IsEmpty()
    IsFull()(For limited size)
    These operations must be in a constant time or O(1)*/

//implementation using array(circular array)
#include <iostream>
class Queue_Array{
    private:
        int front,rear,size,capacity;
        int *arr;
    public:
        Queue_Array(int c){
            capacity = c;
            front = 0;
            size = 0;
            rear = c - 1;
            arr=new int[capacity];
        }
        bool isFull(){
            return (size == capacity);
        }
        bool isEmpty(){
            return (size == 0);
        }
        void enqueue(int x){
            if(isFull()){
                std::cout<<"Queue is full\n";
                return;
            }
            rear = (rear + 1) % capacity;//circular increment
            arr[rear] = x;
            size++;
            std::cout<<x<<" enqueued to queue\n";
        }
        int dequeue(){
            if(isEmpty()){
                std::cout<<"Queue is empty\n";
                return -1;
            }
            int x = arr[front];
            front = (front + 1) % capacity;//circular increment
            size--;
            return x;
        }
        int getFront(){
            if(isEmpty()){
                std::cout<<"Queue is empty\n";
                return -1;
            }
            return arr[front];
        }

        int getRear(){
            if(isEmpty()){
                std::cout<<"Queue is empty\n";
                return -1;  
            }
            return arr[rear];
        }

        void printQueue(){
            if(isEmpty()){
                std::cout<<"Queue is empty\n";
                return;
            }
            for(int i=0; i<size; i++){
                std::cout<<arr[(front + i) % capacity]<<" ";
            }
            std::cout<<"\n";
        }
};


//implementation using linked list
struct Node{
    int data;
    Node* next;
    Node(int val){ data = val; next = nullptr;}
};

class Queue_LL{
    private:
        Node *front, *rear;
        int size;
    public:
        Queue_LL(){
            front = rear = nullptr;
            size = 0;
        }
        bool isEmpty(){
            return (size == 0);
        }
        void enqueue(int x){
            Node* temp = new Node(x);
            if(rear == nullptr){
                front = rear = temp;
                size++;
                std::cout<<x<<" enqueued to queue\n";
                return;
            }
            rear->next = temp;
            rear = temp;
            size++;
            std::cout<<x<<" enqueued to queue\n";
        }

        int dequeue(){
            if(isEmpty()){
                std::cout<<"Queue is empty\n";
                return -1;
            }
            Node* temp = front;
            int x = front->data;
            front = front->next;
            if(front == nullptr)
                rear = nullptr;
            delete temp;
            size--;
            return x;
        }

        Node* getFront(){
            if(isEmpty()){
                std::cout<<"Queue is empty\n";
                return nullptr;
            }
            return front;
        }

        Node* getRear(){
            if(isEmpty()){
                std::cout<<"Queue is empty\n";
                return nullptr;  
            }
            return rear;
        }

        void printQueue(){
            if(isEmpty()){
                std::cout<<"Queue is empty\n";
                return;
            }
            Node* temp = front;
            while(temp != nullptr){
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }
            std::cout<<"\n";
        }
};

int main(){
    Queue_Array q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.printQueue();
    std::cout<<q1.dequeue()<<" dequeued from queue\n";
    q1.printQueue();        

    Queue_LL q2;
    q2.enqueue(100);
    q2.enqueue(200);
    q2.enqueue(300);
    q2.printQueue();
    std::cout<<q2.dequeue()<<" dequeued from queue\n";
    q2.printQueue();

    return 0;
}

 