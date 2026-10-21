class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int x=sum;
        string s="";
        for(int i=0;i<num;i++){
            int d=min(x,9);
            s.push_back(d +'0');
            x=x-d;
        }
        if(x<=0) return s;
        return "";
    }
};