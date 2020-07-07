class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        //else if(amount < *max_element(coins.begin(), coins.end()))
          //  return -1;
        int min;
        vector<int> dp(amount+1, 0);
        for(int i = 1;i<=amount;++i){
            min = INT_MAX;
                for(int x:coins){
                    if((i-x) < 0 || dp[i-x] == -1){
                        dp[i] = -1;
                        continue;
                    }
                    if((dp[i-x]+1) < min)
                        min = dp[i-x]+1;
                }
                if(min == INT_MAX)
                    dp[i] = -1;
                else
                    dp[i] = min;

            }
        return dp[amount];
    }
};