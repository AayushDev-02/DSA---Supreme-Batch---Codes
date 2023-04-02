#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void addString(string &s1 , int p1, string &s2,int p2, int carry, string &ans){
    
    //base case
    if(p1 < 0 && p2 < 0){
        if(carry != 0){
            ans.push_back(carry + '0');
        }

        return ;
    }

    int n1 = ((p1 >= 0) ? s1[p1] : '0' ) - '0';
    int n2 = ((p2 >= 0) ? s2[p2] : '0' ) - '0';
    int sum = n1+ n2 + carry;
    int digit = sum%10;
    carry = sum/10;
    ans.push_back(digit + '0');

    addString(s1,p1-1, s2,p2-1, carry, ans);

}


int main(){

    string s1 = "123";
    string s2 = "456";
    int p1 = s1.length() - 1;
    int p2 = s2.length() - 1;

    string ans = "";
    addString(s1,p1,s2,p2,0,ans);

    reverse(ans.begin(), ans.end());

    cout << "The sum of the strings is: " << ans;


    return 0;
}