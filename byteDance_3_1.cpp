#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int i_move[4] = {-1, 0, 1, 0};
int j_move[4] = {0, -1, 0, 1};
int M = 0;
typedef pair<int, int> tpair;
vector<vector<int>> cube;
void bfs(int i, int j)
{
    queue<tpair> go;
    go.push(make_pair(i, j));

    while (!go.empty())
    {
        auto cur = go.front();
        go.pop();
        for (size_t k = 0; k < 4; k++)
        {
            auto next = make_pair(cur.first + i_move[k], cur.second + j_move[k]);
            if (next.first >= 0 && next.first < M && next.second >= 0 && next.second < M && cube[next.first][next.second] == 1)
            {
                go.push(next);
                cube[next.first][next.second] = 0;
            }
        }
    }
}
int main(int argc, char const *argv[])
{

    int sum = 0;
    cin >> M;
    cube.resize(M);
    for (size_t i = 0; i < M; i++)
    {
        cube[i].resize(M);
    }
    for (size_t i = 0; i < M; i++)
    {

        for (size_t j = 0; j < M; j++)
        {
            cin >> cube[i][j];
        }
    }

    for (size_t i = 0; i < M; i++)
    {

        for (size_t j = 0; j < M; j++)
        {
            if (cube[i][j] == 1)
            {
                bfs(i, j);
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}
