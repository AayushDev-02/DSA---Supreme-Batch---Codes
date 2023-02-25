#include <iostream>
#include <string.h>
using namespace std;

void reverseString(char arr[]){
    int i = 0;
    int size = strlen(arr);

    for(; i<size/2; i++){
        swap(arr[i], arr[size-i-1]);
    }

    return;
}


int main(){

    char arr[100];
    cin >> arr;

    reverseString(arr);

    cout << arr << endl; 

    return 0;
}