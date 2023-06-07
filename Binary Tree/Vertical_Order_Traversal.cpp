#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Node{
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data;
            this->left = NULL;
            this->right = NULL;
        }
}

vector<int> verticalTraversal(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    //map to store the data wrt hd and levels
    map<int, pair<int, vector<int>>> nodes;
    queue<Node*, pair<int,int>> q;
    q.push(root, make_pair(0,0));

    while(!q.empty()){

        pair<Node*, pair<int,int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        //inserting into map
        nodes[hd][level].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd-1, level+1)));
        }

        if(frontNode -> right){
            q.push(make_pair(frontNode->right, make_pair(hd+1, level+1)));
        }

    }

    for(auto i: nodes){
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;

}


int main(){


    return 0;
}