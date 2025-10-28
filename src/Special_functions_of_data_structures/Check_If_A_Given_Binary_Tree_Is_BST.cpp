#include<iostream>
#include<queue>
#include<stack>
#include<climits>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){data = val; left = right = nullptr;}
};

class Tree{
private:
    Node* root;
    int prev; // To keep track of the previous node's value during in-order traversal

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


    void destroyTree(Node* node){
        if(node){
            destroyTree(node -> left);
            destroyTree(node -> right);
            delete node;
        }
    }

    //if the tree is a binary search tree
    bool IsSubtreeLesser(Node* root, int val){
        if(root == NULL){
            return true;
        }
        if(root -> data <= val
            && IsSubtreeLesser(root -> left, val)
            && IsSubtreeLesser(root -> right, val)){
            return true;
        }else{
            return false;
        }
    } 

    bool IsSubtreeGreater(Node* root, int val){
        if(root == NULL){
            return true;
        }
        if(root -> data > val
            && IsSubtreeGreater(root -> left, val)
            && IsSubtreeGreater(root -> right, val)){
            return true;
        }else{
            return false;
        }

    }

    bool IsBinarySearchTree(Node* root){
        if (root == nullptr) {  
        return true;
    }
        if(IsSubtreeLesser(root -> left, root -> data) && IsSubtreeGreater(root -> right, root -> data)
            && IsBinarySearchTree(root -> left) && IsBinarySearchTree(root -> right)){
            return true;
        }else{
            return false;
        }
    }

//This method is not efficient because it traverses the same nodes multiple times.

bool IsBinarySearchTree_Efficient(Node* root, int minVal, int maxVal){
    if(root == nullptr){
        return true;
    }
    if(root -> data > minVal && root -> data < maxVal && IsBinarySearchTree_Efficient(root -> left, minVal, root -> data) && IsBinarySearchTree_Efficient(root -> right, root -> data, maxVal)){
        return true;
    }else{
        return false;
    }
   
}

bool isBSTUsingInorder(Node* node) {
        if (node == nullptr) return true;
        if (!isBSTUsingInorder(node->left)) return false;
        if (node->data <= prev) return false;
        prev = node->data;
        return isBSTUsingInorder(node->right);
    }


public:

    Tree(){root = nullptr;}
    ~Tree(){destroyTree(root);}
    void insert(int val){
        root = insert(root, val);
    }
    bool IsBinarySearchTree(){
        return IsBinarySearchTree(root);
    }
    bool IsBinarySearchTree_Efficient(){
        return IsBinarySearchTree_Efficient(root, INT_MIN, INT_MAX);
    }
    bool isBST() {
        prev = INT_MIN;  
        return isBSTUsingInorder(root);
    }
};


int main() {
    Tree bst1;
    bst1.insert(50);
    bst1.insert(30);
    bst1.insert(70);
    bst1.insert(20);
    bst1.insert(40);
    bst1.insert(60);
    bst1.insert(80);
    cout << "Test 1: " << bst1.IsBinarySearchTree()<< endl;
    
    cout << "Test 2: " << bst1.IsBinarySearchTree_Efficient()<< endl;
    
    cout << "Test 3: " << bst1.isBST()<< endl;


    
    return 0;
}



