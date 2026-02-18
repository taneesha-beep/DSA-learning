#include <iostream>
#include <string>
using namespace std;

bool checkEqual(int count1[26], int count2[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
            return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;

    int count1[26] = {0};
    int count2[26] = {0};

    // Count frequency of s1 and first window of s2
    for (int i = 0; i < s1.size(); i++)
    {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    // Check first window
    if (checkEqual(count1, count2))
        return true;

    // Sliding window
    for (int i = s1.size(); i < s2.size(); i++)
    {
        // Add new character
        count2[s2[i] - 'a']++;

        // Remove old character
        count2[s2[i - s1.size()] - 'a']--;

        if (checkEqual(count1, count2))
            return true;
    }

    return false;
}

int main()
{
    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    if (checkInclusion(s1, s2))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
