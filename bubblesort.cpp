#include <iostream>
using namespace std;

/*
    Optimized Bubble Sort
    - Reduces inner loop range
    - Stops early if array is already sorted
*/
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no elements were swapped, array is sorted
        if (!swapped)
            break;
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array:\n";
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
