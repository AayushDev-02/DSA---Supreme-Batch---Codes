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


void bottomView(Node* root){
    
    if(root == NULL){
        return;
    }

    //create a map for storing horizontal distance -> Topnode -> data
    map<int,int> bottomNode;

    //level order - we will store a pair consisting of a node and hd
    queue< pair<Node*,int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){

        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //we need to update all the time
        bottomNode[hd] = frontNode->data; 

        if(frontNode->left){
            q.push(make_pair(root->left, hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(root->right, hd+1));

        }

    }
}
int main(){
    return 0;
}