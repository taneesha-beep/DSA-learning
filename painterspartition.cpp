#include <bits/stdc++.h>
using namespace std;

/*
    Checks if it is possible to paint all boards such that
    no painter paints more than 'mid' units of work.
*/
bool isPossible(vector<int> &boards, int k, int mid)
{
    int painterCount = 1; // Start with first painter
    int currSum = 0;      // Work assigned to current painter

    for (int i = 0; i < boards.size(); i++)
    {
        // If current board can be painted by current painter
        if (currSum + boards[i] <= mid)
        {
            currSum += boards[i];
        }
        else
        {
            // Assign board to next painter
            painterCount++;

            // If painters exceed limit or single board > mid
            if (painterCount > k || boards[i] > mid)
            {
                return false;
            }

            currSum = boards[i];
        }
    }
    return true;
}

/*
    Finds the minimum possible time to paint all boards
    using k painters.
*/
int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();

    // Edge case: more painters than boards
    if (k > n)
        return -1;

    int s = 0; // Start of search space
    int e = 0; // End of search space

    // Calculate search space
    for (int i = 0; i < n; i++)
    {
        s = max(s, boards[i]); // Minimum time
        e += boards[i];        // Maximum time
    }

    int ans = -1;

    // Binary search on answer
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (isPossible(boards, k, mid))
        {
            ans = mid;   // Store valid answer
            e = mid - 1; // Try to minimize
        }
        else
        {
            s = mid + 1; // Increase time
        }
    }

    return ans;
}

int main()
{
    int n, k;
    cout << "Enter number of boards: ";
    cin >> n;

    vector<int> boards(n);
    cout << "Enter length of each board:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> boards[i];
    }

    cout << "Enter number of painters: ";
    cin >> k;

    int result = findLargestMinDistance(boards, k);

    if (result == -1)
        cout << "Painting not possible\n";
    else
        cout << "Minimum time to paint all boards = " << result << endl;

    return 0;
}
