#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int count[n];
        count[1] = 1;
        count[2] = 2;
        for(int i = 3; i<=n; i++)
            count[i] = count[i-2]+count[i-1];
        return count[n];
    }
};