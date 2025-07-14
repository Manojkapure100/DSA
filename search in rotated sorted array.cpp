#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &n, int t)
{
    int s = 0;
    int e = n.size() - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (n[m] == t)
            return m;

        if (n[s] <= n[m])
        {
            if (n[s] <= t && t <= n[m])
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        else
        {
            if (n[m] <= t && t <= n[e])
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {7,8,9,1,2,3,4,5,6};
    int target = 4;
    int result = search(arr,target);
    cout << "result: " << result << endl;
    return 0;
}