#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end(),greater<long long> ());
        long long  ans=0;
        for (int i = 0; i < n; i++) {
            ans+=(pow(2,i)*v[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}