#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int s, int e, int target){
    int mid = s+(e-s)/2;

    while(s<=e){
        if(target == arr[mid]){
            return mid;
        }
        if( mid-1 >= s && target == arr[mid-1]){
            return mid-1;
        }
        if(mid+1 < arr.size() && target == arr[mid+1]){
            return mid+1;
        }

        if(arr[mid] < target){
            s= mid+2; 
        }else{
            e=mid-2;
        }

        mid = s+(e-s)/2;
    }
    return -1;
}


int main(){

    vector<int> arr {10,3,40,20,50,80,70};

    int target = 0;

    int ans = binarySearch(arr,0,arr.size()-1,target);
    if(ans == -1){
        cout << "EElement not found! "
    }
    cout << "The target is at index: " << ans << endl;

    return 0;
}