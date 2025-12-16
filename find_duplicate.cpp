#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findDuplicateIndexMarking(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int index = abs(arr[i]); // get original value

        // If already negative → visited → duplicate
        if (arr[index] < 0)
        {
            return index;
        }

        // Mark as visited by negating
        arr[index] = -arr[index];
    }
    return -1; // if no duplicate (shouldn't happen in valid input)
}

int findDuplicateXOR(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }
    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 4, 2, 2};
    int duplicate2 = findDuplicateXOR(arr);
    int duplicate1 = findDuplicateIndexMarking(arr);
    cout << "Duplicate (XOR): " << duplicate2 << endl;
    cout << "Duplicate (Index Marking): " << duplicate1 << endl;
    return 0;
}
