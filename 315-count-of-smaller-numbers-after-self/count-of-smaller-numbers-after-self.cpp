class Solution {
public:
    void merge(vector<pair<int, int>>& a, int low, int mid, int high,
               vector<int>& count)
    {
        vector<pair<int, int>> temp;

        int left = low;
        int right = mid + 1;
        int smaller = 0;

        while(left <= mid && right <= high)
        {
            if(a[left].first <= a[right].first)
            {
                count[a[left].second] += smaller;
                temp.push_back(a[left]);
                left++;
            }
            else
            {
                temp.push_back(a[right]);
                right++;
                smaller++;
            }
        }

        while(left <= mid)
        {
            count[a[left].second] += smaller;

            temp.push_back(a[left]);
            left++;
        }

        while(right <= high)
        {
            temp.push_back(a[right]);
            right++;
        }

        for(int i = low; i <= high; i++)
            a[i] = temp[i - low];
    }

    void mergesort(vector<pair<int, int>>& a, int low, int high,
                   vector<int>& count)
    {
        if(low >= high)
            return;

        int mid = (low + high) >> 1;

        mergesort(a, low, mid, count);
        mergesort(a, mid + 1, high, count);
        merge(a, low, mid, high, count);
    }

    vector<int> countSmaller(vector<int>& nums)
    {
        int n = nums.size();
        vector<pair<int, int>> a;

        for(int i = 0; i < n; i++)
            a.push_back({nums[i], i});
        vector<int> count(n, 0);

        mergesort(a, 0, n - 1, count);

        return count;
    }
};