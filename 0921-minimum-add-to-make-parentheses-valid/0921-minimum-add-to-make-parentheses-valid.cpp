class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }else{
                if(st.empty()) ans++;
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans++;
            st.pop();
        }
        return ans;
    }
};