#include <iostream>
#include <string>
using namespace std;

void solve(string &s, string &part){
    int found = s.find(part);

    if(found != string::npos){

        string left = s.substr(0, found);
        string right = s.substr(found + part.length(), s.length());

        s = left + right;

        solve(s,part);
    }
    else{
        return;
    }
}


int main(){

    string s = "daabcbaabcbc";
    string part = "abc";

    solve(s,part);

    cout << s << endl;

    return 0;
}