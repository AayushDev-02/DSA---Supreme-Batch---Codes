#include <iostream>
#include <queue>
using namespace std;

class Node{
    public: 
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree(){

    int data;
    cout << " Enter the data" << endl;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    //step A: 
    Node* root = new Node(data);
    //step B: 
    cout << "Enter data for left part: " ;
    root->left = buildTree();
    //step C: 
    cout << "Enter data for right part: " ;
    root->right = buildTree();

    return root;
}

void LevelOrderTraversal(Node* root){
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();20
        q.pop();

        cout << temp->data << " ";

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right) {
            q.push(temp->right);
        }
    }

}


int main(){

    Node* root = NULL;
    root = buildTree();
    LevelOrderTraversal(root);

    return 0;
}