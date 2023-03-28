#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = arr.size();

    int key = 2;

    int index = binarySearch(arr, n, key);

    if (index == -1)
    {
        cout << "Element not found!" << endl;
    }
    else
    {
        cout << "Element found at index: " << index << endl;
    }

    return 0;
}