#include <iostream>
using namespace std;

class Node {
    public :
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = buildBST(root->right, data);
    }
    else{
        root->left = buildBST(root->left, data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cout << "Enter the data : "; 
    cin >> data;
    

    while(data != -1){
        root = buildBST(root, data);
        cout << "Enter the data : "; 
        cin >> data;
    }
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int maxLeft(Node* root){
    while(root->right != NULL){
        root = root->right;
    }

    return root->data;
    
}

int minRight(Node* root){
    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}


pair<int,int> predecessorSuccessor(Node*root, int key){
    
    Node* temp = root;
    int pred = -1;
    int succ = -1;
    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    //now we got the key
    //pred - max element in left subtree
    //succ - min element in right subtree
    if(temp->left != NULL){
         pred = maxLeft(temp -> left);
    }

    if(temp-> right != NULL){
         succ = minRight(temp -> right);
    }

    pair<int,int> ans = {pred, succ};

    return ans;
    
}


int main(){

    Node* root = NULL;
    cout << "Creating BST - Enter data" << endl;
    takeInput(root);
    cout << "Traversing the tree" << endl;
    if(root == NULL){
        cout << "Root is null";
    }
    preOrder(root);

    cout << endl;

    pair<int,int> PS = predecessorSuccessor(root, 5);

    cout << "Predessor of 5 is: " << PS.first << endl;
    cout << "Successor of 5 is: " << PS.second << endl;



    return 0;
}