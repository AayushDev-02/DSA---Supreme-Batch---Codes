#include <iostream>
#include <vector>
using namespace std;

// Method 1
int solve(vector<int> &arr, int n){
    if(n==0){
        return 0;
    }

    if(n<0){
        return INT_MAX;
    }

    int mini = INT_MAX;
    for(int i=0; i<arr.size(); i++){
        int ans = solve(arr, n-arr[i]);
        if(ans!=INT_MAX){
            mini = min(mini, ans + 1);
        }
    }

    return mini;
}


int main(){


    vector<int> arr{5,2,2};
    int n = 7;
    int ans = solve(arr, n);
    
    cout << "The rod can be cut into " << ans << " segments. " << endl; 

    return 0;
}