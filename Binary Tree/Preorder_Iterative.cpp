#include <iostream>
#include <bits/stdc++.h>
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
}

vector<int> iterativePreOrder(Node* root){
    
    vector<int> ans;
    stack<Node*> s;

    Node* temp = root;

    while(true){
        if(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }
        else {
            //check if stack is empty
            if(s.empty()){
                break;
            }
            temp = s.top();
            s.pop();    
            ans.push(temp->data);
            temp = temp->right;
        }
    }

    return ans;
    

}

int main(){




    return 0;
}