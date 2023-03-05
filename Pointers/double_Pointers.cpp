#include <iostream>
using namespace std;

int main(){

    int a = 5;
    int *q = &a;
    int **p = &q;

    cout << q << endl;
    cout << *q << endl;
    cout << &q << endl;
    cout << a << endl;
    cout << &a << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << **p << endl;
    cout << &p << endl;



    return 0;
}