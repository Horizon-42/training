#include <iostream>
using namespace std;
class Solution
{
  public:
    void replaceSpaceForward(char *str, int length)
    {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
                count++;
        }
        char *newStr = new char[length + 2 * count];
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
            {
                newStr[j++] = '%';
                newStr[j++] = '2';
                newStr[j++] = '0';
            }
            else
            {
                newStr[j++] = str[i];
            }
        }
        // delete[] str;
        // delete old;
        strcpy(str, newStr);
        delete[] newStr;
    }

    void replaceSpace(char *str, int length) // 字符串长度不计入'\0'
    {
        if (str == nullptr || length <= 0)
            return;
        int count = 0;
        int oldStrLength = 0;
        int i = 0;
        while (str[i] != '\0')
        {
            ++oldStrLength;
            if (str[i] == ' ')
                ++count;
            ++i;
        }
        int newStrLength = oldStrLength + 2 * count;
        if (newStrLength > length)
            return;
        while (oldStrLength >= 0 && newStrLength > oldStrLength)
        {
            if (str[oldStrLength] == ' ')
            {
                str[newStrLength--] = '0';
                str[newStrLength--] = '2';
                str[newStrLength--] = '%';
            }
            else
            {
                str[newStrLength--] = str[oldStrLength];
            }
            oldStrLength--;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    char *str = new char[30];
    strcpy(str, " ");
    s.replaceSpace(str, 30);
    cout << str << endl;
    return 0;
}
