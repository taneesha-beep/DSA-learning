#include <bits/stdc++.h>
using namespace std;

/*
    This function checks whether it is possible to place
    'k' cows in the stalls such that the minimum distance
    between any two cows is at least 'mid'.
*/
bool isPossible(vector<int> &stalls, int k, int mid, int n)
{
    int cowCount = 1;        // First cow is placed
    int lastPos = stalls[0]; // Position of first cow

    for (int i = 0; i < n; i++)
    {
        // Check if current stall is far enough
        if (stalls[i] - lastPos >= mid)
        {
            cowCount++; // Place next cow

            // If all cows are placed
            if (cowCount == k)
            {
                return true;
            }

            // Update last placed cow position
            lastPos = stalls[i];
        }
    }
    return false; // Not all cows could be placed
}

/*
    This function finds the maximum minimum distance
    between any two cows.
*/
int aggressiveCows(vector<int> &stalls, int k)
{
    // Sort stall positions
    sort(stalls.begin(), stalls.end());

    int n = stalls.size();

    int s = 0;             // Minimum possible distance
    int e = stalls[n - 1]; // Maximum possible distance
    int ans = -1;

    // Binary search on answer
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (isPossible(stalls, k, mid, n))
        {
            ans = mid;   // Store answer
            s = mid + 1; // Try bigger distance
        }
        else
        {
            e = mid - 1; // Reduce distance
        }
    }
    return ans;
}

int main()
{
    int n, k;

    cout << "Enter number of stalls: ";
    cin >> n;

    vector<int> stalls(n);
    cout << "Enter stall positions:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }

    cout << "Enter number of cows: ";
    cin >> k;

    int result = aggressiveCows(stalls, k);

    cout << "Maximum minimum distance = " << result << endl;

    return 0;
}
