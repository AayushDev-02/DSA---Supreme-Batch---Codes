//LRN

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

void Postorder(Node* root){
    if(root == NULL){
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}


int main(){
    return 0;
}