#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // since elements are sorted and complexity O(log(m * n)) is mentioned,
        // use binary search. treat this 2d array as 1d array.

        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = (row * col) - 1;
        int mid = start + (end - start) / 2;

        while (start <= end)
        {
            // to access element in 2d as 1d:
            int element = matrix[mid / col][mid % col];

            // bs core logic:
            if (element == target)
                return true;
            else if (target < element)
                end = mid - 1;
            else if (target > element)
                start = mid + 1;
            mid = start + (end - start) / 2;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int target = 3;

    Solution obj;
    bool result = obj.searchMatrix(matrix, target);

    if (result)
        cout << "Target found" << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}