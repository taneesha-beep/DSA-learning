#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
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
    vector<int> a = {1, 0, 0, 9, 5};
    moveZeroes(a);
    print(a, 5);
    return 0;
}