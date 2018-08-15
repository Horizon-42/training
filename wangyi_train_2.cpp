#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k = 0;
    cin >> n >> k;
    vector<int> intersts(n, 0);
    vector<int> sleepy(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> intersts[i];
    }
    int alreadyHave = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> sleepy[i];
        if (sleepy[i])
        {
            alreadyHave += intersts[i];
            intersts[i] = 0;
        }
    }
    int awakeToGet = 0;
    for (int i = 0; i < k; ++i)
    {
        awakeToGet += intersts[i];
    }
    int maxGet = awakeToGet;
    for (int i = k; i < n; ++i)
    {
        awakeToGet -= intersts[i - k];
        awakeToGet += intersts[i];
        if (awakeToGet > maxGet)
            maxGet = awakeToGet;
    }
    cout << maxGet + alreadyHave;
    return 0;
}
