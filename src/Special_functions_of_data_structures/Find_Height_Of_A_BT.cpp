#include<iostream>
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

    // Function to find the height of the binary tree
    int FindHeight(Node* node){
        if(node == nullptr){
            return -1; // Height of empty tree is -1
        }
        int leftHeight = FindHeight(node -> left);
        int rightHeight = FindHeight(node -> right);
        return max(leftHeight, rightHeight) + 1;
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
    int FindHeight(){
        return FindHeight(root);
    }
};

int main(){
    Tree bt;
    bt.insert(10);
    bt.insert(5);
    bt.insert(4);
    bt.insert(3);
    bt.insert(2);
    bt.insert(1);
    bt.insert(18);

    cout << "Height of the binary tree: " << bt.FindHeight() << endl;

    return 0;
}
