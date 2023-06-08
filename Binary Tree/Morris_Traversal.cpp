#include <iostream>
using namespace std;


vector<int> MorrisTraversal(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    Node* curr = root;

    while(curr){
        //left node is null - the visit the current node
        if(curr->left == nullptr){
            ans.push_back(curr->data);
            curr = curr->right;
        } 

        //left node is not null
        else{
            //find inorder predecessor
            Node* pred = curr->left;
            while(pred->right != curr && pred->right){
                pred = pred->right;
            }

            //if right node is null the go left after establishing link from predecessor to current
            if(pred -> right == nullptr){
                pred -> right = curr;
                curr = curr->left;
            }
            else{
                //left is already visited, go right after visiting curr node while removing the link
                pred->right = nullptr;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main(){
    return 0;
}