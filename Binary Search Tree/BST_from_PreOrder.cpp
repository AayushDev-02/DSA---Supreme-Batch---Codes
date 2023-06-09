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

//bst from a preorder array/vector

Node* solve(int pre[], int min , int max, int &i , int size){
    if(i >= size){
        return NULL;
    }

    if(pre[i] < min || pre[i] > max){
        return NULL;
    }

    Node* root = new Node(pre[i++]);
    //left call
    root->left = solve(pre, min, root->data, i, size);
    //right call
    root->right = solve(pre, root->data, max, i, size);

    return root;
}

Node* buildTree(int pre[], int size){
    
    int min = INT_MIN;
    int max = INT_MAX;
    int i=0;
    solve(pre, min, max, i ,size);

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