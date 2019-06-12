#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[1001][1001] = {0};
    for (int i = 0; i < 1001; ++i)
    {
        for (size_t j = 0; j < 1001; j++)
        {
            cout << a[i][j] << endl;
        }
    }
    return 0;
}
