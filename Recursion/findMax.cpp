#include <iostream>
using namespace std;

void findMax(int arr[], int n, int i,int &maxi){
    if(i >=n){
        return ;
    }

    if(arr[i] > maxi){
        maxi = arr[i];
    }

    findMax(arr, n, i+1, maxi);
}

int main(){
    int arr[7] = {1,2,3,4,10,2,3};
    int maxi= INT_MIN;
    
    findMax(arr, 7, 0, maxi);

    cout << maxi;
    return 0;
}