#include <iostream>
#include <vector>
using namespace std;

class Node{
    public :
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data;
            this->left = NULL;
            this->right = NULL;
        }
}

vector<int> zigzagTraversal(Node* root){

    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    int toggle = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> res(size);

        for(int i=0; i<size; i++){
            Node* frontNode = q.front();
            q.pop();

            int index = toggle == true ? i : size - i 1;
            
            res[index] = frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left)
            }
            if(frontNode->right){
                q.push(frontNode->right)
            }
        }

        toggle = !toggle;

        for(auto i: res){
            ans.push_back(i);
        }
    }

    return ans;


}


int main(){
    return 0;
}