class Solution {
public:
    int mod=1e9+7;
    int countHousePlacements(int n) {
        long long a=2;
        long long b=3;
        long long c=5;
        if(n==1) return 4;
        if(n==2) return 9;
        if(n==3) return 25;
        for(int i=0;i<n-3;i++){
            a=b%mod;
            b=c%mod;
            c=a%mod + b%mod;
        }
        return (c%mod * c%mod)%mod;
    }
};