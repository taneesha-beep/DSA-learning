#include <iostream>
using namespace std;

void printrowsum(int a[][3], int row, int col)
{
    cout << "row wise sum:\n";
    for (row = 0; row < 3; row++)
    {
        int sum = 0;
        for (col = 0; col < 3; col++)
        {
            sum = sum + a[row][col];
        }
        cout << sum;
        cout << endl;
    }
}

void printcolsum(int a[][3], int row, int col)
{
    cout << "col wise sum:\n";
    for (row = 0; row < 3; row++)
    {
        int sum = 0;
        for (col = 0; col < 3; col++)
        {
            sum = sum + a[col][row];
        }
        cout << sum;
        cout << endl;
    }
}

int main()
{
    int a[3][3];
    cout << "enter elements\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "matrix:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    printrowsum(a, 3, 3);
    printcolsum(a, 3, 3);
}