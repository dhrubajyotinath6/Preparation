#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    vector<pair<int,int>> x;
    for(int i=0;i<n;++i)
    {
        
        for(int i=0;i<3;++i)
        {
            int a,b;
            cin>>a>>b;
            x.push_back(make_pair(a,b));
        }
        sort(x.begin(),x.end());
        if(x[0].first==x[1].first==x[2].first or x[0].second==x[1].second==x[2].second) continue;
        else{
            if(x[0].first==x[1].first or x[1].first==x[2].first){
                for(int i=0;i<3;++i)
                {
                    v.push_back(x[i]);
                }
            }
            else if(x[0].second==x[1].second or x[1].second==x[2].second){
                 for(int i=0;i<3;++i)
                {
                    v.push_back(x[i]);
                }
            }
        }
        x.clear();
    }
    for(int i=0;i<v.size();++i)
    {
            cout<<v[i].first<<" "<<v[i].second;
            cout<<"\n";
    }
    
    return 0;
}