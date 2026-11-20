class Solution {
public:
    bool canMeasureWater(int x, int y, int t) {
        queue<pair<int,int>>q;
        q.push({0,0});
        set<pair<int,int>>st;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x1=it.first;
            int y1=it.second;
            if(st.find({x1,y1})!=st.end()) continue;
            st.insert({x1,y1});
            if(x1+y1==t || y1==t || x1==t) return true;
            int pour = min(x1, y - y1);
            q.push({x1 - pour, y1 + pour});
            int pour1 = min(x-x1,y1);
            q.push({x1+pour1, y1-pour1});
            q.push({x1,0});
            q.push({0,y1});
            q.push({x,y1});
            q.push({x1,y});
        }
        return false;
    }
};