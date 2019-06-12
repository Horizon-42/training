#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct work
{
    int index;
    int time;
    work(int i, int t) : index(i), time(t) {}
    work()
    {
        index = 0;
        time = 0;
    }
};

bool cmp(work &a, work &b)
{
    return a.time > b.time;
}

int main(int argc, char const *argv[])
{
    vector<work> t;
    vector<int> d;
    int n, m;
    cin >> n >> m;
    t.resize(n);
    d.resize(m, 0);

    for (size_t i = 0; i < n; i++)
    {
        cin >> t[i].time;
        t[i].index = i;
    }

    sort(t.begin(), t.end(), cmp);
    vector<vector<int>> s(m);

    for (size_t i = 0; i < m; i++)
    {
        s[i].push_back(t[i].index);
        d[i] = t[i].time;
    }
    // 若m>=n,此处不会运行
    for (size_t i = m; i < n; i++)
    {
        int j = 0;
        for (size_t k = 1; k < m; k++)
        {
            if (d[j] > d[k])
                j = k;
        }
        s[j].push_back(t[i].index);
        d[j] += t[i].time;
    }

    for (size_t i = 0; i < m; i++)
    {

        for (auto x : s[i])
        {
            cout << x + 1 << "\t";
        }
        cout << endl;
    }

    return 0;
}
