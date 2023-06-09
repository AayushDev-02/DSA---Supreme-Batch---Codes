#include <iostream>
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
    if(!root) return;

    inOrderTraversal(root->left, arr);
    arr.push_back(root->data);
    inOrderTraversal(root->right, arr);

}

vector<int> merge2Array(vector<int> a, vector<int> b){
    int size = a.size() + b.size();
    vector<int> mergedArray(size);

    int i=0; 
    int j=0; int k=0;

    while(i<a.size() || j<b.size()){
        if(a[i] < b[i]){
            mergedArray[k++] = a[i];
            i++;
        }else{
            mergedArray[k++] = b[j];
            j++;
        }
    }

    while(i<a.size()){
        mergeArray[k++] = a[i];
        i++;
    }

    while(j<b.size()){
        mergeArray[k++] = b[j];
        j++;
    }

    return ans;
}

//merge 2 bst
Node* merge2BST(Node* root1, Node* root2){
    
    vector<int> bst1;
    vector<int> bst2;

    inOrderTraversal(root1, bst1);
    inOrderTraversal(root2, bst2);

    vector<int> mergedArray = merge2Array(bst1, bst2);

    int start = 0;
    int size = mergedArray.size();
    int end = size-1;
    //convert into bst 
    Node* root = convertBST(mergedArray,start, end);

}

Node* convertBST(vector<int> arr, int start, int end){
    if(start > end ){
        return NULL;
    }
    int mid = start+(end-start)/2;
    Node* root = new Node(arr[mid]);
    root-left = convertBST(arr, start, mid-1 );
    root-left = convertBST(arr, mid+1, end );

    return root;
}

int main(){

    Node* root = NULL;
    cout << "Creating BST - Enter data" << endl;
    takeInput(root);
    cout << "Traversing the tree" << endl;
    if(root == NULL){
        cout << "Root is null";
    }
    preOrder(root);



    return 0;
}