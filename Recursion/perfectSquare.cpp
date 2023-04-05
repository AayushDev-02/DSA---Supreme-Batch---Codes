#include <iostream>
#include <cmath>
using namespace std;

int numSquaresHelper(int n){

    //base case
    if(n==0){
        return 1;
    }

    if(n<0){
        return 0;
    }

    int ans = INT_MAX;
    int i=1;
    int end = sqrt(n);
    while( i <= end ){
        int perfectSquare = i*i;
        int noOfPerfectSquare = 1 + numSquaresHelper(n - perfectSquare);
        
        if(ans > noOfPerfectSquare) {  
            ans = noOfPerfectSquare;
        }

        i++;
    }

    return ans;
}



int numSquares(int n) {
    return numSquaresHelper(n) - 1;
}


int main(){

    int n = 13;

    cout <<  numSquares(n) << endl;



    return 0;
}