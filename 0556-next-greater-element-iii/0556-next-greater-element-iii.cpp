class Solution {
public:
    int nextGreaterElement(int n) {
        int n1=n;
        vector<long long>list;
        while(n>0){
            list.push_back(n%10);
            n/=10;
        }
        
        bool f=false;
        reverse(list.begin(),list.end());
        int index=-1;
        n=list.size();
        for(int i=n-2;i>=0;i--){
            int j=i;
            if(j+1<n && list[j]<list[j+1]){
                index=j;
                f=true;
            }
            if(f) break;
        }
        if(index==-1) return -1;
        int index1=-1;
        f=false;
        for(int i=n-1;i>=0;i--){
            if(list[i]>list[index]){
                index1=i;
                f=true;
                break;
            }
            if(f) break;
        }
        // cout<<index1;
        if(index1==-1) return -1;
        swap(list[index],list[index1]);
        long long res=0;
        reverse(list.begin()+index+1,list.end());
        for(long long it:list){
            res=res*1LL*10 + it;
        }
        if (res > INT_MAX) return -1;
        if(res<=n1) return -1;
        return res;
    }
};