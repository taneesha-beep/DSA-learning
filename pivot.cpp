#include <iostream>
using namespace std;

int findPivot(vector<int> &arr)
{
    int s = 0;
    int e = arr.size() - 1;

    if (arr[s] <= arr[e])
    {
        return e;
    }

    while (s < e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }

    return s - 1;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout << "Pivot index: " << findPivot(arr);
    return 0;
}
