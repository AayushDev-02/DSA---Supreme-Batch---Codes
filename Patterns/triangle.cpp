#include <iostream>
using namespace std;

int main()
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }

    cout << endl;

    int n = 4;
    for (int i = 0; i < 4; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << "*"
                 << " ";
        }

        cout << endl;

        int n = 4;
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << " "
                 << " ";
        }
        for (int j = n; j > i; j--)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << " "
                 << " ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << " "
                 << " ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*"
                 << " ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*"
                 << " ";
        }
        for (int j = n; j > i; j--)
        {
            cout << " "
                 << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << " "
                 << " ";
        }
        for (int j = n; j > i; j--)
        {
            cout << "*"
                 << " ";
        }
        for (int j = n; j > i; j--)
        {
            cout << "*"
                 << " ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << " "
                 << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    
    

    return 0;
}
