#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<bool>> arc;
vector<int> color;

void init();
void GraphColor(int m);
bool OK(int k);

int main(int argc, char const *argv[])
{
    init();
    int m;
    cout << "Please input the num of colors" << endl;
    cin >> m;
    GraphColor(m);
    return 0;
}

void init()
{
    cin >> n;
    arc.resize(n);

    for (size_t i = 0; i < n; i++)
    {
        arc[i].resize(n, false);
    }
    cout << "Please input edge num:" << endl;
    int e;
    cin >> e;

    for (size_t i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        arc[a][b] = true;
        arc[b][a] = true;
    }
}
void GraphColor(int m)
{
    color.resize(n, 0);
    int k = 0;

    // 注意此处边界
    while (k >= 0)
    {
        // 尝试新的色号 色号从1开始 到m
        color[k] += 1;
        while (color[k] <= m)
        {
            if (OK(k))
                break;
            else
                color[k] += 1;
        }
        if (color[k] <= m && k == n - 1)
        {

            for (size_t i = 0; i < n; i++)
            {
                cout << color[i] << "\t";
            }
            cout << endl;
            return;
        }
        if (color[k] <= m && k < n - 1)
            k++;
        else
            color[k--] = 0; //回溯
    }
}

bool OK(int k)
{
    // 只用判断已经着色的点
    for (size_t i = 0; i < k; i++)
    {
        if (arc[k][i] && color[k] == color[i])
            return false;
    }
    return true;
}
