#include <iostream>

using namespace std;
int sovle(int a[], int len)
{
    int m = 0;
    for (int i = 0; i < len; ++i)
    {
        // //此处实现有误， 只交换一次并不能保证每个数字都在正确的位置
        // m = a[i];
        // if (m == i)
        //     continue;
        // else if (a[i] == a[m])
        // {
        //     return a[i];
        // }
        // else
        // {
        //     a[i] ^= a[m];
        //     a[m] ^= a[i];
        //     a[i] ^= a[m];
        // }
        while (a[i] != i)
        {
            m = a[i];
            if (a[i] == a[m])
                return a[i];
            else
            {
                a[i] ^= a[m];
                a[m] ^= a[i];
                a[i] ^= a[m];
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    int a[] = {2, 3, 1, 0, 2, 5, 3};
    cout << sovle(a, sizeof(a) / sizeof(int)) << endl;
    return 0;
}

class Solution
{
  public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication)
    {
        int m = 0;
        for (int i = 0; i < length; ++i)
        {
            while (numbers[i] != i)
            {
                m = numbers[i];
                if (numbers[i] == numbers[m])
                {
                    *duplication = numbers[i];
                    return true;
                }
                else
                {
                    numbers[i] ^= numbers[m];
                    numbers[m] ^= numbers[i];
                    numbers[i] ^= numbers[m];
                }
            }
        }
    }
};