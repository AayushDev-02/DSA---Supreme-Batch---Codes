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

//recursive approach
bool searchInBST(Node* root, int x){
    if(root == NULL){
        return false;
    }

    if(root->data == x){
        return true;
    }

    if(x > root->data){
        return searchInBST(root->right, x);
    }
    else{
        return searchInBST(root->left,x);
    }

    return false;
}

//iterative approach
bool searchInBST2(Node* root, int x){
    Node* temp = root;

    while(temp != NULL){
        if(temp->data == x){
            return true;
        }

        else if(temp->data > x){
            temp = temp->left;
        }else{
            temp = temp->right;
        }

    }

    return false;
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

    cout  << endl << "Searching 9 in bst : " << endl;
    if(searchInBST2(root, 9)){
        cout << "Element found" << endl;
    }
    else{
        cout << "Element not found" << endl;
    }




    return 0;
}