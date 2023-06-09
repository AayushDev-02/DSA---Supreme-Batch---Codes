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

    if(root->data == val){
        // no child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->left !=NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        if(root->left!=NULL && root->right!=NULL){
            //max from left
            Node* temp = root->left;
            while(temp->right != NULL){
                temp = temp->right;
            }

            int max = temp->data;
            root->data = max;
            root->left = deleteNodeInBST(root->left, max);

            return root;
        }
    }else if(root->data < val){
        root->right = deleteNodeInBST(root->right, val);
        return root;
    }else{
        root->left = deleteNodeInBST(root->left, val);
        return root;
    }
    
    ;

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