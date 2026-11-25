class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int c=0;
        for(int i=0;i<32;i++)
        {
            int y = b & 1;
            int x = a & 1;
            if(x & y){
                if(c){
                    ans|=(1<<i);
                }else{
                    c=1;
                }
            }else{
                if(c){
                    if(!x && !y){
                        ans|=(1<<i);
                        c=0;
                    }else{
                        c=1;
                    }
                }else{
                    if(x || y){
                        ans|=(1<<i);
                    }
                    c=0;
                }
            }
            a=a>>1;
            b=b>>1;
        }
        return ans;
    }
};