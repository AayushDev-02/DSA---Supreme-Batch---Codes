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
            right = NULL;
        }
}



Node* kthAncestor(Node* root, int &k, Node* p){
    if(root == NULL){
        return NULL;
    }

   if(root->data == p->data){
        return root;
   }

   Node* leftAns = kthAncestor(root->left, k, p);
   Node* rightAns = kthAncestor(root->right, k, p);

    if(leftAns == NULL && rightAns !=NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
}

int main(){
    return 0;
}