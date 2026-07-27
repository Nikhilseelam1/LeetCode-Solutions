class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int c;
    SeatManager(int n) {
        c=1;
        // for(int i=1;i<=n;i++) pq.push(i);
        pq.push(1);
    }
    
    int reserve() {
        // int x=pq.top();
        // pq.pop();
        // return x;
        int x=pq.top();
        c++;
        pq.pop();
        pq.push(c);
        return x;
    }
    
    void unreserve(int s) {
        pq.push(s);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */