class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>vec(n+1,vector<int>(26,0));
        for(int i=0;i<n;i++)
        {   
            string s=words[i];
            for(int j=0;j<s.size();j++){
                vec[i][s[j]-'a']++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>arr=vec[i];
            for(int j=i+1;j<n;j++){
                vector<int>arr1=vec[j];
                bool f=false;
                for(int k=0;k<26;k++){
                    if(arr[k]>0 && arr1[k]>0 && arr1[k] && arr[k]){
                        f=true;
                        break;
                    }
                }
                if(!f){
                    ans=max(ans,(int)words[i].size()* (int)words[j].size());
                }
            }
        }
        return ans;
    }
};