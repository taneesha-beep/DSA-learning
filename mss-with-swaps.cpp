#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// function to calculate maximum subarray sum (brute force)
int maxSubarraySum(vector<int> &a, int n)
{
    int max_sum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            max_sum = max(max_sum, sum);
        }
    }

    return max_sum;
}

// function to calculate max subarray sum using kadane's algorithm
int kadane(vector<int> &a, int n)
{
    int current = a[0], maxsum = a[0];

    for (int i = 1; i < n; i++)
    { // starting from i=1 cause 0th position is already initialised.
        current = max(a[i], current + a[i]);
        maxsum = max(maxsum, current);
    }
    return maxsum;
}

int main()
{ // INPUTS
    cout << "enter array size, k, and array elements:\n";
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // BRUTE FORCE
    int best = INT_MIN;
    // try all possible swaps
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // swap
            swap(a[i], a[j]);

            // calculate MSS after swap
            int current = maxSubarraySum(a, n);

            // update best answer
            best = max(best, current);

            // undo swap
            swap(a[i], a[j]);
        }
    }

    // no swap case
    best = max(best, maxSubarraySum(a, n));

    cout << "answer using brute force: \n"
         << best << endl;

    // KADANE
    int best1 = kadane(a, n);

    // improving array using swaps (greedy attempt)
    for (int i = 0; i < n && k > 0; i++)
    {
        for (int j = n - 1; j > i && k > 0; j--)
        {
            if (a[j] > a[i])
            {
                swap(a[i], a[j]);
                k--;
            }
        }
    }

    best1 = max(best1, kadane(a, n));
    cout << "answer using kadane algorithm (may not always be correct):\n"
         << best1 << endl;

    return 0;
}