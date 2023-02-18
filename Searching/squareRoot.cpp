#include <iostream>
using namespace std;

int findSqrt (int n){
    int s = 0;
    int e = n;
    int mid = s+(e-s)/2;
    int ans;

    while(s<=e){
        if(mid*mid == n){
            return mid;
        }
        else if(mid*mid < n){
            ans = mid;
            s= mid+1;
        }
        else{
            e= mid-1;
        }
        mid = s+(e-s)/2;
    }

    return ans;
}



int main(){

    int n;
    cout << "Enter the number : ";
    cin >> n;

     int precision;
    cout << "Enter the no of floating digits in precision: ";
    cin >> precision;

    int ans = findSqrt(n);

    double finalAns;
    double step = 0.1;

    for(int i=0; i<precision; i++){
        for(double j = ans ; j*j <=n; j+=step){
            finalAns = j;
        }

        step = step/10;
    }

    cout << finalAns << endl;

    return 0;
}