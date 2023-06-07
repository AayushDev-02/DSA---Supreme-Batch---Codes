#include <iostream>
#include <queue>
#include <vector>
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

//counting the leaf nodes
void leafCount(Node* root, int &count){
    if(root == NULL){
        return;
    }

    leafCount(root->left, count);
    if(root->left == NULL && root->right == NULL){
        count += 1;
    }
    leafCount(root->right, count);
}


//height of a binary tree
int getHeight(Node* root){
    if(root == NULL){
        return 0;
    }

    int left = getHeight(root->left);
    int right = getHeight(root->right);

    return (max(left, right) + 1);

}

//diameter of a binary tree
int getDiameter(Node* root){
    if(root == NULL){
        return 0;
    }

    int option1 = getDiameter(root->left);
    int option2 = getDiameter(root->right);

    int left = getHeight(root->left);
    int right = getHeight(root->right);
    int option3 = left + right + 1;

    int ans = max(option1, max(option2, option3));

    return ans;
}

//diameter of a binary tree  - efficient approach
pair<int,int> getDiameter2(Node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = getDiameter2(root->left);
    pair<int,int> right = getDiameter2(root->right);

    int option1 = left.first;
    int option2 = right.first;
    int option3 = left.second + right.second + 1;

    pair<int,int> ans;

    ans.first = max(option1, max(option2, option3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

//check for balanced tree
bool checkBalanced(Node* root){
    if(root == NULL){
        return true;
    }

    bool left = checkBalanced(root->left);
    bool right = checkBalanced(root->right);

    bool diff = abs(getHeight(root->left) - getHeight(root->right)) <= 1;

    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}

//check balanced - better complexity
pair<bool, int> checkBalanced2(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pait(true, 0);
        return p;
    }

    pair<bool, int> left = checkBalanced2(root->left);
    pair<bool, int> right = checkBalanced2(root->right);

    bool cnd1 = left.first;
    bool cnd2 = right.first;
    bool cnd3 = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.first = cnd1&&cnd2&&cnd3;
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

//identical tree or not
bool checkIdentical(Node* root1, Node* root2){

    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 == NULL && root2!= NULL){
        return false;
    }
    if(root1 != NULL && root2 == NULL){
        return false;
    }

    bool left = checkIdentical(root1->left, root2->left);
    bool right = checkIdentical(root1->right, root2->right);

    bool cnd3 = false;
    if(root1->data == root2->data){
        cnd3 = true;
    }

    return left && right && cnd3;
}

//sum tree check
pair<int, bool> checkSumTree(Node* root){
    if(root == NULL){
        pair<int,bool> p = make_pair(0,true);
        return p;
    }

    if(root->left == NULL && root->right == NULL){
        pair<int,bool> p = make_pair(root->data, true);
        return p;
    }

    pair<int,bool> left = checkSumTree(root->left);
    pair<int,bool> right = checkSumTree(root->right);

    bool cnd1 = left.second;
    bool cnd2 = right.second;

    bool cnd3 = (left.first + right.first == root->data);

    pair<int, bool> ans;
    ans.first = left.first + right.first + root->data;
    ans.second = cnd1&&cnd2&&cnd3;

    return ans;

}

//zig zag traversal
vector<int> zigzagTraversal(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){
        int s = q.size();
        vector<int> res(size);

        for(int i=0; i<size; i++){
            Node* frontNode = q.front();
            q.pop();
            int index;
            
            if(leftToRight){
                index = i;
            }else{
                index = size - i - 1;
            }

            res[index] = frontNode->data;

            if(frontNode -> left ){
                q.push(frontNode->left);
            }

            if(frontNode->right){
                q.push(frontNode -> right);
            }
        }

        leftToRight = !leftToRight;

        for(auto i: res){
            ans.push_back(i);
        }

    }
        return result;
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