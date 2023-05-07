#include <iostream>
using namespace std;

class Node {
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

    int ans = max(left, right) + 1;

    return ans;
}


bool checkBalancedTree(Node* root){
    if(root == NULL){
        return true;
    }

    bool left = checkBalancedTree(root->left);
    bool right = checkBalancedTree(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff){
        return true;
    }else{
        return false;
    }


}


int main(){



    return 0;
}