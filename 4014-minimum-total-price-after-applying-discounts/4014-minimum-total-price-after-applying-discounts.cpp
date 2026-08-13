class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& d) {
        sort(prices.rbegin(),prices.rend());
        sort(d.rbegin(),d.rend());
        double ans=0.0;
        int n=prices.size();
        int m=d.size();
        int i=0;
        int j=0;
        while(i<n && j<m){
            ans+= ((double)prices[i] * (100-d[j]))/100;
            j++;
            i++;
        }
        while(i<n){
            ans+=prices[i];
            i++;
        }
        return ans;
    }
};