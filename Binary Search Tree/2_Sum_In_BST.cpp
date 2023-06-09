#include <iostream>
#include <vector>
using namespace std;

class Node {
    public :
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = buildBST(root->right, data);
    }
    else{
        root->left = buildBST(root->left, data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cout << "Enter the data : "; 
    cin >> data;
    

    while(data != -1){
        root = buildBST(root, data);
        cout << "Enter the data : "; 
        cin >> data;
    }
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrderTraversal(Node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left, arr);
    arr.push_back(root->data);
    inOrderTraversal(root->right, arr);
}

void TwoSum(Node* root, vector<int> &ans, int target){

    vector<int> inorder;
    inOrderTraversal(root,inorder);

    int i=0; int j = inorder.size()-1;

    while(i<=j){
        int sum = inorder[i] + inorder[j];
        
        if(sum == target){
            ans.push_back(inorder[i]);
            ans.push_back(inorder[j]);
            return;
        }
        else if(sum < target){
            i+=1;
        }else j= j-1;
    }

    return;
}



int main(){

    Node* root = NULL;
    cout << "Creating BST - Enter data" << endl;
    takeInput(root);

    vector<int> ans;
    int target = 15;

    TwoSum(root, ans, target);

    cout << endl;

    for(auto i: ans){
        cout << i << " " ;
    }

    cout << endl;



    return 0;
}