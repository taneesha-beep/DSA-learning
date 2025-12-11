#include <iostream>
#include <climits>
using namespace std;

void printarr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void swap_alt(int a[], int n)
{
    int cursor1, cursor2;
    cursor1 = 0;
    cursor2 = 1;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n)
        {
            swap(a[cursor1], a[cursor2]);
            cursor1 += 2;
            cursor2 += 2;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    swap_alt(a, n);
    printarr(a, n);
    return 0;
}