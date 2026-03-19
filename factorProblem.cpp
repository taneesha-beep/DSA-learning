/* You are given a positive integer X,
Your task is to tell whether there exist two positive integers  a and b, a > 0, b > 0
such that  2⋅a + 2⋅b + a⋅b = X
If there exist positive integers a and b satisfying the above condition print YES, otherwise print NO.*/

#include <iostream>
using namespace std;

int main()
{
    // your code goes here

    int x;
    cin >> x;
    bool found = false;
    int n = x + 4;
    for (int i = 3; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int a = n / i;
            if (a >= 3)
                found = true;
        }
    }
    if (found)
        cout << "yes\n";
    else
        cout << "no\n";
}
