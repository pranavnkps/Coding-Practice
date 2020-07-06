#include <vector>
#include <iostream> 
using namespace std; 

class Solution { 
    public: int maxProfit(vector<int>& prices) { 
        int min = INT_MAX; 
        int max = 0; 
        int currentprof = 0; 
        for(auto it = prices.begin(); it != prices.end(); it++)
        { if(*it < min){ 
            min = *it; 
            max = 0; 
        } 
        if(*it > max) 
            max = *it; 
        if((max-min) > currentprof)
            currentprof = max-min;
        } 
        return currentprof;
    }
};