#include <iostream>
using namespace std;

int bs(int key, int a[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;

        else if (key < a[mid])
            high = mid - 1;

        else if (key > a[mid])
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cout << "enter key to search: ";
    cin >> key;
    int result = bs(key, a, n);
    if (result != -1)
        cout << "Key found at index " << result;
    else
        cout << "Key not found";
    return 0;
}