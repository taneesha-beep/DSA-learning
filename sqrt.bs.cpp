#include <iostream>
using namespace std;

int floorSqrt(int n)
{
    int s = 0;
    int e = n;
    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        long long square = mid * mid;

        if (square > n)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n; // input number

    cout << floorSqrt(n) << endl;

    return 0;
}
