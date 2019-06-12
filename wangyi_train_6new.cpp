#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
struct Tower
{
    int pos;
    int height;

  public:
    Tower(int p, int h)
    {
        pos = p;
        height = h;
    }
};

bool cmp(const Tower &a, const Tower &b)
{
    return a.height < b.height;
}

int main(int argc, char const *argv[])
{
    list<Tower> towers;
    vector<pair<int, int>> XY;
    int n = 0, k = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int height = 0;
        cin >> height;
        towers.emplace_back(i, height); //copy
    }
    towers.sort(cmp);
    int m = 0;
    list<Tower>::iterator lowest = towers.begin();
    list<Tower>::iterator highest = towers.end();
    while (k > 0)
    {
        k--;
        list<Tower>::iterator lowest = towers.begin();
        list<Tower>::iterator highest = towers.end();
        highest--;
        if (lowest->height == highest->height)
        {
            break;
        }
        highest->height--;
        lowest->height++;

        XY.push_back(make_pair(highest->pos, lowest->pos));
        m++;

        auto higer = towers.begin();
        higer++;
        bool isHigher = false;
        while (lowest->height > higer->height && higer != towers.end())
        {
            isHigher = true;
            higer++;
        }
        if (isHigher)
        {
            towers.emplace(higer, lowest->pos, lowest->height);
            towers.pop_front();
        }
        auto lower = towers.end();
        lower--;
        lower--;
        bool isLower = false;
        while (highest->height < lower->height && lower != towers.begin())
        {
            isLower = true;
            --lower;
        }
        if (isLower)
        {
            lower++;
            towers.emplace(lower, highest->pos, highest->height);
            towers.pop_back();
        }
    }
    cout << towers.back().height - towers.front().height << " " << m << endl;
    for (auto xy : XY)
    {
        cout << xy.first << " " << xy.second << endl;
    }
    return 0;
}
