#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    // INPUT
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;

    // edge case
    if (k == 0)
        cout << m * n << endl;

    int min_r = m, min_c = n;

    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        min_r = min(min_r, r);
        min_c = min(min_c, c);
    }

    cout << (min_r * min_c) << endl;

    return 0;
}
