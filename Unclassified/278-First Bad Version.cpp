// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        while(left <= n)
        {
            int mid = left + (n - left) / 2;
            if(isBadVersion(mid))
                n = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};