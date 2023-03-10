#include <iostream>
using namespace std;

int factorial(int n){
    //base case
    if(n==1){
        return 1;
    }

    int fac = n*factorial(n-1);

    return fac;
}



int main(){

    int n;
    cout << "Enter the value : " << endl;
    cin>> n;

    int ans = factorial(n);

    cout << "Factorial is : " << ans << endl; 
    return 0;
}