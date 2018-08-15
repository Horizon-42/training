#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k=0;
    cin>>n>>k;
    vector<int> intersts(n,0);
    vector<int> sleepy(n,0);
    for(int i=0;i<n;++i){
        cin>>intersts[i];
    }
    for(int i=0;i<n;++i){
        cin>>sleepy[i];
    }
    return 0;
}
