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
    return 0;
}