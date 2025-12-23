#include <iostream>
#include <vector>
using namespace std;

// brute force
void pairsum_bf(vector<int> &arr, int s)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == s)
            {

                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
}

int main()
{
    int n;

    int s;
    cout << "enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "enter elements: ";
    for (int &i : arr)
    {
        cin >> i;
    }
    cout << "enter sum: ";
    cin >> s;
    pairsum_bf(arr, s);
    return 0;
}