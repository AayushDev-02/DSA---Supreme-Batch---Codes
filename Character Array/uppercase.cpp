#include <iostream>
#include <string.h>
using namespace std;

void uppercase(char arr[])
{
    int size = strlen(arr);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {

            char ch = arr[i];
            ch = ch - 'a' + 'A';

            arr[i] = ch;
        }
    }

    return;
}

int main()
{

    char arr[100];
    cin >> arr;

    uppercase(arr);

    cout << arr;
}