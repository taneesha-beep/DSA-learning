#include <iostream>
using namespace std;

void printarr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void sort01_2pointer(int a[], int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        while (a[i] == 0)
            i++;
        while (a[j] == 1)
            j--;
        if (i < j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
}

int main()
{
    int n;
    cout << "enter n";
    cin >> n;
    int a[n];
    cout << "enter array elements 0/1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "sorted elements: ";
    sort01_2pointer(a, n);
    printarr(a, n);
    return 0;
}