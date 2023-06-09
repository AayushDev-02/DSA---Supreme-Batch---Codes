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

//kth smallest element
void kthSmallest(Node* root,int i, int ans, int k){
    
    if(root == NULL){
        return ;
    }

    kthSmallest(root->left, i, ans, k);
    //increment i each time root->left does not exit
    i++;

    if(i == k){
        ans = root->data;
        return;
    }

    kthSmallest(root->left, ans, k);



}


int main(){
    Node* root = NULL;
    cout << "Enter data for node: " << endl;
    takeInput();

    int i=0;
    int ans = -1;
    int k = 5;
    kthSmallest(root, i, ans, k);

    return 0;
}