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
void inOrder(Node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }

    preOrder(root->left);
    arr.push_back(root->data);
    preOrder(root->right);
}

//finding min and max values
int minValue2(Node* root){
    vector<int> inorder;
    inOrder(root,inorder);

    return inorder[0];
}

int maxValue2(Node* root){
    vector<int> inorder;
    inOrder(root, inorder);
    int size = inorder.size();
    return inorder[size-1];
}

//iterative appraach
int minValue(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }

    return temp->data;
}

int maxValue(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }

    return temp->data;
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
    cout << "Min Value: " << minValue(root) << endl;
    cout << "Max Value: " << maxValue(root) << endl;



    return 0;
}