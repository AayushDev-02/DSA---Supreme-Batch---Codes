#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int size, int &postIndex, int inorderStart, int inorderEnd ){
        if(postIndex < 0 || inorderStart > inorderEnd){
            return NULL;
        }

        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);
        int pos = findElement(inorder, size, element);

        root->right = solve(inorder, postorder, size, postIndex, pos+1, inorderEnd);
        root->left = solve(inorder, postorder, size, postIndex, inorderStart, pos-1);

        return root;

    }

    int findElement(vector<int>& inorder, int size, int &element){

        for(int i=0; i<size; i++){
            if(inorder[i] == element){
                return i;
            }
        }

        return -1;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int size = inorder.size();
        int postIndex = size-1;
        int inorderStart = 0;
        int inorderEnd = size-1;

        TreeNode* root = solve(inorder, postorder, size, postIndex, inorderStart, inorderEnd);

        return root;


    }
};