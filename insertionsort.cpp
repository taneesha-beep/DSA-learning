#include <iostream>
using namespace std;

/*
    Insertion Sort
    - Builds the sorted array one element at a time
    - Shifts elements to the right to make space
*/
void insertionSort(int n, vector<int> &arr)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i]; // Element to be inserted
        int j = i - 1;

        // Shift elements greater than temp to the right
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place temp at correct position
        arr[j + 1] = temp;
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

    insertionSort(n, arr);

    cout << "Sorted array:\n";
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
