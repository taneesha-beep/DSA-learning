#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;

    int row = matrix.size();
    int col = matrix[0].size();

    int SR = 0, SC = 0;
    int ER = row - 1, EC = col - 1;

    while (SR <= ER && SC <= EC)
    {

        //  left → right
        for (int i = SC; i <= EC; i++)
        {
            ans.push_back(matrix[SR][i]);
        }
        SR++;

        //  top → bottom
        for (int i = SR; i <= ER; i++)
        {
            ans.push_back(matrix[i][EC]);
        }
        EC--;

        //  right → left
        if (SR <= ER)
        {
            for (int i = EC; i >= SC; i--)
            {
                ans.push_back(matrix[ER][i]);
            }
            ER--;
        }

        // bottom → top
        if (SC <= EC)
        {
            for (int i = ER; i >= SR; i--)
            {
                ans.push_back(matrix[i][SC]);
            }
            SC++;
        }
    }

    return ans;
}

int main()
{

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Order: ";
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}