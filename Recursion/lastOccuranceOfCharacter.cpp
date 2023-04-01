#include <iostream>
#include <string>
using namespace std;

void lastOccurance(string s, char x, int i, int &ans){      // left to right

    if(i >= s.length()){
        return;
    }

    if(s[i] == x){
        ans = i;
    }

    lastOccurance(s, x, i+1, ans);
}


void lastOccurance2(string s, char x, int i, int &ans){
    if(i<0){
        return;
    }

    if(s[i] == x){
        ans = i;
        return;
    }

    lastOccurance2(s,x, i-1, ans);
}



int main(){

    string s= "abcd";
    char x = 'b';
    int i=s.length() - 1;
    int ans = -1;

    lastOccurance2(s, x, i, ans);

    if(ans == -1){
        cout << "Element not found";
    }
    else{
        cout << ans << endl;
    }

    return 0;
}