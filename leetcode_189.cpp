#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    vector<int> temp(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % nums.size()] = nums[i];
    }
    nums = temp;
}

void print(vector<int> &arr3, int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << arr3[i] << " ";
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    rotate(arr, 3);
    print(arr, 6);
    return 0;
}