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

void kthSmallest(Node* root,int &i, int &ans, int k){
    
    if(root == NULL){
        return ;
    }

    kthSmallest(root->left, i, ans, k);
    //increment i each time root->left does not exit
    i++;

    if(i == k){
        ans = root->data;
        return;
    }

    kthSmallest(root->right,i ,ans, k);



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


    
    int i=0;
    int ans = -1;
    int k = 5;
    kthSmallest(root, i, ans, k);

    cout << endl;

    if(ans == -1){
        cout << "There is no 5th smallest no" << endl;
    }
    else
        cout << "The 5th smallest no is: " << ans << endl;

    return 0;


    return 0;
}
//kth smallest element
