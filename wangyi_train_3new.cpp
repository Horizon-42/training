#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    int total=0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        total+=a[i];
        a[i]=total;
    }
    int m = 0;
    cin >> m;
    int ask = 0;
    while (m != 0)
    {
        cin >> ask;
        int l=0, r=n-1;
        int mid=0;
        while(l<r)
        {
            mid=(l+r)/2;
            if(a[mid]==ask)
            {
                break;
            }
            else if(ask>a[mid])
            {
                l=mid+1;
            }
            else if(ask<a[mid])
            {
                r=mid-1;
            }
        }
        while(a[l]<ask)
            l++;
        cout<<l+1<<endl;
        m--;
    }
    return 0;
}
