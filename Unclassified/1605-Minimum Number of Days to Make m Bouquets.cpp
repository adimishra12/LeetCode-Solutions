class Solution {
public:
        int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 1;
        int right = 1e9;
        int maxele = INT_MIN;
        if ((long long)m * k > bloomDay.size()) 
            return -1;
        if((long long)m * k == bloomDay.size())   
        {
            return *max_element(bloomDay.begin(), bloomDay.end());
        }


        while(left < right)
        {
            int mid = left + (right - left) / 2;
            int flower = 0, bouquet = 0;

            for (int j = 0; j < bloomDay.size(); j++) 
            {
                if (bloomDay[j] > mid) 
                    flower = 0;
                else if (++flower >= k) 
                {
                    bouquet++;
                    flower = 0;
                }
            }
            if (bouquet < m)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};