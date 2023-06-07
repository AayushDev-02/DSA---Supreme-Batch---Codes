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
        Node* temp = q.front();
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

void LevelOrderTraversalVariation(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){

            cout << endl;

            if(!q.empty()){
                q.push(NULL);
            }

        }else{

        cout << temp->data << " ";

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right) {
            q.push(temp->right);
        }
        }

    }

}


int main(){

    Node* root = NULL;
    root = buildTree();
    LevelOrderTraversal(root);
    cout << endl;
    LevelOrderTraversalVariation(root);

    return 0;
}