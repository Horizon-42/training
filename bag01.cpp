#include <iostream>
#include <vector>

using namespace std;

int num = 0;
int W = 0;
int V = 0; // 最大价值
vector<int> w, v, res;

// 回溯法 深度优先搜索
// @param i 当前处理下标
// @param weigth 当前总重量
// @param value 当前总价值
// @param path 路径记录
void dfs(int i, int weight, int value, vector<int> &path);

int main(int argc, char const *argv[])
{
    num = 0;
    cin >> num;
    cin >> W;
    w.resize(num);
    v.resize(num);
    for (size_t i = 0; i < num; i++)
    {
        cin >> w[i] >> v[i];
    }

    vector<int> path;
    dfs(0, 0, 0, path);

    cout << "Max Value: " << V << endl
         << "Result: " << endl;
    for (int i : res)
    {
        cout << "Weight: " << w[i] << " Value: " << v[i] << endl;
    }

    return 0;
}

void dfs(int i, int weight, int value, vector<int> &path)
{
    if (i < num)
    {
        if (weight + w[i] <= W)
        {
            path.push_back(i);
            weight += w[i];
            value += v[i];
            dfs(i + 1, weight, value, path);
            path.pop_back();
            weight -= w[i];
            value -= v[i];
            dfs(i + 1, weight, value, path);
        }
        else
        {
            if (V < value)
            {
                V = value;
                res = path;
            }
            return;
        }
    }
    else
        return;
}
