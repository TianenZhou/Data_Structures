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

    void destroyTree(Node* node){
        if(node){
            destroyTree(node -> left);
            destroyTree(node -> right);
            delete node;
        }
    }

    int FindMin(Node* node){
        if (node == nullptr) {
            throw runtime_error("The tree is empty");
        }
        if(node -> left == nullptr){
            return node -> data;
        }
        return FindMin(node -> left);
    }

    //Delete a node from BST
    Node* Delete(Node* root, int data){
        if(root == nullptr){
            return root;
        }else if(data < root -> data) root ->left = Delete(root -> left, data);
        else if(data > root -> data) root ->right = Delete(root -> right, data);
        else{
            if(root -> left == NULL && root -> right == NULL){
                delete root;
                root = nullptr;
               
            }else if (root -> left == NULL ){
                Node* temp = root;
                root = root -> right;
                delete temp;
            }else if(root -> right == NULL){
                Node* temp = root;
                root = root -> left;
                delete temp;
            }else{
                Node* temp;
                int minVal = FindMin(root -> right); 
                root -> data = minVal; 
                root -> right = Delete(root -> right, minVal); 
            }
            
        }
        return root;
    }

    void inorder(Node* node){
        if(node == nullptr) return;
        inorder(node -> left);
        cout << node -> data << " ";
        inorder(node -> right);
    }




public:

    Tree(){root = nullptr;}
    ~Tree(){destroyTree(root);}
    void insert(int val){
        root = insert(root, val);

    }
    void Delete(int val){
        root = Delete(root, val);
    }
    void printInorder(){
        inorder(root);
        cout << endl;
    }
};


int main(){
    Tree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.printInorder();
    bst.Delete(20);
    bst.printInorder();
    bst.Delete(30);
    bst.printInorder();
    bst.Delete(50);
    bst.printInorder();
    return 0;
}