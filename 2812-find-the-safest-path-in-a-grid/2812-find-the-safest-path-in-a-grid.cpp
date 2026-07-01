#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<int>rows={0,1,0,-1};
    vector<int>cols={1,0,-1,0};
    vector<vector<int>>safety;
    int n;
    void bfs(vector<vector<int>>&grid){
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    safety[i][j]=0;
                    vis[i][j]=1;
                    pq.push({0,{i,j}});
                }
            }
        }
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int w=it.first;
            int r=it.second.first;
            int c=it.second.second;
            // if(w>safety[r][c]) continue;
            for(int i=0;i<4;i++){
                int ri=r+rows[i];
                int cj=c+cols[i];
                if(ri<n && cj<n && cj>=0 && ri>=0 && !vis[ri][cj]){
                    vis[ri][cj]=1;
                    safety[ri][cj]=w+abs(r-ri) + abs(c-cj);
                    pq.push({safety[ri][cj],{ri,cj}});
                }
            }
        }
    }
    bool bfs2(int mid){
        // cout<<mid<<" ";
        // cout<<endl;
        vector<vector<int>>safety1=safety;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(safety1[i][j]<mid){
                    safety1[i][j]=-1;
                }
            }
        }
        queue<pair<int,int>>q;
        if(safety1[0][0]!=-1) q.push({0,0});
        vector<vector<int>>vis(n,vector<int>(n,0));
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            // cout<<r<<" "<<c<<" ";
            // cout<<endl;
            if(r==n-1 && c==n-1) return true;
            for(int i=0;i<4;i++){
                int ri=r+rows[i];
                int cj=c+cols[i];
                if(ri<n && cj<n && cj>=0 && ri>=0 && !vis[ri][cj] && safety1[ri][cj]!=-1){
                    vis[ri][cj]=1;
                    q.push({ri,cj});
                }
            }
        }
        // cout<<endl;
        return false;
    }
    // 2 -1 -1
    // 3 2 -1
    // 4 3 2
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        safety.resize(n,vector<int>(n,0));
        bfs(grid);
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi,safety[i][j]);
                mini=min(mini,safety[i][j]);
            }
        }
        int ans=0;
        while(mini<=maxi){
            int mid=mini + (maxi-mini)/2;
            if(bfs2(mid)){
                ans=mid;
                mini=mid+1;
            }else{
                maxi=mid-1;
            }
        }
        return ans;
    }
};