class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        int n=s.size();
        // int c=0;
        for(int i=0;i<n;i++){
            if(s[i]==')')
            {
                int x=st.top();
                st.pop();
                int s=x==0?1:2*x;
                st.top()+=s;
            }else{
                st.push(0);
            }
        }
        return st.top();
    }
};