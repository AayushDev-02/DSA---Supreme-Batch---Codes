#include <iostream>
#include <string>
using namespace std;


bool solve(string s, int si, string p,  int pi){

    // base cases

    if(si == s.size() && pi== p.size()){
        return true;
    }

    if(si == s.size() && pi < p.size()){
        while(pi < p.size()){
            if(p[pi] !='*'){
                return false;
            }
            pi++;
        }
        return true;
    }

    // processing :
    //condition 1
    if(s[si] == p[pi] || p[pi] == '?'){
        return solve(s, si+1, p, pi+1);
    }

    if(p[pi] == '*'){
        //case 1 - let * be null

        bool case1 = solve(s, si, p ,pi+1);

        //case 2 - let * consume one character from p
        bool case2 = solve(s, si+1, p ,pi);


        return case1 || case2;
    }


    // when the elements of s, p do not match and pi is not * this means that characters are different thus matching cannot be done
    return false;
}


bool isMatch(string s, string p) {

    //pointer for string s, p respectively
    int si = 0;
    int pi =0 ;

    return solve(s,si,p,pi);

}


int main(){

    string s,p;
    cout << "Enter the s string: " << endl;
    cin >> s;
    cout << "Enter the p string :" << endl;
    cin >> p;

    bool ans = isMatch(s,p);

    if(ans){
        cout << "Wildcard Matched!" << endl;
    }
    else{
        cout << "Wildcard Not Matched!" << endl;
    }
    return 0;
}