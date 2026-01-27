#include <iostream>
using namespace std;

int mylogic(int arr[], int n, int k)
{
    int first = -1;
    int last = -1;
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        if (arr[low] == k && first == -1)
            first = low;
        low++;

        if (arr[high] == k && last == -1)
            last = high;
        high--;
    }
    cout << first << " " << last << endl;
}
int bs(int arr[], int n, int k)
{
    int first = -1, last = -1;

    // first occurrence
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    // last occurrence
    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << first << " " << last << endl;
}

int main()
{
    int a[4] = {0, 1, 1, 5};
    int k = 1;
    cout << "first and last occurrence of 1 at indexes (my logic): ";
    mylogic(a, 4, k);
    cout << "first and last occurrence of 1 at indexes (binary search logic): ";
    bs(a, 4, k);
    return 0;
}