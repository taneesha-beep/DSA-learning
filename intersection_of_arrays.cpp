// intersection of two arrays i.e, finding common elements from both arrays and printing them.

#include <iostream>
#include <climits>
using namespace std;

int bruteforce_approach(int a[], int b[], int n, int m)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                ans = a[i];
                cout << ans << endl;
                b[j] = INT_MIN;
                break;
            }
        }
    }
    return ans;
}

int twopointer_approach(int a[], int b[], int n, int m)
{
    int ans;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            ans = a[i];
            cout << ans << endl;
            i++;
            j++;
        }
        else if (a[i] < b[j])
            i++;

        else
            j++;
    }
    return ans;
}

int main()
{
    int n, m;
    cout << "enter n and m: ";
    cin >> n >> m;
    int a[n], b[m];
    cout << "enter first array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "enter second array elements: ";
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << "intersection elements by two pointer approach (optimised): ";
    twopointer_approach(a, b, n, m);
    cout << "intersection elements by brute force approach: ";
    bruteforce_approach(a, b, n, m);

    return 0;
}