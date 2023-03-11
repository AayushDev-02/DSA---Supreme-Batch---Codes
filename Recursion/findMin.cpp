#include <iostream>
using namespace std;

void findMax(int arr[], int n, int i,int &mini){
    if(i >=n){
        return ;
    }

    if(arr[i] < mini){
        mini = arr[i];
    }

    findMax(arr, n, i+1, mini);
}

int main(){
    int arr[7] = {1,2,3,4,10,2,3};
    int mini= INT_MAX;
    
    findMax(arr, 7, 0, mini);

    cout << mini;
    return 0;
}