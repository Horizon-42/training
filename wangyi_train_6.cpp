#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> a(n, 0);
    int maxI = 0;
    int minI = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > a[maxI])
            maxI = i;
        if (a[i] < a[minI])
            minI = i;
    }
    int minDis = 10001;
    int m = 0;
    vector<pair<int, int>> x_y;
    for (int i = 0; i <= k; i++)
    {
        if (a[maxI] - a[minI] == 0)
        {
            m = i;
            break;
        }
        a[maxI] -= 1;
        a[minI] += 1;
        x_y.push_back(make_pair(maxI + 1, minI + 1));
        for (int i = 0; i < n; i++)
        {
            if (a[i] > a[maxI])
                maxI = i;
            if (a[i] < a[minI])
                minI = i;
        }
    }
    cout << a[maxI] - a[minI] << " " << m << endl;
    for (auto move : x_y)
    {
        cout << move.first << " " << move.second << endl;
    }
    return 0;
}
