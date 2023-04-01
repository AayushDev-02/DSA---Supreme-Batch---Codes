#include <iostream>
#include <string>
using namespace std;

void reverseString(string &s, string &output, int i){
    if(i>=s.length()){
        return;
    }

    reverseString(s, output, i+1);

    output.push_back(s[i]);

}


int main(){

    string s = "abcd";
    string output = "";
    int i=0;
    reverseString(s, output, i);

    cout << output << endl;


    return 0;
}