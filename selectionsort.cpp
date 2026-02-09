#include <iostream>
using namespace std;

void selectionsort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
}

void printarr(int n, int arr[])
{
    cout << "sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "array size?\n";
    cin >> n;
    int arr[n];
    cout << "array elements?\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionsort(n, arr);
    printarr(n, arr);
    return 0;
}