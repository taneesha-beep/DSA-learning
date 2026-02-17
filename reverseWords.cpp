#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverseWords(string &s)
{
    int n = s.size();

    reverse(s.begin(), s.end());

    int start = 0;
    int end = 0;

    while (end < n)
    {
        if (s[end] == ' ')
        {
            end++;
            start = end;
            continue;
        }

        while (end < n && s[end] != ' ')
        {
            end++;
        }

        reverse(s.begin() + start, s.begin() + end);

        start = end;
    }
}

int main()
{
    string s;
    getline(cin, s);

    reverseWords(s);

    cout << "Reversed words string: " << s;

    return 0;
}
