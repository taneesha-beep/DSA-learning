#include <iostream>
#include <vector>
using namespace std;

// brute force
void tripletsum_bf(vector<int> &arr, int s)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == s)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                }
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
    tripletsum_bf(arr, s);
    return 0;
}