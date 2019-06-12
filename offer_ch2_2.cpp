#include <iostream>

using namespace std;
int getSize(int data[])
{
    return sizeof(data);
}
int main(int argc, char const *argv[])
{
    int data1[] = {1, 2, 3, 4, 5};
    cout << sizeof(data1) << endl;
    int *data2 = data1;
    cout << sizeof(data2) << endl;
    cout << getSize(data1) << endl;
    return 0;
}
