#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL
    }

}

int convertIntoSumTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftSum = convertIntoSumTree(root->left);
    int rightSum = convertIntoSumTree(root->right);

    root->data = root->data + leftSum + rightSum;

    return root->data;
}


int main(){
    return 0;
}