#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(const vector<int> &arr)
    {
        unordered_map<int, int> freq; // unordered map stores "key : value: pairs, here it is storing "element : frequency" pairs.

        for (int x : arr) // equivalent to "for (int i = 0; i < arr.size(); i++) { int x = arr[i]; }"
        {
            freq[x]++;
        }

        unordered_set<int> seen; // unordered set only stores keys, here it is used for traversing freq array and finding unique values.

        // Check if frequencies are unique
        for (auto &p : freq) // "auto" automatically detects data type.
        {
            int count = p.second; // p.first is the key and p.second is the value. (second part of key:value pair)
            // in count we are storing frequencies
            if (seen.count(count))
            {
                return false; // duplicate frequency found
            }

            seen.insert(count); // here we are trying to maintain a list of unique frequencies
        }

        return true;
    }
};

int main()
{
    Solution obj;

    // Test case 1
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    cout << "Test Case 1 Result: " << obj.uniqueOccurrences(arr1) << endl;
    // Expected output: 1 (true)

    // Test case 2
    vector<int> arr2 = {1, 2};
    cout << "Test Case 2 Result: " << obj.uniqueOccurrences(arr2) << endl;
    // Expected output: 0 (false)

    // Test case 3
    vector<int> arr3 = {3, 3, 3, 3};
    cout << "Test Case 3 Result: " << obj.uniqueOccurrences(arr3) << endl;
    // Expected output: 1 (true)

    return 0;
}
