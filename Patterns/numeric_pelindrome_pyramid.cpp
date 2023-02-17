#include <iostream>
using namespace std;

int main(){

    for(int i=0; i<5; i++){
        int j=0;
        for(; j<i+1; j++){
            cout << j+1 << " ";
        }
        j=j-1;
        for(; j>0; j--){
            cout << j << " ";
        }

        cout << endl;
    }
    
    cout << endl;

    for(int i=0; i<5; i++){
        int j=0;
        for(; j<i+1; j++){
            int ans = j + 1;
            char ch= ans + 'A' - 1;
            cout << ch <<  " ";
        }
        j=j-1;
        for(; j>0; j--){
            int ans = j;
            char ch = ans+ 'A' - 1;
            cout << ch << " ";
        }

        cout << endl;
    }
    return 0;
    return 0;
}