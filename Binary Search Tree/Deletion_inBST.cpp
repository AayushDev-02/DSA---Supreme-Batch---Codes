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


//deleting a node in bst
Node* deleteNodeInBST(Node* root, int val){

    if(root == NULL){
        return NULL;
    }

    Node* temp = root;

    if(root->data == val){
        //case1 : 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        if(root->left != NULL && root->right != NULL){
            // find either min value from right sub tree or max value from left sub tree
            //min value from right sub tree
            Node* temp = root->right;

            while(temp->left != NULL){
                temp = temp->left;
            }
            int mini = temp->data;
            root->data = mini;
            root->right = deleteNodeInBST(root->right, mini); 
            return root;
        }

    }
    else if(root->data < val){
        root->right = deleteNodeInBST(root->right, val);
        return root;
    }else{

        root->left = deleteNodeInBST(root->left, val);
        return root;
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
    preOrder(root);
    cout << endl;
    deleteNodeInBST(root,5);
    cout << endl;
    preOrder(root);


    return 0;
}