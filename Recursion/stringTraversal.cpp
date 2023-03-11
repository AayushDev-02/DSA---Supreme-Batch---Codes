#include <iostream>
using namespace std;

bool checkKey(string s,int n,int i, char key){
    if(i>=n){
        return false;
    }

    if(s[i] == key){
        return true;
    }

    bool ans = checkKey(s, n, i+1, key);

    return ans;

}

int main(){
    
    string s= "Aayush";
    char key = 's';
    int n =s.length();
    
    bool ans = checkKey(s, n,0, key);

    cout << "Answer is: " << ans << endl;
    return 0;
}