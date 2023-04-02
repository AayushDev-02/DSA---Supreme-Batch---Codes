#include <iostream>
using namespace std;


class Solution {
public:

    void solve(vector<int>&nums , int i, int output, int &maxi){
        if(i >= nums.size()){
            maxi = max(maxi, output);
            return ;
        }

        //exclude
        solve(nums, i+1, output, maxi);

        //include
        output+=nums[i];
        solve(nums, i+2, output, maxi);
    }

    int rob(vector<int>& nums) {
        int i=0;
        int output = 0;
        int maxi = INT_MIN;
        solve(nums, i, output, maxi);

        return maxi;
    }
};