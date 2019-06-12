#include <iostream>
#include <vector>
using namespace std;
typedef vector<bool> fuck;
int T = 0, N = 0, M = 0;
vector<fuck> mat;

bool solve(vector<int> all)
{
    if (all.size() == 1)
        return false;
    vector<int> youlianjie;

    for (size_t i = 0; i < all.size() - 1; i++)
    {
        bool you = true;
        for (size_t j = i + 1; j < all.size(); j++)
        {
            if (!mat[i][j])
            {
                you = false;
                break;
            }
        }
        if (you)
        {
            youlianjie.push_back(all[i]);
        }
    }
    if (youlianjie.empty())
        return false;
    else if (youlianjie.size() == all.size() - 1)
        return false;
    else
    {
        return solve(youlianjie);
    }
}

int main(int argc, char const *argv[])
{
    cin >> T;

    while (T > 0)
    {
        T--;
        cin >> N >> M;
        mat.resize(N);
        vector<int> all;
        for (size_t i = 0; i < N; i++)
        {
            all.push_back(i);
            mat[i].resize(N, false);
        }

        for (size_t i = 0; i < M; i++)
        {
            int a = 0, b = 0;
            cin >> a >> b;
            mat[a - 1][b - 1] = true;
            mat[b - 1][a - 1] = true;
        }
        bool res = solve(all);
        if (res)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
