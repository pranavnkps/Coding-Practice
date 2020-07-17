class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long size = 0,i;
        string ans;
        for(i = 0; i < S.size(); ++i){
            if(isdigit(S[i]))
                size *= S[i] - '0';
            else
                size++;
        }
        i--;
        for(;i>=0;--i){
            if(isdigit(S[i])){
                size /= S[i]-'0';
                K = K%size;
            }
            else{
                if(K%size == 0)
                    return string(1,S[i]);
                size--;
            }
        }
        return ans;
    }
};