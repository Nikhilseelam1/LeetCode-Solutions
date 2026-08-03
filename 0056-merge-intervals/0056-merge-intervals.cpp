class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
       sort(i.begin(),i.end(),[](const auto & a,const auto & b){
            return a[0]<b[0];
       });
       vector<vector<int>>vec;
       int n=i.size();
       vec.push_back({i[0][0],i[0][1]});
       for(int j=1;j<n;j++){
        if(i[j][0]<=vec.back()[1]){
            vec.back()[1]=max(vec.back()[1],i[j][1]);
        }else{
            vec.push_back({i[j][0],i[j][1]});
        }
       }
       return vec;
    }
};