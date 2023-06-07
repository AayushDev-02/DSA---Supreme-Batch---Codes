#include <iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

void leftNodes(Node* root){
    if( root == NULL ){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    //NLR - PREORDER
    cout << root->data << " ";
    if(root->left){

        leftNodes(root->left);
    }else {

        leftNodes(root->right);
    }

}

void leafNodes(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
    }

    leafNodes(root->left);
    leafNodes(root->right);
    
}

void rightNodes(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    leafNodes(root->right);
    leafNodes(root->left);

    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
    }
    
}


void boundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }

    //print left nodes
    leftNodes(root->left);
    //print leaf nodes
    leafNodes(root);
    //print right nodes
    rightNodes(root->right);
}


int main(){



    return 0;
}