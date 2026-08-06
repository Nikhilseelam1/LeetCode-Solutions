class Solution {
public:
    bool check(int x,int t){
        int y=x;
        int res=1;
        while(y>0){
            int z=y%10;
            res=res*z;
            y/=10;
        }
        return (res%t==0);
    }
    int smallestNumber(int n, int t) {
        for(int i=n;;i++){
            while(check(i,t)){
                return i;
            }
        }
        return -1;
    }
};