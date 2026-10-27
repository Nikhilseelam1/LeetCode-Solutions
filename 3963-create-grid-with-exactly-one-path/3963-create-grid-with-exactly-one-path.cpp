class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>nik;
        for(int i=0;i<m;i++){
            if(i==0){
                nik.push_back(string(n,'.'));
            }else{
                nik.push_back(string(n-1,'#') + '.');
            }
        }
        return nik;
    }
};