//Array， Linked List, stack, queue are linear data structures;

/*we consider three key elements of a data structure:
1.cost of operations (time complexity)
2.memory usage (space complexity)
3.ease of implementation*/

/*Tree is a hierarchical data structure/recursive data structure that consists of nodes connected by edges.
A tree is connection of nodes with following properties:
1.one node is designated as root
2.each node contains a value
3.each node may have a list of child nodes
4.each node (except root) has exactly one parent node
5.nodes with no children are called leaves
6.children of a node are siblings to each other
7.there is exactly one path between any two nodes in the tree
N nodes have N-1 edges
8.ancestral relationship: if there is a path from node A to node B, then A is an ancestor of B and B is a descendant of A
9.depth of a node: length og path /number of edges from root to that node
10.height of a node: number of edges on the longest path from that node to a leaf
11.height of tree: height of the root node
12.degree of a node: number of children of that node
13.degree of tree: maximum degree of any node in the tree
14.subtree: any node and all its descendants form a subtree(recursive definition)


Common types of trees:
1.Binary Tree
2.Binary Search Tree
3.AVL Tree
4.Red-Black Tree
5.B-Trees
6.Trie
7.Heap


Basic operations on trees:
1.Insertion
2.Deletion
3.Traversal (Inorder, Preorder, Postorder, Level order)
4.Searching
5.Find Min/Max
6.Find Height/Depth
7.Check if Balanced
8.Find Ancestors/Descendants
9.Find LCA (Lowest Common Ancestor)
10.Convert to other data structures (like linked list, array, etc.)*/
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;// Constructor: initialize node with given value, left and right pointers as null
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

class Tree{
private:
    Node* root;  // Private root pointer, inaccessible from outside the class

    // Private recursive insertion (used internally, accepts current node pointer)
    Node* insert(Node* node, int val){
        if (node == nullptr){
            // Create a new node only once and return it (fix memory leak)
            return new Node(val);
        }else if (val <= node -> data){
            node -> left = insert(node -> left, val);
        }else{
            node -> right = insert(node -> right, val);
        }
        return node;
    }

    // Private recursive search (used internally)
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

    // Private recursive tree destruction
    void destroyTree(Node* node){
        if(node){
            destroyTree(node -> left);
            destroyTree(node -> right);
            delete node;
        }
    }

public:
    // Constructor: initialize root pointer as null
    Tree(){root = nullptr;}
    // Destructor: release memory by destroying the tree
    ~Tree(){destroyTree(root);}

    // Public interface: insert value (called externally, no need to pass root)
    void insert(int val){
        root = insert(root, val);  // Internally call private recursive function to update root
    }

    // Public interface: search value (called externally, no need to pass root)
    bool search(int val){
        return search(root, val);  // Internally call private recursive function
    }
};

int main(){
    Tree bst;
    // Directly call public interfaces without accessing private member 'root'
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bool found = bst.search(1);
    cout << found << endl;  // Output: 1 (true) 0 (false)
    return 0;
}