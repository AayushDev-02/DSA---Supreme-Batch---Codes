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

Node* lca(Node* root, int n1, int n2){

    if(root->data < n1 && root->data < n2){
        return lca(root->right, n1, n2);
    }
    else if(root->data > n1 && root->data < n2 || root->data > n2 && root->data < n1){
        return root;
    }
    else if(root->data > n1 && root->data > n2){
        return lca(root->left, n1, n2);
    }
    else if(root->data == n1 || root->data == n2){
        return root;
    }

    return NULL;

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

    Node* ancestor = lca(root, 3,5);
    cout << "Lowest common ancestor of 3 and 9 is: " << ancestor->data << endl;


    return 0;
}

