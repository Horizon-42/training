#include <iostream>

using namespace std;

int duplicate(const int a[], int len)
{
    int l = 1;
    int r = len - 1;
    int m = 0;
    while (l < r)
    {
        m = (l + r) / 2;
        int lsum = 0, rsum = 0;
        for (int i = 0; i < len; ++i)
        {
            if (a[i] >= l && a[i] <= m)
                lsum++;
            else if (a[i] >= m + 1 && a[i] <= r)
                rsum++;
        }
        if (lsum > m - l + 1)
            r = m;
        else if (rsum > r - m)
            l = m + 1;
    }
    return l;
}

int main(int argc, char const *argv[])
{
    int a[] = {2, 3, 2, 4, 3, 2, 6, 7};
    cout << duplicate(a, sizeof(a) / sizeof(int)) << endl;
    return 0;
}