#include <iostream>
using namespace std;

bool checkPalindrome(string s)
{

    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {

        // Skip non-alphanumeric characters from left
        if (!isalnum(s[left]))
        {
            left++;
            continue;
        }

        // Skip non-alphanumeric characters from right
        if (!isalnum(s[right]))
        {
            right--;
            continue;
        }

        // Compare characters (case insensitive)
        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
