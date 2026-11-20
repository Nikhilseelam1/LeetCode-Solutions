class Solution {
public:
    int check(char ch){
        if(ch=='+') return 1;
        if(ch=='-') return 1;
        if(ch=='*') return 2;
        if(ch=='/') return 2;
        return 3;
    }
    int calculate(string s) {
        int n=s.size();
        stack<int>st;
        string s1="";
        for(int i=0;i<n;)
        {
            // char ch=s[i];
            if(s[i]==' '){
                i++;
                continue;
            }
            if(isdigit(s[i]))
            {
                while(i<n && isdigit(s[i]))
                {
                    s1+=s[i];
                    i++;
                }
                i--;
                s1+=' ';
            }else
            {
                while(!st.empty() && check(st.top()) >= check(s[i]))
                {
                    s1+=st.top();
                    s1+=' ';
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            s1+=st.top();
            s1+=' ';
            st.pop();
        }
        stack<long long>st1;
        for(int i=0;i<s1.size();){
            if(s1[i]==' '){
                i++;
                continue;
            }
            if(isdigit(s1[i]))
            {
                long long res=0;
                while(i<s1.size() && isdigit(s1[i]) ){
                    res=res*10 + s1[i]-'0';
                    i++;
                }
                i--;
                st1.push(res);
            }else{
                long long t1=st1.top();
                st1.pop();
                long long t2=st1.top();
                st1.pop();
                if(s1[i]=='+') st1.push((t1+t2));
                if(s1[i]=='-') st1.push(((t2-t1)));
                if(s1[i]=='*') st1.push((t1*t2));
                if(s1[i]=='/') st1.push((t2/t1));
            }
            i++;
        }
        return st1.top();
    }
};