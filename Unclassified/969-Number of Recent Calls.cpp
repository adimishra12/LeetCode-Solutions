class RecentCounter {
    vector<int> r;
    int i = 0;;
public:

    RecentCounter() {
        
    }
    
    int ping(int t) {
        r.push_back(t);
        while(r[i] < t - 3000)
            i++;
        return r.size() - i;    
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */