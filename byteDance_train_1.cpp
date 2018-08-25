#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
struct Point
{
    int x;
    int y;
    Point()
    {
        x = 0;
        y = 0;
    }
    friend bool operator<(const Point &a, const Point &b)
    {
        return a.x < b.x;
    }
    friend bool operator==(const Point &a, const Point &b)
    {
        return a.x == b.x && a.y == b.y;
    }
    friend ostream &operator<<(ostream &out, const Point &a)
    {
        out << a.x << " " << a.y;
        return out;
    }
};
int main(int argc, char const *argv[])
{
    ifstream cin("byteDance_train_1.in", ios::in);
    if (!cin)
    {
        cout << "Fail to open the file";
        exit(-1);
    }
    int N = 0;
    cin >> N;
    priority_queue<Point> points;
    Point in;
    Point maxY;
    for (int i = 0; i < N; ++i)
    {
        cin >> in.x >> in.y;
        points.push(in);
        if (maxY.y < in.y)
        {
            maxY = in;
        }
        else if (maxY.y == in.y)
        {
            if (maxY.x > in.x)
            {
                maxY = in;
            }
        }
    }
    stack<Point> res;
    Point out;
    int curMax_y = 0;
    while (!points.empty())
    {
        out = points.top();
        if (curMax_y <= out.y)
        {
            res.push(out);
            curMax_y = out.y;
        }
        points.pop();
        if (out == maxY)
            break;
    }
    while (!res.empty())
    {
        cout << res.top() << endl;
        res.pop();
    }
    return 0;
}
