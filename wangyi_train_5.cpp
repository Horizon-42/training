#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b)
{
    if (a > b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}
int main(int argc, char const *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;
    swap(a, b);
    swap(a, c);
    swap(b, c);
    if (a == 1)
        cout << (a + b) * c;
    else
        cout << a * b * c;
    return 0;
}
