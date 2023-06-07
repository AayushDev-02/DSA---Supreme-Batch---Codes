#include <iostream>
#include <queue>
using namespace std;

class Node {
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

Node* buildTree(Node* root){
    int data;
    cout << " Enter the value of the node: " << endl;
    cin >> data;

    root = new Node(data);
    
    if(data == -1){
        return NULL;
    }

    cout << "Enter the left part of " << data << " : " << endl;
    root->left = buildTree(root->left);
    cout << "Enter the right part of " << data << " : " << endl;
    root->right = buildTree(root->right);


    return root;
}


//Level order traversal
void levelOrderTraversal(Node* root){

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
        }
        else{
            cout << temp->data << " ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

//inorder
void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//preorder
void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//postorder
void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

//creating a tree from level order traversal
void createTreeLOT(Node* &root){
    queue<Node*> q;
    int data;
    cout << "Enter the node value: ";
    cin >> data;

    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter the left node data : ";
        cin >> leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        } 

        int rightData;
        cout << "Enter the right node data : ";
        cin >> rightData;

        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        } 


    }
}



int main(){

    Node* root = NULL;

    // Node* head = buildTree(root);

    // levelOrderTraversal(head);
    // cout << endl;
    // inOrder(head);
    // cout << endl;
    // preOrder(head);
    // cout << endl;
    // postOrder(head);

    createTreeLOT(root);
    levelOrderTraversal(root);
    

    return 0;
}