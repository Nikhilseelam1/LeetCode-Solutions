class Solution {
public:
        
    bool splitArraySameAverage(vector<int>& arr) {
        int n=arr.size();
        int n1=n/2;
        int n2=n-(n1);
        unordered_map<int,vector<int>>mp1;
        unordered_map<int,vector<int>>mp2;
        for(int mask=0;mask<(1<<n1);mask++){
            int c=0;
            int sum=0;
            for(int i=0;i<n1;i++){
                if((mask & (1<<i))){
                    sum+=arr[i];
                    c++;
                }
            }
            mp1[c].push_back(sum);
        }
        for(int mask=0;mask<(1<<n2);mask++){
            int c=0;
            int sum=0;
            for(int i=0;i<n2;i++){
                if((mask & (1<<i))){
                    sum+=arr[n1+i];
                    c++;
                }
            }
            mp2[c].push_back(sum);
        }
        
        int s=accumulate(arr.begin(),arr.end(),0);
        for(int i=0;i<=n2;i++){
            sort(mp2[i].begin(),mp2[i].end());
        }
        for(int i=0;i<=n1;i++){
            for(int left_s:mp1[i]){
                for(int j=0;j<=n2;j++){
                    int size=i+j;
                    if(size==0 || size==n) continue;
                    if(size*s % n != 0) continue;
                    int right_s=(size*s/n)-left_s;
                    if(binary_search(mp2[j].begin(),mp2[j].end(),right_s)) return true;
                }
            }
        }
        return false;
    }
};