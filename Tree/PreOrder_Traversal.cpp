//NLR

#include <iostream>
using namespace std;
class Node{
    public: 
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

void Preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}


int main(){
    return 0;
}