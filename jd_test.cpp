#include <iostream>
#include <vector>
using namespace std;
struct thing
{
    int a;
    int b;
    int c;

  public:
    bool operator<(const thing &t)
    {
        return this->a < t.a && this->b < t.b && this->c < t.c;
    }
};
int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<thing> ts(n);

    for (size_t i = 0; i < n; i++)
    {
        thing t;
        cin >> t.a;
        cin >> t.b;
        cin >> t.c;
        ts[i] = t;
    }
    int res = 0;
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (ts[i] < ts[j])
            {
                res++;
                break;
            }
        }
    }

    cout << res;
    return 0;
}
