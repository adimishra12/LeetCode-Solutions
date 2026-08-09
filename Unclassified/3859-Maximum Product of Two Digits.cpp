class Solution {
public:
    int maxProduct(int n) {
        int d = 0;
        int prod = 1;
        vector<int> a;
        while (n > 0)
        {
            d = n % 10;
            a.push_back(d);
            n /= 10;
        }
        sort(a.begin(), a.end());

        return a[a.size() - 1] * a[a.size() - 2];
    }
};