#include<iostream>
using namespace std;

//  Node structure for the BST

struct Node{
    int key;
    Node* left;
    Node *right;

    Node(int k): key(k), left(nullptr), right(nullptr){}
};

// BST Class

class BinarySearrchTree{

public:
    BinarySearrchTree(): root(nullptr){}

    void insert(int key){
        root = insertRecursive(root,key);
    }

    bool search(int key){
        return searchRecursive(root,key) != nullptr;
    }

    void inorder(){
        inorderRecursive(root);
        cout << endl;
    }

private:
    Node* root;

    Node* insertRecursive(Node* node, int key){
        if(node == nullptr){
            return new Node(key);
        }

        if(key < node->key){
            node->left = insertRecursive(node->left, key);
        }
        else{
            node->right = insertRecursive(node->right,key);
        }
        
        
        return node;
    }

    Node* searchRecursive(Node* node,int key){
        if(node == nullptr || node->key == key){
            return node;
        }

        if(key < node->key){
            return searchRecursive(node->left,key);
        }

        if(key > node->key){
            return searchRecursive(node->right,key);
        }
    }

    void inorderRecursive(Node* node){
        if(node != nullptr){
            inorderRecursive(node->left);
            cout << node->key << " ";
            inorderRecursive(node->right);
        }
    }

};

int main(){
    BinarySearrchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);


    cout << "Inorder Treaversal of the BST: ";
    bst.inorder(); // OUTPUT: 20 30 40 50 60 70 80

    cout << "Search for 40 : " << (bst.search(40) ? "Found" : "Not Found ") << endl;
    cout << "Search for 25: " << (bst.search(25) ? "Found" : "Not Found ") << endl;

    return 0;

}
