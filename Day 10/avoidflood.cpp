class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), -1);
        map<int,int> mp;
        set<int> dry;
        
        for(int i = 0 ; i < rains.size(); ++i){
            if(rains[i] == 0){
                dry.insert(i);
                ans[i] = 1;
            }
            else{
                if(mp.find(rains[i]) != mp.end()){
                    auto it = dry.upper_bound(mp[rains[i]]);
                    if(it == dry.end())
                        return {};
                    ans[*it] = rains[i];
                    dry.erase(*it);
                }
                mp[rains[i]] = i;
                
            }
        }
        return ans;
    }
};