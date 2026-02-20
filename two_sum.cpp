#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans; // return immediately once found
                }
            }
        }
        return ans;
    }
};

int main()
{
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    vector<int> result = obj.twoSum(nums, target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    }
    else
    {
        cout << "No two numbers found." << endl;
    }

    return 0;
}