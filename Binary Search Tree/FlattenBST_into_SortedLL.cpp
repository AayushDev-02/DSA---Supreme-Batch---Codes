#include <iostream>
#include <vector>
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


void inOrderTraversal(Node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left, arr);
    arr.push_back(root->data);
    inOrderTraversal(root->right, arr);
}


//flatten bst to sorted linked list
Node* flattenBSTtoLL(Node* root){
    vector<int> inorder;
    inOrderTraversal(root, inorder);

    Node* head = new Node(inorder[0]);
    Node* curr = head;

    for(int i=1; i<inorder.size(); i++){
        Node* temp = new Node(inorder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    //now we will point the left and right of last node to null
    curr->left = NULL;
    curr->right = NULL;

    return head;

}


int main(){

    Node* root = NULL;
    cout << "Creating BST - Enter data" << endl;
    takeInput(root);

    cout << endl; 

    Node* linkedList = flattenBSTtoLL(root);
    while(linkedList->right!= NULL){
        cout << linkedList->data << " ";
        linkedList = linkedList->right;
    }

    cout << endl;
    







    return 0;
}