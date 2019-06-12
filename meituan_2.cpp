#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k, t;
    cin >> n >> k >> t;
    int *a = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int res = 0;
    map<int, int> count;
    int max_index = 0;
    for (size_t i = 0; i < k; i++)
    {
        if (count.find(a[i]) == count.end())
        {
            count.insert(make_pair(a[i], 1));
        }
        else
        {
            count[a[i]] += 1;
        }
        if (count[a[i]] > count[a[max_index]])
            max_index = i;
    }
    if (count[a[max_index]] >= t)
        res++;
    for (int i = k; i < n; ++i)
    {
        count[a[i - k]] -= 1;
        if (max_index == i - k)
            max_index = i - k + 1;

        if (count.find(a[i]) == count.end())
        {
            count.insert(make_pair(a[i], 1));
        }
        else
        {
            count[a[i]] += 1;
        }
        if (count[a[i]] > count[a[max_index]])
            max_index = i;

        if (count[a[max_index]] >= t)
            res++;
    }
    std::cout << res;
    // delete[] zone;
    delete[] a;
    return 0;
}
