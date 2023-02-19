#include <iostream>
using namespace std;

int binarySearch(int divisor, int dividend)
{
    int s = 0;
    int e = dividend;
    int mid = s + (e - s) / 2;
    int ans = 1;

    while (s <= e)
    {
        // perfect solution
        if(mid* divisor == dividend){
            ans = mid;
            break;
        }

        //not perfect solution
        if ( mid * divisor < dividend)
        {
            ans = mid;
            s = mid+1;
        }
        
        //not perfect sol
        if(mid * divisor > dividend){
            e = mid-1;
        }

        mid = s + (e-s)/2;
    }

    return ans;
}

int main()
{

    int divisor = 7;
    int dividend = -22;

    int quotient = binarySearch(abs(divisor), abs(dividend));

    if((divisor < 0 && dividend > 0) || (divisor >0 && dividend < 0)){
        quotient = -quotient;
    }

    cout << "Quotient is: " << quotient << endl;

    return 0;
}
