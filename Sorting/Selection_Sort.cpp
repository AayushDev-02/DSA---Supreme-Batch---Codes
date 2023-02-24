#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &arr, int n){

    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }

    return ;

}



int main(){

    vector<int> arr{19,12,10,11,4};

    selection_sort(arr,5);

    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }

    cout << endl;


    return 0;
}