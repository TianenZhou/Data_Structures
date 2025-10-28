#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

class Tree{
private:
    Node* root;

    Node* insert(Node* node, int val){
        if (node == nullptr){
            return new Node(val);
        }else if (val <= node -> data){
            node -> left = insert(node -> left, val);
        }else{
            node -> right = insert(node -> right, val);
        }
        return node;
    }
    bool search(Node* node, int val){
        if (node == nullptr){
            return false;
        }else if (node -> data == val){
            return true;
        }else if (val <= node -> data){
            return search(node -> left, val);
        }else{
            return search(node -> right, val);
        }
    }
    void destroyTree(Node* node){
        if(node){
            destroyTree(node -> left);
            destroyTree(node -> right);
            delete node;
        }

    }
public:
    Tree(){root = nullptr;}
    ~Tree(){destroyTree(root);}
    void insert(int val){
        root = insert(root, val);
    }
    bool search(int val){
        return search(root, val);
    }
    
    //iterative approach to find min and max element in BST
    // Function to find the minimum value in the BST
    int findMin(){
        if (root == nullptr) {
            throw runtime_error("The tree is empty");
        }
        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->data;
    }   

    // Function to find the maximum value in the BST
    int findMax(){
        if (root == nullptr) {
            throw runtime_error("The tree is empty");
        }       
        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->data;
    }

    // Recursive approach to find min and max element in BST
    // Function to find the minimum value in the BST recursively
    int findMinRecursive(Node* node){
        if (node == nullptr) {
            throw runtime_error("The tree is empty");
        }
        if(node -> left == nullptr){
            return node -> data;
        }
        return findMinRecursive(node -> left);
    }

    // Function to find the maximum value in the BST recursively
    int findMaxRecursive(Node* node){
        if (node == nullptr) {
            throw runtime_error("The tree is empty");
        }
        if(node -> right == nullptr){
            return node -> data;
        }
        return findMaxRecursive(node -> right);
    }

    Node* getRoot(){
        return root;
    }
};

int main(){
    Tree bst;
    bst.insert(15);
    bst.insert(10);
    bst.insert(20);
    bst.insert(8);
    bst.insert(12);
    bst.insert(17);
    bst.insert(25);

    cout << "Minimum element (iterative): " << bst.findMin() << endl;
    cout << "Maximum element (iterative): " << bst.findMax() << endl;

    cout << "Minimum element (recursive): " << bst.findMinRecursive(bst.getRoot()) << endl;
    cout << "Maximum element (recursive): " << bst.findMaxRecursive(bst.getRoot()) << endl;

    return 0;
}

        