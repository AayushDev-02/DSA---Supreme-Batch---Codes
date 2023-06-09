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


Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        
    }
}

void takeInput(){
    cin >> data;
    while(data!=-1){
        root = insertIntoBST(data);
        cin >> data;
    }
}

int main(){
    Node* root = NULL;
    cout << "Enter data for node: " << endl;
    takeInput();


    return 0;
}