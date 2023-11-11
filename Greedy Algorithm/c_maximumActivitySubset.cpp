#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second!=b.second){
        return a.second<b.second;
    }
    return a.first<b.first;
}
int main(){
    
    // write your code here
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    while(n--){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
   
    sort(v.begin(),v.end(),cmp);
  
    int ans=1;
   
    int lastSecond=v[0].second;
  
    for(int i=1; i<v.size(); i++){
        if(v[i].first>=lastSecond){
            ans++;
            lastSecond=v[i].second;
        }
    }
    cout<<ans<<endl;
    return 0;
}