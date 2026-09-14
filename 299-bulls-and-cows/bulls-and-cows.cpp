class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        vector<int> fS(10, 0);
        vector<int> fG(10, 0);

        for(int i = 0; i < secret.size(); i++)
        {
            if(secret[i] == guess[i])
                bulls++;
            else
            {
                fS[secret[i] - '0']++;
                fG[guess[i] - '0']++;
            }
        }
        int cows = 0;
        for(int i = 0; i < 10; i++)
            cows += min(fS[i], fG[i]);

        string ans = "";
        ans += to_string(bulls);
        ans += "A";
        ans += to_string(cows);
        ans += "B";
        return ans;
    }
};