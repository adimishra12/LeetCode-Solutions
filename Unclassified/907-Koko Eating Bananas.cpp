class Solution {
public:
    long long helper(vector<int>& piles, int h)
    {
        long long hrs = 0;
        for(int i = 0; i < piles.size(); i++)
            hrs += ceil((double)piles[i] / h);
        return hrs;    
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxpiles = INT_MIN; long long speed;
        for(int i : piles)
        {
            maxpiles = max(maxpiles, i);
        }
        int left = 1;
        int right = maxpiles;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            long long hrs = helper(piles, mid);

            if(hrs <= h)
            {
                speed = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return speed;
    }
};