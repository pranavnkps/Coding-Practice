class Solution {
public:
    string customSortString(string S, string T) {
        sort(T.begin(), T.end(), [&S](char ch1, char ch2){return S.find(ch1) < S.find(ch2);});
        return T;
    }
};