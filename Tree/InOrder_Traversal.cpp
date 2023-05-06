//LNR
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


void Inorder(Node* root){
    if(root == NULL){
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);

}

int main(){



    return 0;
}