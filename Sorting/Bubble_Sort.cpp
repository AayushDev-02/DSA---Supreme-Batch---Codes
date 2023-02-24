#include <iostream>
#include <vector>
using namespace std;


void bubbleSort(vector<int> &arr, int n){
    for(int i=1; i<n; i++){
        bool swapped = false;
        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swapped = true;
                swap(arr[j], arr[j+1]);
            }
        }

        if(swapped == false){
            break;
        }
    }

    return;
}



int main(){


    vector<int> arr{10,1,7,5,2,4};
    int n = arr.size();

    bubbleSort(arr, 6);

    for(int i=0; i<6; i++){
        cout << arr[i] << " ";
    }

    cout << endl;


    return 0;
}