#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // row and column of vector matrix
        int row = matrix.size();
        int col = matrix[0].size();

        // transpose (flip across diagonal)
        for (int i = 0; i < row; i++)
        {
            for (int j = i; j < col; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse the rows (for clockwise)
        for (int i = 0; i < row; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    Solution obj;
    obj.rotate(matrix);

    for (auto &row : matrix)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}