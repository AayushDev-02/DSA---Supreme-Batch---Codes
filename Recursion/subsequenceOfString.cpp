#include <iostream>
#include <string>
#include <vector>
using namespace std;


void printSubsequence(string str, string output, int i, vector<string> &v){
    if(i >= str.length()){
        cout << output << " ";
        return;
    }

    //exclude call
    printSubsequence(str, output, i+1, v);

    //include call
    output.push_back(str[i]);
    v.push_back(str[i]);
    printSubsequence(str, output, i+1, v);


}



int main(){

    string str = "abc";
    string output = "";

    vector<string> v;

    int i=0;
    printSubsequence(str, output, i, v);

    cout << "Printing all subsequences :" << endl;

    for(auto val:v) {
        cout << val << " ";
    }

    return 0;

}