#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<int> nums(n, 0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    return 0;
}
