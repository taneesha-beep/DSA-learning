#include <iostream>
using namespace std;

/*
    This function checks whether it is possible to allocate books
    such that no student gets more than 'mid' pages.
*/
bool isPossible(vector<int> &arr, int n, int m, int mid)
{
    int studentCount = 1; // Start with first student
    int pageSum = 0;      // Pages allocated to current student

    for (int i = 0; i < n; i++)
    {
        // If current book can be added to current student
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            // Assign book to next student
            studentCount++;

            // If students exceed limit OR single book > mid
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }

            // Start counting pages for new student
            pageSum = arr[i];
        }
    }
    return true;
}

/*
    This function finds the minimum possible value of the
    maximum number of pages assigned to any student.
*/
int findPages(vector<int> &arr, int n, int m)
{
    // Edge case: more students than books
    if (m > n)
        return -1;

    int s = 0;   // Start of search space
    int sum = 0; // Total pages

    // Calculate total pages
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int e = sum; // End of search space
    int ans = -1;

    // Binary search on answer
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = mid;   // Store possible answer
            e = mid - 1; // Try for smaller maximum
        }
        else
        {
            s = mid + 1; // Increase limit
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cout << "Enter number of books: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter pages in each book:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter number of students: ";
    cin >> m;

    int result = findPages(arr, n, m);

    if (result == -1)
        cout << "Allocation not possible\n";
    else
        cout << "Minimum maximum pages = " << result << endl;

    return 0;
}
