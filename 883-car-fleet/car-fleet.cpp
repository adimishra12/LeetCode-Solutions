class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for(int i = 0; i < n; i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());
        stack<double> st;
        for(auto i : cars)
        {
            int p = i.first;
            int s = i.second;
            double t = (double)(target - p) / s;
            if(st.empty() || t > st.top())
                st.push(t);
        }   
        return st.size(); 
    }
};