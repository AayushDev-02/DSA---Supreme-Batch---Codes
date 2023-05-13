#include <iostream>
#include <queue>
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

void topView(Node* root){
    
    //level order traversal
    if(root == NULL){
        return;
    }

    //create a map for storing horizontal distance , topnode->data
    map<int, int> topNode;

    //level order
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node* , int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        Node* distance = temp.second;

        // check if to store it or not - check if answer for distance is present or not;

        if(topNode.find(distance) == topNode.end()){
            topNode[distance] = frontNode->data;
        }

        if(frontNode -> left)
            q.push(frontNode->left, hd-1);
        if(frontNode -> right)
            q.push(frontNode->right, hd-1);

    }

    //answer is stored in the map
    for(auto i: topNode ){
        cout << i.first + "->" + i.second;
    }

}



int main(){
    return 0;
}