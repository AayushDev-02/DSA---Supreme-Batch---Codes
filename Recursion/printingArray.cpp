#include <iostream>
using namespace std;


void print(int arr[], int n){
    if(n==0){
        return;
    }

    print(arr+1, n-1);
    cout << arr[0] << " ";
}

int main(){

    int arr[5] ={10,20,30,40,50};
    int n = 5;

    print(arr, n);

    return 0;
}