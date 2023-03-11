#include <iostream>
using namespace std;

bool checkKey(string& s,int& n,int& i, char& key){
    if(i>=n){
        return false;
    }

    if(s[i] == key){
        return true;
    }
    int newi = i+1;
    bool ans = checkKey(s, n, newi, key);

    return ans;

}

int main(){
    
    string s= "Aayush";
    char key = 's';
    int n =s.length();
    int i=0;
    bool ans = checkKey(s, n,i, key);

    cout << "Answer is: " << ans << endl;
    return 0;
}