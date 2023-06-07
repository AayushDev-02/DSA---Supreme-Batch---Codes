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


//better approach
pair<bool, int> checkBalancedTree2(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool , int> left = checkBalancedTree2(root->left);
    pair<bool , int> right = checkBalancedTree2(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;

    ans.first = leftAns && rightAns && diff;
    ans.second = max(left.second + right.second) + 1;

    return ans; 
}

bool callerFunc(Node* root){
    return checkBalancedTree2(root).first;
}


int main(){

    

    return 0;
}