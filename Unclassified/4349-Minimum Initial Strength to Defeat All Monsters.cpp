class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {

        vector<int> temp = monsters;

        int n = temp.size();

        vector<long long> diff(n + 1, 0);

        for (auto &b : boosts) {
            int l = b[0];
            int r = b[1];
            long long v = b[2];

            diff[l] += v;
            diff[r + 1] -= v;
        }

        vector<long long> bonus(n, 0);

        long long curBonus = 0;
        for (int i = 0; i < n; i++) {
            curBonus += diff[i];
            bonus[i] = curBonus;
        }

        auto can_defeat = [&](long long initial_strength) {
            long long current_strength = initial_strength;

            for (int i = 0; i < n; i++) {
                if (current_strength + bonus[i] < temp[i])
                    return false;

                current_strength = max(0LL, current_strength - temp[i]);
            }

            return true;
        };

        long long low = 0;
        long long high = 0;

        for (int x : temp)
            high += x;

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (can_defeat(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};