class Solution {
public:
    bool checkString(string s) {
        int a_c,b_c=0;
        for(char ch:s){
            if(ch=='a') a_c++;
            else b_c++;
        }
        if(a_c==0) return true;
        int b_s=b_c;
        for(char ch:s){
            if(ch=='a'){
                if(b_s!=b_c) return false;
            }else b_s--;
        }
        return true;
    }
};