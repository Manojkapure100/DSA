#include<iostream>

using namespace std;

int recursion(string s1, string s2, int i)
{
    if (i == s1.size())
    {
        return -1;
    }
    if (s1.substr(i, s2.size()) == s2)
    {
        return i;
    }
    else
    {
        return recursion(s1, s2, i + 1);
    }
}

int simple(string s1, string s2)
{
    int s1Size = s1.size();
    int s2Size = s2.size();

    for (int i = 0; i <= s1Size - s2Size; i++)
    {
        if (s1.substr(i, s2Size) == s2)
        {
            return i;
        }
    }
    return -1;
}

int strStr(string s1, string s2)
{
    int ans;
    // ans = recursion(s1,s2,0);
    ans = simple(s1, s2);
    return ans;
}

int main(){
    string s1 = "abcdleetcode";
    string s2 = "leetcode";
    cout << strStr(s1,s2) << endl;
    return 0;
}