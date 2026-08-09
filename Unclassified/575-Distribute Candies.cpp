class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());
        int j = 1;
        int candynow = candyType[0];
        for(int i = 1; i < candyType.size(); i++)
        {
            if(candynow != candyType[i])
            {
                candynow = candyType[i];
                j++;
            }
        }
        return min((int)candyType.size() / 2, j);
    }
};