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

// validate bst

bool validateBST(Node* root, int &min, int &max ){
    if(root== NULL){
        return true;
    }

    if(root->data > min && root->data < max){
        bool left = validateBST(root->left, min, root->data);
        bool right = validateBST(root->right, root->data ,max);

        return left&&right;
    }
    else{
        return false;
    }
}


int main(){

    Node* root = NULL;
    cout << "Creating BST - Enter data" << endl;
    takeInput(root);
    cout << "Traversing the tree" << endl;
    if(root == NULL){
        cout << "Root is null";
    }
    preOrder(root) ;
    cout << endl;

    int min = INT_MIN;
    int max = INT_MAX;
    bool validator = validateBST(root, min , max);
    if(validator){
        cout << "This is a valid BST" << endl;
    }else{
        cout << "Not a valid BST" << endl;
    }

    return 0;
}