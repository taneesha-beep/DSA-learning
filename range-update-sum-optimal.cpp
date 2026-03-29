#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    // to prevent overflow when encountering large values
    const long long MOD = 1e9 + 7;

    // INPUT
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;

    vector<vector<int>> queries(m, vector<int>(3));
    for (int i = 0; i < m; i++)
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];

    long long ans = 0;

    // now build prefix array
    vector<long long> prefix(n);
    prefix[0] = a[0] % MOD;
    for (int i = 0; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i] % MOD;

    // process queries now
    // outer loop:
    for (int i = 0; i < m; i++)
    {
        int type = queries[i][0];
        int l = queries[i][1] - 1; // convert to 0-based indexing
        int r = queries[i][2] - 1;

        // type 1 optimised logic
        if (type == 1)
        {
            long long k = 1;
            for (int j = l; j <= r; j++)
            {
                a[j] = a[j] * k % MOD;
                k++;
            }

            // rebuild prefix (imp)
            prefix[0] = a[0] % MOD;
            for (int i = 0; i < n; i++)
                prefix[i] = prefix[i - 1] + a[i] % MOD;
        }

        // type 2 optimised logic
        else if (type == 2)
        {
            long long sum = prefix[r];
            if (l > 0)
                sum = (sum - prefix[l - 1] + MOD) % MOD;
            ans = (ans + sum) % MOD;
        }
    }
    cout << ans << endl;

    return 0;
}