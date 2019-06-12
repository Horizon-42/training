#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    bool **pass = new bool *[N]();
    for (int i = 0; i < N; ++i)
    {
        pass[i] = new bool[N]();
    }

    for (size_t i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        pass[x][y] = true;
        pass[y][x] = true;
    }
    bool *passed = new bool[N]();
    queue<int> go;
    go.push(0);
    passed[0] = true;

    while (!go.empty())
    {
        int now = go.front();
        go.pop();

        for (size_t i = 0; i < N; i++)
        {
            /* code */
        }
    }

    delete[] passed;
    for (int i = 0; i < N; ++i)
    {
        delete[] pass[i];
    }
    delete[] pass;
    return 0;
}
