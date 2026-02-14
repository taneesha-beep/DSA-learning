#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findArraySum(vector<int> &a, vector<int> &b)
{

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    vector<int> result;

    while (i >= 0 || j >= 0 || carry)
    {

        int sum = carry;

        if (i >= 0)
        {
            sum += a[i];
            i--;
        }

        if (j >= 0)
        {
            sum += b[j];
            j--;
        }

        result.push_back(sum % 10);
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{

    vector<int> a = {4, 5, 1}; // 451
    vector<int> b = {3, 4, 5}; // 345

    vector<int> ans = findArraySum(a, b);

    cout << "Sum: ";
    for (int digit : ans)
    {
        cout << digit << " ";
    }

    return 0;
}
