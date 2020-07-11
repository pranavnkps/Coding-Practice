class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        int flag;
        vector<int> count(26), temp(26);
        for(string word : B){
            temp = countchar(word);
            for(int i = 0; i<26; i++){
                count[i] = max(temp[i], count[i]);
            }
        }
        for(string word : A){
            flag = 0;
            temp = countchar(word);
            for(int i = 0 ; i<26; ++i){
               // if(count[i] == 0)
                 //   continue;
                if(temp[i] < count[i]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                ans.push_back(word);
        }
        return ans;

    }
    vector<int> countchar(string str){
        vector<int> cnt(26);
        for(char c : str){
            cnt[c-'a']++;
        }
        return cnt;
    }
};