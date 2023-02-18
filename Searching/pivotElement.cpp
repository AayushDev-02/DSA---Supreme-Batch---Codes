#include <iostream>
using namespace std;








int main(){
    // write a binary search function to find pivot element in an array
   

    int n;
    cin >> n;

    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = findPivot(arr, n);
    cout << "Pivot element is found at: " << ans << endl;

    

}