#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    // INPUT
    int n;
    cout << "enter size of array:\n";
    cin >> n;

    vector<int> a(n);
    cout << "enter elements of array:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cout << "how many number of queries?\n";
    cin >> m;

    // using 2d array for inputing size 3 queries for m times
    vector<vector<int>> queries(m, vector<int>(3));
    cout << "enter queries:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> queries[i][j];
        }
    }

    long long ans = 0;
    vector<int> original = a;
    for (int i = 0; i < m; i++)
    {
        vector<int> q = queries[i];

        // TYPE 1 QUERY
        if (q[0] == 1)
        {
            int l = q[1] - 1;
            int r = q[2] - 1;

            int k = 1;
            for (int i = l; i <= r; i++)
            {
                a[i] = a[i] * k;
                k++;
            }
        }

        // TYPE 2 QUERY
        if (q[0] == 2)
        {
            int l = q[1] - 1, r = q[2] - 1;
            long long sum = 0;

            for (int i = l; i <= r; i++)
            {
                sum += a[i];
            }

            ans += sum;
        }
    }
    cout << "summation of answers of type 2 queries: " << ans << endl;

    return 0;
}