#include <iostream>
using namespace std;

bool sorted(int arr[], int n){
    if(n==0){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }
    else{
        sorted(arr+1, n-1);
    }

    return true;
}



int main(){

    int arr[5] = {1,0,3,4,5};
    int n=5;
    int maxi = INT_MIN;
    bool ans = sorted(arr, n);

    if(ans){
        cout << "Array is sorted!" << endl;
    }else{
        cout << "Array is not sorted!" << endl;
    }

    return 0;
}