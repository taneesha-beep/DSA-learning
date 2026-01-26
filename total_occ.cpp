#include <iostream>
using namespace std;

int totalocc(int a[], int n, int el)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == el)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int n;
    cout << "enter n";
    cin >> n;
    int a[n];
    cout << "enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int el;
    cout << "enter element for finding occurence: ";
    cin >> el;
    int res = totalocc(a, n, el);
    cout << "total occurences: " << res;
    return 0;
}