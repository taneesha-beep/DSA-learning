/*You want to buy food from a store. You have a scoring system that uses a unit called taste points.
Each time you buy a type of food, you can measure its tastiness by the number of taste points you get from that food.
You have N types of food. You can buy any type any number of times, as long as the total number of meals does not exceed M.

However, you don't want to grow tired of a food if you buy it too often. Therefore, you will get v[i] − d[i] × (ti − 1) taste points when you buy the i-th
type of food for the ti-th time.
Find the maximum number of taste points you can achieve.

Input Format
The first line contains an integer, n, denoting the number of types of food you can buy.
The next line contains an integer, m, denoting the maximum number of meals you can buy.
Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer describing v[i].
Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer describing d[i].

Constraints
1 <= n <= 10^5
1 <= m <= 10^9
1 <= v[i] <= 10^9
1 <= d[i] <= 10^9 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n; // number of types of food you can buy
    cout << "enter number of types of food: \n";
    cin >> n;

    cout << "enter how many times you are allowed to eat: \n";
    int m; // how many times you are allowed to eat
    cin >> m;

    vector<int> v(n); // initial taste point
    vector<int> d(n); // reduction in taste points every time a food is repeated

    cout << "enter initial taste points values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "enter depreciation in taste points after every buy: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    // my original approach
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            ans.push_back(v[i] - d[i] * (j - 1));
        }
    }

    sort(ans.begin(), ans.end(), greater<int>());
    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        sum += ans[i];
    }

    cout << "answer from my approach:\n"
         << sum << endl;

    // expected optimal approach (using priority queue and heap)
    // why do we need optimal?
    // we need it because in some cases values for n and m can be TOOOO huge which would take more time and space to compute values.
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; i++)
        pq.push({v[i], i}); // pq will arrange values such that max value at each time is always at top

    long long total = 0; // for storing final answer

    while (m-- && !pq.empty())
    { // loop for m times till pq is empty

        auto top = pq.top();
        pq.pop();

        int value = top.first; // first value from pair pq
        int idx = top.second;  // second value from pair pq
        total += value;
        int next = value - d[idx]; // food becomes less tasty
        pq.push({next, idx});      // repeat
    }
    cout << "answer from optimal approach:\n"
         << total << endl;
}