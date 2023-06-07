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
    
    if(root == NULL){
        return;
    }

    //create a map for storing horizontal distance -> Topnode -> data
    map<int,int> topNode;

    //level order - we will store a pair consisting of a node and hd
    queue< pair<Node*,int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){

        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //check if we need to store or not
        if(topNode.find(hd) == topNode.end()){          // no entry present condition
            topNode[hd] = frontNode->data;
        }   

        if(frontNode->left){
            q.push(make_pair(root->left, hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(root->right, hd+1));

        }

    }

    cout << "Printing top node: " << endl;

    for(auto i: topNode){
        cout << i.first << "->" << i.second << endl;
    }


}



int main(){
    return 0;
}