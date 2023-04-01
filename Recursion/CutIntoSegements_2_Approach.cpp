#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }

    if(n < 0){
        return INT_MIN;
    }

    int a = solve(n-x, x,y,z) + 1;
    int b = solve(n-y, x,y,z) + 1;
    int c = solve(n-z, x,y,z) + 1;
    
    int ans = max(a,max(b,c));
    return ans;
}

int main()
{

    int n = 8;
    int x = 5;
    int y = 2;
    int z = 2;

    // returns max no of segments
    int ans = solve(n, x, y, z);

    if(ans < 0){
        ans = 0;
    }
    cout << "The rod can be cut into " << ans << " segments. " << endl;

    return 0;
}