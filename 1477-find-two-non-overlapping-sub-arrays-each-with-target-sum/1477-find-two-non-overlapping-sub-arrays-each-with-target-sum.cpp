class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>pre(n+1,0),suff(n+1,0);
        int sum=0;
        int j=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            while(sum>target){
                sum-=arr[j];
                j++;
            }
            if (sum == target)
            {
                int len = i - j + 1;

                if (pre[i] == 0)
                    pre[i+1] = len;
                else
                    pre[i+1] = min(pre[i], len);
            }
            else {
                pre[i+1] = pre[i];
            }
        }
        sum=0;
        j=n-1;
        for(int i=n-1;i>=0;i--){
            sum+=arr[i];
            while(sum>target){
                sum-=arr[j];
                j--;
            }
            if(sum==target){
                int len=j-i+1;
                if(suff[i+1]==0){
                    suff[i]=len;
                }else{
                    suff[i]=min(suff[i+1],len);
                }
            }else{
                suff[i]=suff[i+1];
            }
        }
        for(int it:pre) cout<<it<<" ";
        cout<<endl;
        for(int it:suff) cout<<it<<" ";
        int mini=1e9;
        for(int i=0;i<n;i++){
            int x=pre[i];
            int y=suff[i];
            if(x>0 && y>0 ) mini=min(mini,x+y);
        }
        return mini==1e9?-1:mini;
    }
};