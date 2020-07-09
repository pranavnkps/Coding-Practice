//SOLUTION 1 - DP

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T+1, T+1);
        dp[0] = 0;
        for(int i =1; i<= T; i++){
            for(auto clip : clips){
                if(i >= clip[0] && i <= clip[1])
                    dp[i] = min(dp[clip[0]]+1, dp[i]);
            }
        }
        if(dp[T] == T+1)
            return -1;
        return dp[T];
    }
};

/* SOLUTION 2 - CAN USE GREEDY ALSO
Take clips with maximum ends at time one by one
For example, clips = [[0,2],[4,6],[0,1],[8,10],[1,9],[1,5],[5,9],[1,3]], T = 10
Let's set start=0

1. We take [0,2], because it has maximum ends time between the clips ([0,2],[0,1]) whose starts are smaller or equal to start (which is 0 by now). set start=2 end time of the selected clip([0,2])

2. Now we take [1,9], since it has maximum ends time (9) between the clips whose starts are smaller or equal to start (which is 2 by now). set start=9

3. Finally, we take [8,10] with the same reason above.
Result is 3.
*/