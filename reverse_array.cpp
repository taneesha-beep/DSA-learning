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

void reverse(int a[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }
}

bool ls(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int a[5] = {3, 4, 5, 6, 7};
    int b[6] = {2, 8, 3, 0, 9, 1};
    reverse(a, 5);
    reverse(b, 6);
    printarr(a, 5);
    printarr(b, 6);
    return 0;
}