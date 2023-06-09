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

//Boundary Traversal
vector<int> boundaryTraversal(Node* root){
    
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);
    leftTraversal(root->left, ans);
    leafTraversal(root, ans);
    rightTraversal(root->right,ans)

}

//left traversal - excluding the leaf nodes
void leftTraversal(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    ans.push_back(root->data);

    if(root->left){
        leftTraversal(root->left);
    }
    else{
        leftTraversal(root->right);
    }
}

//right traversal - excluding the leaf nodes
void rightTraversal(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right){
        rightTraversal(root->right);
    }
    else{
        rightTraversal(root->left);
    }

    ans.push_back(root->data);
}

//leaf traversal
void leafTraversal(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root);
    }

    leafTraversal(root->left);
    leafTraversal(root->right);
}

//vertical traversal of binary tree
vector<int> verticalTraversal(Node* root){

    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node*, pair<int,int>>> q;
    q.push(root, make_pair(0,0));

    while(!q.empty()){
        pair<Node*, pair<int,int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        //pushing element into the map on the basis of - level and hd
        nodes[hd][level].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd-1, level+1)));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(hd+1, level+1)));
        }
    }

    for(auto i: nodes){
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;
}

//top view
vector<int> topView(Node* temp){
    
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int,int> nodes;
    queue<pair<Node* , int>> q;

    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        //inserting into map

        if(nodes.find(hd) == nodes.end()){
            nodes[hd] = frontNode->data;
        }
        
        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i: nodes){
        ans.push_back(i.second);
    }

    return ans;
}

// Bottom View 

vector<int> bottomView(Node* root){

    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    map<int,int> nodes;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        //inserting into the map
        nodes[hd] = frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i: nodes){
        ans.push_back(i.second);
    }

    return ans;
}

//left view
void leftView(Node* root, vector<int> &ans, int level){

    if(root == NULL){
        return;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

//right view
void rightView(Node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->right, ans, level);
    solve(root->left, ans, level);
}

//sum of longest bloodline in a tree
void bloodLine(Node* root, int sum, int &maxSum, int length, int &maxLength){

    if(root == NULL){
        if(length > maxLength){
            maxLength = length;
            maxSum = sum;
        }
        else if( length == maxLength){
            maxSum = max(maxSum, sum);
        }
        
        return;
    }

    sum+=root->data;

    bloodLine(root->left, sum, maxSum, length + 1, maxLength);
    bloodLine(root->right, sum, maxSum, length + 1, maxLength);

}

//lowest common ancestors

Node* lowestCommonAncestors(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left = lowestCommonAncestors(root->left, n1,n2);
    Node* right = lowestCommonAncestors(root->right, n1,n2);

    if(left == NULL && right == NULL){
        return NULL;
    }

    else if(left == NULL && right != NULL){
        return right;
    }

    else if(left != NULL && right == NULL){
        return left;
    }

    else (left != NULL && right != NULL){
        return root;
    }
}

// k sum paths
void kSumPath(Node* root, int k, int &count, vector<int> &path){

    if(root == NULL){
        return;
    }

    path.push_back(root);

    kSumPath(root->left, k, count, path);
    kSumPath(root->right, k, count, path);

    int size = path.size();
    int sum = 0;

    for(int i=size - 1; i>=0; i--){
        sum+=path[i];

        if(sum == k){
            count ++;
        }
    }

}

//kth ancestor
Node* kthAncestor(Node* root, int &k, int n){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n){
        return root;
    }

    Node* left = kthAncestor(root->left, k, n);
    Node* right = kthAncestor(root->right, k, n);

    if(left!= NULL && right==NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }

        return left;
    }
    else if(right != NULL && left == NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }

        return right;
    }
    else{
        return NULL;
    }

}


//morris traversal
vector<int> morrisTraversal(Node* root) {
    vector<int> ans;
    if(!root) return ans;
    Node* curr = root;

    while(curr != NULL){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* pred = curr->left;
            while(pred->right && pred->right != curr){
                pred = pred->right;
            }

            //case1: right is null
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }else{
                pred->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return ans;
}

//flatten a binary tree into linked list
void flatten(Node* root) {
        if(root == NULL) return;
        TreeNode* curr = root;

        while(curr!=NULL){

            if(curr->left == NULL){

                curr = curr->right;

            }else{  
                TreeNode* pred = curr->left;
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                }

                if(pred->right == NULL){
                    pred->right = curr->right;
                    curr->right = curr->left;
                    curr->left = NULL;
                    curr = curr->right;
                }
                else{
                    curr->right = curr->left;
                    curr->left = NULL;
                }

            }

        }
    }

//tree from inorder and preorder
Node* buildTreeFromPreOrderInOrder(vector<int> &preorder, vector<int> &inorder, int size, int preIndex, int inorderStart, int inorderEnd){
    
    //base case - preIndex should be within the array/vector
    if(preIndex >= size || inorderStart > inorderEnd){
        return NULL;
    }

    //stepA : 
    int element = preorder[preIndex++];
    Node* root = new Node(element);

    //finding the element in the inorder array
    int position = findPosition(inorder, size, element);

    root->left = buildTreeFromPreOrderInOrder(preorder, inorder, size, preIndex, inorderStart, position - 1);
    root->right = buildTreeFromPreOrderInOrder(preorder, inorder, size, preIndex, position+1, inorderEnd);

    return root;
}

int findPosition(vector<int> &inorder, int size, int element){
    for(int i=0; i<size; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
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