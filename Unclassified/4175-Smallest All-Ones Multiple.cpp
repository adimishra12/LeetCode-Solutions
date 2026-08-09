class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2 == 0 || k%5 == 0)
        return -1;
        long long sum = 1;
        k*=9;
        for(int i = 0 ; i <= k/9 ; i++){
            sum=((sum*10)%k);
            if(sum == 1)
            return i+1;
        }
        return -1;
    }
};