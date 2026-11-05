
class Solution {
public:
    vector<long long>cost;
    int k1;
    int x1;
    int n;
    long long dp[16][100001];
    long long rec(int c,int i){
        if(c==k1) return 0;
        if(i>n-x1) return 1e15;
        if(dp[c][i]!=-1) return dp[c][i];
        long long res=cost[i]  + rec(c+1,i+x1);
        res=min(res,rec(c,i+1));
        return dp[c][i]=res; 
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        k1=k;
        x1=x;
        multiset<long long>left,right;
        int i=0;
        int j=0;
        long long leftsum=0;
        long long rightsum=0;
        cost.resize(n-x+1);
        while(j<n){
            if(left.size()<=right.size()){
                left.insert(nums[j]);
                leftsum+=nums[j];
            }else{
                right.insert(nums[j]);
                rightsum+=nums[j];
            }
            int left_size=left.size();
            int right_size=right.size();
            while(left_size>0 && right_size>0){
                long long leftmax=*left.rbegin();
                long long rightmin=*right.begin();
                if(leftmax>rightmin){
                    right.erase(right.begin());
                    left.erase(prev(left.end()));
                    left.insert(rightmin);
                    right.insert(leftmax);
                    leftsum-=leftmax;
                    leftsum+=rightmin;
                    rightsum+=leftmax;
                    rightsum-=rightmin;
                    left_size=left.size();
                    right_size=right.size();
                }else{
                    break;
                }
            }
            if(j-i+1 == x)
            {
                long long mid=*left.rbegin();
                int l_s=left.size();
                int r_s=right.size();
                cost[i]=(mid*l_s - leftsum) + rightsum - r_s*mid;
                if(left.find(nums[i])!=left.end()){
                    left.erase(left.find(nums[i]));
                    leftsum-=nums[i];
                }else{
                    right.erase(right.find(nums[i]));
                    rightsum-=nums[i];
                }
                i++;
            }
            j++;
        }
        // for(int it:cost) cout<<it<<" ";
        // return 1;
        return rec(0,0);
    }
};