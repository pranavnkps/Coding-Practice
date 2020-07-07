//SOLUTION 1 -
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(auto it = asteroids.begin(); it != asteroids.end(); it++)
        {
            if(s.empty()){
                s.push(*it);
                continue;
            }
            int top = s.top();
            if(top > 0  && *it > 0){
                s.push(*it);
            }
            if(top < 0  && *it < 0){
                s.push(*it);
            }
            while(top > 0 && *it < 0){
                if(abs(top) == abs(*it)){
                    s.pop();
                    break;
                }
                if(abs(top) > abs(*it))
                    break;
                if(abs(top) < abs(*it)){
                    s.pop();
                    if(s.empty()){
                        s.push(*it);
                        break;
                    }
                    else
                        top = s.top();
                }
                if(top < 0)
                s.push(*it);
            }
            if(top < 0 && *it > 0)
                s.push(*it);

        }
        vector<int> ans(s.size());
        int len = s.size()-1;
        for(int i = len; i>=0;i--){
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};