#include <iostream>
using namespace std;

int main(){
    int n =5;
    for(int i=0; i<n; i++){
        cout << "Aayush" << endl;
        break;
    }

    cout << "Loop has ended!" << endl;

    for(int i=0; i<n; i++){
        if(i==2){
            continue;       // skips printing i for i=2
        }
        cout << i << endl;
        
    }

    return 0;
}