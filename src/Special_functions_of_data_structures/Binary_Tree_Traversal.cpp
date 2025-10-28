#include<iostream>
#include<queue>
#include<stack>
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

//Level-order Traversal

    void LevelOrderTraversal(Node* root){
        if (root == nullptr){
            throw runtime_error("The tree is empty");
        }
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty()){
            Node* current = queue.front();
            std::cout<< current -> data << " " ;
            
            if(current -> left != NULL){queue.push(current -> left);}
            if(current -> right != NULL){queue.push(current -> right);}
            queue.pop();
        }
        
        
    }

//Pre-order Traversal

    void PreorderTraversal(Node* node){
        if(node == nullptr){
            throw runtime_error("The tree is empty");
        }
        stack<Node*> stack;
        stack.push(node);
        while(!stack.empty()){
            Node* current = stack.top();
            stack.pop();
        std::cout << current->data << " ";
        
        if (current->right != nullptr) {
            stack.push(current->right);
        }
        if (current->left != nullptr) {
            stack.push(current->left);
        }
        }
    }

    //recursion version
    void PreorderTraversal_Recursive(Node* node){
        if(node == nullptr){
            return;
        }
        std::cout << node->data << " ";
        PreorderTraversal_Recursive(node->left);
        PreorderTraversal_Recursive(node->right);

    }

    //In-order Traversal
    void InorderTraversal_Recursive(Node* node){
        if(node == nullptr){
            return;
        }
        InorderTraversal_Recursive(node->left);
        std::cout << node->data << " ";
        InorderTraversal_Recursive(node->right);

    }

    //Post-order Traversal
    void PostorderTraversal_Recursive(Node* node){
        if(node == nullptr){
            return;
        }
        PostorderTraversal_Recursive(node->left);
        PostorderTraversal_Recursive(node->right);
        std::cout << node->data << " ";
}

    






public:
    Tree(){root = nullptr;}
    ~Tree(){destroyTree(root);}
    void insert(int val){
        root = insert(root, val);
    }
    void LevelOrderTraversal(){
        LevelOrderTraversal(root);
    }
    void PreorderTraversal_Recursive(){
        PreorderTraversal_Recursive(root);
    }
    void InorderTraversal_Recursive(){
        InorderTraversal_Recursive(root);   
    }
    void PostorderTraversal_Recursive(){
        PostorderTraversal_Recursive(root);   
    }
};  

int main() {
    Tree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    try {
        cout << "Level-order Traversal of the BST: ";
        bst.LevelOrderTraversal();
        cout << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
    cout << "In-order Traversal (Recursive): ";
    bst.InorderTraversal_Recursive();
    cout << endl;

    cout << "Post-order Traversal (Recursive): ";
    bst.PostorderTraversal_Recursive();
    cout << endl;
    

    return 0;
}