#include <iostream>
#include <string.h>
using namespace std;

void replace(char arr[], char str){
    int size = strlen(arr);

    for(int i=0; i<size; i++){
        if(arr[i] == ' '){
            arr[i] = str;
        }
    }

    return;
}


int main(){

    char arr[100];
    cin.getline(arr, 100);

    replace(arr, '@');

    cout << arr << endl;
    return 0;
}