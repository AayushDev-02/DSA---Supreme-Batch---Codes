#include <iostream>
using namespace std;

int main()
{
    int n =5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }



        int count = 1;
        for (int j = 0; j < 2 * i + 1; j++)
        {
            
            if(i==0 || i==n-1){
                if(j % 2 == 0){
                    cout << count;
                    count++;
                }else{
                    cout <<  " "; 
                }
            }else{
                if(j==0){
                    cout << 1;
                }else if(j == 2*i){
                    cout << i+1;
                }
                else{
                    cout << " ";
                }
            }

        }
        cout << endl;
    }

    return 0;
}