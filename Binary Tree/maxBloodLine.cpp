#include <iostream>
using namespace std;


void bloodLine(Node* root, int length, int &maxLength, int sum, int maxSum){
    if(root == NULL){
        if(length > maxLength){
            maxLength = len;
            maxSum = sum;
        }else if(length == maxLength){
            maxSum = max(maxSum, sum);
        }

        return ;
    }

    sum+=root->data;

    bloodLine(root->left, length+1, maxLength, sum, maxSum);
    bloodLine(root->right, length+1, maxLength, sum, maxSum);
}

int main(){
    
    int length = 0;
    int maxLength = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    bloodLine(root, length, maxLength, sum, maxSum);
    return 0;
}