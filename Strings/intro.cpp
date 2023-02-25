#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(){
    string str = "Aayush Yadav";
    cout << str << endl;

    // char arr[100];
    // arr[0]= 'a';
    // arr[1]= '\0';
    // arr[2]= 'a';
    // arr[3]= 'a';
    // arr[4]= '\0';
    
    // cout << arr;

    string s = 'aa\0awukdb\0';

    cout << s;

    return 0;
}