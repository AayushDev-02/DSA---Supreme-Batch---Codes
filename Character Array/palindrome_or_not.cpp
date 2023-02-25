#include <iostream>
#include <string.h>
using namespace std;


bool checkPalindrome(char arr[]){
    int size = strlen(arr);
    bool ans = true;
    for(int i=0; i<size/2; i++){
        if(arr[i] != arr[size-1-i] ){
            ans = false;
            break;
        }
    }

    return ans;
}


int main(){

    char arr[100];

    cin >> arr;

    bool ans = checkPalindrome(arr);

    if(ans){
        cout << " Is palindrome" << endl;
    }else{
        cout << "Not a palindrome" << endl;
    }

    return 0;
}