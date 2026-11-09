class Solution {
public:
    bool check(char ch){
        return ch >= 'a' && ch <= 'z';
    }
    string reverseParentheses(string s) {
        stack<string>st;
        int n=s.size();
        for(int i=0;i<n;){
            if(s[i]=='('){
                st.push("(");
                i++;
            }else{
                string x="";
                if(check(s[i])){
                    while(i<n && check(s[i]))
                    {
                        x+=s[i];
                        i++;
                    }
                    st.push(x);
                }else{
                    if(!st.empty())
                    {
                        string x1="";
                        while(!st.empty() && st.top()!="("){
                            x1=st.top() + x1;
                            st.pop();
                        }
                        reverse(x1.begin(),x1.end());
                        if(!st.empty()) st.pop();
                        st.push(x1);
                    }
                    i++;
                }
            }
        }
        if(!st.empty() && st.top()=="(") st.pop();
        string ans = "";

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};