#include <iostream>
using namespace std;

int main(){

    bool a = true;
    bool b = false;

    cout << (a & b) << endl;
    cout << (a | b) << endl;
    cout << (a^b) << endl;
    cout << (~a) << endl;

    int n = 10;
    cout << (n<<1) << endl; 
    cout << (n>>1) << endl; 
    return 0;
}