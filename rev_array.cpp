#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;
    int a[n];
    cout << "enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cout << "enter m from where array has to be reversed: ";
    cin >> m;
    for (int i = 0; i <= m; i++)
        cout << a[i] << " ";
    for (int i = n - 1; i > m; i--)
        cout << a[i] << " ";
    return 0;
}