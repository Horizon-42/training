#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int m = 0;
    cin >> m;
    int ask = 0;
    while (m != 0)
    {
        cin >> ask;
        for (int i = 0; i < n; ++i)
        {
            ask -= a[i];
            if (ask < 0)
            {
                cout << i + 1 << endl;
                break;
            }
        }
        m--;
    }
    return 0;
}
