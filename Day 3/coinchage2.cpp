class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0 )
            return 1;
        if(coins.empty())
            return 0;
        vector<vector<int> > dp(coins.size(), vector<int>(amount+1, 0));
        for(int i = 0; i < coins.size(); ++i){
            for(int j = 0; j <= amount; ++j){
                if(j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if(i-1 >= 0)
                {   
                    if(j<coins[i])
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
                }
                else if(j-coins[i] >= 0){
                    dp[i][j] = dp[i][j-coins[i]];
                }
            }
        }
        return dp[coins.size()-1][amount];
    }
};