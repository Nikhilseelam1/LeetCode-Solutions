#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll base=31;
    ll mod=1e9+7;
    vector<ll>pre;
    vector<ll>power;
    ll hash(int l,int r){

        if(l==0)
            return pre[r];

        return (pre[r]-pre[l-1]*power[r-l+1]%mod+mod)%mod;
    }

    int rec(int l,int r){
        if(l==r) return 1;
        if(l>r) return 0;
        for(int i=1;l+i-1<r;i++){
            if(hash(l,l+i-1) ==  hash(r-i+1,r)){
                return 2 + rec(l+i,r-i);
            }
        }
        return 1;
    }
    int longestDecomposition(string text) {
        int n=text.size();
        pre.resize(n);
        power.resize(n+1);
        power[0]=1;
        for(int i=1;i<=n;i++){
            power[i]=power[i-1]*base%mod;
        }
        pre[0]=text[0]-'a'+1;

        for(int i=1;i<n;i++){

            pre[i]=(pre[i-1]*base + (text[i]-'a'+1))%mod;
        }

        for(ll it:pre) cout<<it<<" ";
        return rec(0,n-1);
    }
};