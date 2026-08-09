class Solution {
public:
    int Difference_Seconds(string s)
    {
        return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        return Difference_Seconds(endTime) - Difference_Seconds(startTime);
    }
};