#include <iostream>
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



int main(){

    Node* root = NULL;
    root = buildTree();
    return 0;
}