class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int>list;
        int n1=n;
        while(n>0){
            list.push_back(n%10);
            n/=10;
        }
        reverse(list.begin(),list.end());
        int m=list.size();
        long long res=0;
        int index=m;
        for(int i=m-1;i>0;i--){
            if(list[i-1]>list[i]){
                list[i-1]--;
                index=i;
            }
        }
        for(int i=index;i<m;i++){
            list[i]=9;
        }
        for(int i=0;i<list.size();i++){
            res=res*1ll*10+list[i];
        }
        return res;
    }
};