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


void solve(Node*root, int arr, int size, int start, int end){
    

    int mid = start+(end-start)/2;
    root->data = arr[mid];

    solve(root->left, arr, size, start, mid-1);
    solve(root->right, arr, size, mid+1, end);

    return root;
}

// normal to bst
Node* normalToBST(Node* root){

    vector<int> arr;
    inOrderTraversal( root,arr);

    int size = arr.size();
    int start = 0;
    int end = arr.size()-1;

    solve(root, arr, size,  start, end);

    return root;


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



    return 0;
}