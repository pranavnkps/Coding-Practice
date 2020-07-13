class Solution {
public:
    int currentans;
    int minEatingSpeed(vector<int>& piles, int H) {
        int max = *max_element(piles.begin(), piles.end());
        recurse(piles,1,max,H);
        return currentans;
    }
    
    void recurse(vector<int> piles, int l, int r, int H){
        if(l == r){
            currentans = l;
            return;
        }
        int count = 0;
        int mid = (l+r)/2;
        for(int i = 0; i < piles.size(); ++i){
            count += (piles[i]-1)/mid + 1;
        }

        if(count <= H){
            //currentans = mid;
            recurse(piles,l,mid,H);
        }
        if(count > H)
            recurse(piles, mid+1,r,H);
    }
};