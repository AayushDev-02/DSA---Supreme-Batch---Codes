#include <iostream>
using namespace std;

int main(){

    vector<int> arr{10,1,7,6,14,9};

    for(int i=1; i<6; i++){
        //step 1: Fetch
        int val = arr[i];

        //step 2: Compare
        for(int j=i-1; j>=0; j--){
            if(arr[j] > val){
                //shift
                arr[j+1] = arr[j];
            }
            else{
                //rukna hai
                break;
            }
        }

        //step 3: copy
        arr[j] = val;



    }

    return 0;
}