#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    bool Find(int target, vector<vector<int>> array)
    {
        int r = 0;
        int c = array[0].size() - 1;
        while (r >= 0 && r < array.size() && c >= 0 && c < array[0].size())
        {
            if (array[r][c] == target)
                return true;
            else if (target < array[r][c])
                c--;
            else
                r++;
        }
        return false;
    }
};