#include <iostream>
#include <string>
using namespace std;

// int factorial(int n){
//     if(n==1){
//         return 1;
//     }

//     return n*factorial(n-1);
// }



// int main(){

//     // factorial 
//     int n=5;
//     int ans = factorial(5);
    
//     cout << "Factorial of 5 is: " << ans << endl;

//     return 0;
// }

// ------------------------------------------------- Fibonnacci series ---------------------

// int fib(int n){
//     if(n==0 || n==1){
//         return n;
//     }

//     return fib(n-1) + fib(n-2);
// }


// int main(){

//     // factorial 
//     int n=1;
//     int ans = fib(n);
    
//     cout << "5th Fib no is: " << ans << endl;

//     return 0;
// }

// -------------------------- nth stair problem --------------------------------------

// int stair(int n){
//     if(n<0){
//         return 0;
//     }
//     else if(n == 0 ){
//         return 1;
//     }

//     return (stair(n-1) + stair(n-2));
// }


// int main(){

//     int n = 1;

//     int no_of_ways = stair(n);

//     cout << no_of_ways << endl;

//     return 0;
// }

// ------------------------ Say Digits ------------------------------------------


// void sayDigits(int n, string arr[]){
//     if(n==0){
//         return; 
//     }

//     sayDigits(n/10, arr);
//     int digit = n%10;

//     cout << arr[digit] << " ";

// }


// int main(){
//     string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
//     int n = 1;

//     sayDigits(123, arr);
//     cout << endl;
//     return 0;
// }

// -----------------------------------------Check sorted or not ---------------------------------------


// bool checkSorted(int arr[],int size){
//     if(size == 0 || size == 1 ){
//         return true;
//     }

//     if(arr[0] > arr[1]){
//         return false;
//     }
//     else{
//         return checkSorted(arr+1, size-1);
//     }


// }


// int main(){

//     int arr[6] = {2,4,6,9,11,11};
//     bool ans = checkSorted(arr,6);

//     if(ans){
//         cout << "Array is sorted" << endl;
//     }
//     else{
//         cout << "Array is not sorted " << endl;
//     }


//     return 0;
// }

// ------------------------------------- Sum of Elements of array ----------------------------------------

// int sumArray(int arr[], int size){
//     if(size == 0){
//         return 0;
//     }

//     return arr[0] + sumArray(arr+1, size-1);
// }


// int main(){

//     int arr[5] = {3,2,200,1,6};
//     int ans = sumArray(arr, 5);

//     cout << "Sum of the array is: " << ans << endl;
//     return 0;
// }

// ------------------------------------- Linear Search ----------------------------------------

// bool linearSearch(int arr[], int size, int x){
//     if(size == 0){
//         return false;
//     }

//     if(arr[0] == x){
//         return true;
//     }
//     else{
//         return linearSearch(arr+1, size-1, x);
//     }
// }


// int main(){

//     int arr[10] = {1,2,3,55,23,32,80,33,50,11};
//     int x = 23;

//     bool ans = linearSearch(arr, 10, x);

//     if(ans){
//         cout << "Element found" << endl;
//     }
//     else{
//         cout << "Element not found" << endl;
//     }


//     return 0;
// }
// ------------------------------------- Binary Search ----------------------------------------

// bool binarySearch(int arr[], int start,int end, int x){
//     if(start > end){
//         return false;
//     }

//     int mid = start+ (end - start)/2;

//     if(arr[mid] == x){
//         return true;
//     }
//     else if(arr[mid] < x){
//         return binarySearch(arr, mid + 1, end, x);
//     }
//     else{
//         return binarySearch(arr, start, mid - 1, x);
//     }
// }


// int main(){

//     int arr[10] = {1,2,3,55,23,32,80,33,50,11};
//     int size = 10;
//     int x = 29;

//     int start = 0;
//     int end = size - 1;

//     bool ans = binarySearch(arr, start, end, x);

//     if(ans){
//         cout << "Element found" << endl;
//     }
//     else{
//         cout << "Element not found" << endl;
//     }


//     return 0;
// }

// ------------------------------------- Reverse a String ----------------------------------------


void reverseString(string &s, int size, int i){
    if(i > size - 1 - i){
        return;
    }

    swap(s[i], s[size  - 1 - i]);

    reverseString(s, size, i+1);
}

void reverseString_2pointer(string &s, int i, int j){
    if(i>j){
        return;
    }
    // cout << "Aaysuh" << endl;

    swap(s[i], s[j]);
    i++;
    j--;

    reverseString_2pointer(s, i, j);
}


int main(){

    string s = "abcde";
    int size = s.length();
    // reverseString(s,size, 0);
    reverseString_2pointer(s,0, size-1);

    cout << s <<  endl;

    return 0;
}
