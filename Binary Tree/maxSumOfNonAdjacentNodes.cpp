#include <iostream>
using namespace std;

pair<int, int> solve(Node* root){
        if(!root) return {0,0};
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> ans;
        
        ans.first = left.second + right.second + root->data;
        ans.second = max(left.first, left.second ) + max(right.first, right.second);
        
        return ans;
        
}

int getMaxSum(Node *root) 
    {
        pair<int,int> ans = solve(root);
        
        return max(ans.first, ans.second);
        
    }



int main(){
    return 0;
}