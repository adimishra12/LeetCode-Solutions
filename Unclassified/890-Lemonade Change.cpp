class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ten = 0;
        int five = 0;
        for(int rupee : bills)
        {
            if (rupee == 5)
                five++;
            else if (rupee == 10)
            {
                if(five > 0)
                {
                    ten++;
                    five--;
                }
                else 
                    return false;
            }  
            else
            {
                if (five > 0 && ten > 0)
                {
                    ten--;
                    five--;
                }
                else if (five > 2)
                    five = five - 3;
                else 
                    return false;    
            }  
        }
        return true;
    }
};