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

int findElement(int inorder[], int size, int element){
    for(int i=0; i<size; i++){
        if(inorder[i] == element){
            return i;
        }
    }

    return -1;
}

//build tree from inorder and preorder traversal
Node* buildTreeFromInorderPreorder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd){

    //base case
    if(preIndex >= size || inorderStart > inorderEnd){
        return NULL;
    }


    //Step 1: create the root node
    int element = preorder[preIndex++];
    Node* root = new Node(element);

    //step 2: find the element in the inoorder array:
    int pos = findElement(inorder,size, element);    
       
    // replace the above line  with map to reduce time complexity
    // int pos = nodeInorder[element];


    //step3 - make the left subtree
    root->left = buildTreeFromInorderPreorder(inorder, preorder, size, preIndex, inorderStart, pos-1);
    //step4 - make the right subtree
    root->right = buildTreeFromInorderPreorder(inorder, preorder, size, preIndex, pos+1, inorderEnd);


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

 void findIndex(int inorder[], map<int,int> &nodeInorder, int n){

        for(int i=0; i<n; i++){
            nodeInorder[inorder[i]] = i;
        }

    }

int main(){

    int inorder[] = {3,1,4,5,2};
    int preorder[] = {5,1,3,4,2};
    int preIndex = 0;
    int size = 5;
    int inorderStart = 0;
    int inorderEnd = size-1;

    // done to reduce the time complexity of finding the element in inorder array - use map - O(1)
    // map<int, int> nodeInorder;
    // findIndex(inorder, nodeInorder,  n);


    Node* root = buildTreeFromInorderPreorder(inorder, preorder, size, preIndex, inorderStart, inorderEnd);

    cout << "Printing level order traversal: " << endl;
    LevelOrderTraversal(root);  

    return 0;
}