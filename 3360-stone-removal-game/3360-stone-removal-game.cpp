class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        n-=10;
        bool f=true;
        int x=9;
        while(n>0){
            if(n<x) return f;
            n-=x;
            f=!f;
            x--;
        }
        return f;
    }
};