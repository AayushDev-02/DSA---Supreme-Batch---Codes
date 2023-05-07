#include <iostream>
using namespace std; 

class Node{
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
}

Node* lowestCommonAncestor(Node* root, Node* n1, Node* n2){
    if(root == NULL){
        return NULL;
    }

    //check if p or q
    if(root->data == n1->data){
        return n1;
    }
    if(root->data == n2->data){
        return n2;
    }

    Node* left = lowestCommonAncestor(root->left, n1,n2);
    Node* right = lowestCommonAncestor(root->right, n1,n2);
    
    if(left != NULL && right != NULL){
        return root;
    }

    else if(left == NULL && right == NULL){
        return NULL;
    }

    else if(left != NULL && right == NULL){
        return left;
    }

    else {
        return right;
    }

    
}