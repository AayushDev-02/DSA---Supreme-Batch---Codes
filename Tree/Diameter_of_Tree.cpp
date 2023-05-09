#include <iostream>
using namespace std;

class Node{
    public: 
        Node* left;
        Node* right;
        int data;

        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    
    return (max(left, right) + 1);


}

int diameter(Node* root){
    if(root == NULL){
        return 0;
    }

    //left part
    int left = diameter(root->left);
    int right = diameter(root->right);
    int current = height(root->left) + height(root->right) + 1;

    return max(left, max(right, current));
}


int main(){





    return 0;
}