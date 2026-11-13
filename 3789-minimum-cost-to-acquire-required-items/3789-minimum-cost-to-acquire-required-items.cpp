class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a1=cost1*1ll*need1 + cost2*1ll*need2;
        long long a2=costBoth*1ll*max(need1,need2);
        long long ans=1e18,ans2=1e18;
        if(need1>need2){
            ans2=(need1-need2)*1ll*cost1;
            ans2+=need2*1ll*costBoth;
        }else{
            ans=(need2-need1)*1ll*cost2;
            ans+=need1*1ll*costBoth;
        }
    //    cout<<a1<<" "<<a2<<" "<<ans<<" "<<ans2; 
        long long ans3=min({a1,a2,ans,ans2});
        return ans3;
    }
};