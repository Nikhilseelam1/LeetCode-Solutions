class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        sort(i.begin(),i.end(),[](const auto &a,const auto &b){
            // if(a[0]==b[0]) return a[1]<b[1];
            return a[1]<b[1];
        });
        int n=i.size();
        int x=i[0][1];
        int c=0;
        for(int j=1;j<n;j++){
            int y=i[j][0];
            if(x>y){
                c++;
            }else{
                x=i[j][1];
            }
        }
        return c;
    }
};