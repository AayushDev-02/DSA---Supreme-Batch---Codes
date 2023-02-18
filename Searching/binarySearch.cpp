#include <iostream>
using namespace std;

//TODO: Push the codes on github

int binarySearch(int *arr, int element, int size)
{

    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int main()
{

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl;

    int element;
    cout << "Enter the element to search : ";
    cin >> element;
    cout << endl;

    int index = binarySearch(arr, element, n);

    if (index == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {

        cout << "Element found at index: " << index;
    }

    return 0;
}