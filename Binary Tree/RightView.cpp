#include <iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};  


void rightView(Node* root, int *level, vector<int> *arr){
    if(root == NULL){
        return;
    }

    if(level == arr.size()){
        arr.push_back(root->data);
    }

    root->right = leftView(root->right, level+1, arr);
    root->left = leftView(root->left, level+1, arr);

    return root;
}


int main(){
    return 0;
}