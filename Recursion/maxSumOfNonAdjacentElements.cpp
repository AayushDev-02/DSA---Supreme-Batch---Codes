#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &arr, int sum,int i, int  &maxi){
    if(i >= arr.size() ){
        maxi = max(sum, maxi);
        return;
    }

    // exclude
    solve(arr, sum, i+1, maxi);

    //include
    sum+=arr[i];
    solve(arr, sum, i+2, maxi);

    

}

int main(){

    vector<int> arr{1,2,4};
    int sum = 0;
    int maxi=INT_MIN;
    int i =0;
    
    solve(arr, sum,i,  maxi);

    cout << "Max sum of non adjucent elements is: " << maxi;



    return 0;
}