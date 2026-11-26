class Solution {
public:
    const long long mod=1337;
    long long powerr(long long a,long long b){
        long long res=1;
        b%=mod;
        while(b>0){
            if(b & 1) res=(res*a)%mod;
            a=(a*a)%mod;
            b=b>>1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b){
        long long res=1;
        for(int it:b){
            res=(powerr(res,10)%mod * powerr(a,it)%mod)%mod;
        }
        return res;
    }
};