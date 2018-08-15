#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n=0, m=0;
    cin>>n>>m;
    vector<int> bottom(n,0);
    int cube=0;
    for(int i=0; i<m;++i){
        cin>>cube; 
        bottom[cube-1]++;
    }
    int socre = m;
    for(int x:bottom){
        if(socre>x)
            socre=x;
    }
    cout<<socre;
    cin.clear();
    cin.ignore(1024,'\n');
    cin.sync();
    getchar();
    return 0;
}
