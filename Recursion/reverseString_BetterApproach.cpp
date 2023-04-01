#include <iostream>
using namespace std;

void reverse(string &s, int start, int end){
    if(start > end){
        return;
    }

    swap(s[start], s[end]);

    reverse(s, start+1, end-1);

}

int main(){

    string s= "abcd";
    int start = 0;
    int end = s.length() - 1;

    reverse(s,start, end);

    cout << s << endl; 

    return 0;
}