#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int n, int key, int start, int end)
{

    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] > key)
    {

        return binarySearch(arr, n, key, start, mid - 1);
    }
    else
    {
        return binarySearch(arr, n, key, mid + 1, end);
    }
}

int main()
{

    vector<int> arr = {1, 5,7,23,44,60};
    int n = arr.size();

    int key = 44;

    int start = 0;
    int end = n - 1;
    int index = binarySearch(arr, n, key, start, end);

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