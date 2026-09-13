class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size())
            return s;

        vector<string> arr(numRows); // humne string create kr li hai each row ke liye
        int r = 0;
        int down = false;

        for(int i = 0; i < s.size(); i++)
        {
            arr[r] += s[i]; // char add kro row me
            if(r == 0 || r == numRows - 1)
                down = !down; // direction change kro agar top ya bottom pohoch jao to
            
            // jo bhi abhi tumahri direction hai uske acc upar ya neeche jao
            if(down)
                r++;
            else
                r--;    
        }  
        string ans; // final string banao sari string jod ke aur return kr do
        for(string str : arr) 
            ans += str;

    return ans;
    }
};