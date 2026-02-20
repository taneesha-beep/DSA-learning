// check if array is sorted and rotated
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int c = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                c++;
            }
        }

        if (nums[nums.size() - 1] > nums[0])
        {
            c++;
        }

        return c <= 1;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {3, 4, 5, 1, 2}; // You can change this input

    if (sol.check(nums))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
