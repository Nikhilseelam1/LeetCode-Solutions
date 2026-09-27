class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string s1 = "";
            if (s[i] == ')') {
                while (!st.empty() && st.top() != "(") {
                    s1 += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
                reverse(s1.begin(),s1.end());
                st.push(s1);
            }
            else {
                st.push(string(1, s[i]));
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};