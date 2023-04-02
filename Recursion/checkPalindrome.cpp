#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string s, int start, int end)
{

    if (start > end)
    {
        return true;
    }

    if (s[start] != s[end])
    {
        return false;
    }

    return checkPalindrome(s, start + 1, end - 1);
}

int main()
{

    string s = "aaysuih";
    int start = 0;
    int end = s.length() - 1;
    bool ans = checkPalindrome(s, start, end);

    if (ans)
    {
        cout << "String is palindrome!" << endl;
    }
    else
    {
        cout << "String is not a Palindrome!" << endl;
    }

    return 0;
}