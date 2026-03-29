#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    // INPUT
    cout << "rows?\n";
    int n;
    cin >> n;
    cout << "columns?\n";
    int m;
    cin >> m;
    cout << "initialising with zeroes...\n";
    vector<vector<int>> a(m, vector<int>(n, 0));

    cout << "enter how many operations:\n";
    int k;
    cin >> k;
    cout << "enter coordinates for each operation:\n";
    vector<vector<int>> ops(k, vector<int>(2));
    for (int i = 0; i < k; i++)
    {
        cin >> ops[i][0] >> ops[i][1];
    }

    // MAIN LOGIC
    // CODE TO INCREMENT VALUES
    for (int g = 0; g < k; g++)
    {
        int row = ops[g][0];
        int col = ops[g][1];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                a[i][j] = a[i][j] + 1;
            }
        }
    }

    // CODE TO FIND MAXIMUM ELEMENTS
    int maximum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            maximum = max(maximum, a[i][j]);
        }
    }

    // CODE TO MAINTAIN COUNT
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == maximum)
                count++;
        }
    }
    cout << "count of max elements is: \n"
         << count << endl;
    return 0;
}