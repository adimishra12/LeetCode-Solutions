class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> ans;
        int a = sides[0], b = sides[1], c = sides[2];
        if(a + b <= c || b + c <= a || c + a <= b) return {};
        double a1,a2,a3;
        a1 = acos((b*b + c*c - a*a) / (2.0*b*c)) * 180.0/M_PI;
        a2 = acos((a*a + b*b - c*c) / (2.0*a*b)) * 180.0/M_PI;
        a3 = 180.0 - a1 - a2;
        ans = {a1,a2,a3};
        sort(ans.begin(),ans.end());
        return ans;
    }
};