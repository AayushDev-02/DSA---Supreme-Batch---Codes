#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>arr, int target, int output){

    if(output == target){
        return 0;
    }

    if(output > target){
        return INT_MAX;
    }

    int mini = INT_MAX;
    for(int i=0; i<arr.size() ; i++){
        int ans = solve(arr, target, arr[i] + output);

        if(ans != INT_MAX){
            mini = min(ans+1, mini);
        }
    }

    return mini;

}

int main(){

    vector<int> arr{1,2,3};
    int target = 5;
    int output = 0;
    int mini = INT_MAX;
    int ans = solve(arr, target, output);

    cout << ans;


    return 0;
}