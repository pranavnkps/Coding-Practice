class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        set<char> st;
        int flag = 0;
        unordered_map<char,char> mp;
        for(string word : words){
            flag = 0;
            mp.clear();
            st.clear();
            for(int i = 0 ; i < word.size(); ++i){
               auto it = mp.find(pattern[i]);
               if(it != mp.end()){
                   if(it->second == word[i])
                       continue;
                   else{
                       flag = 1;
                       break;
                   }
               }
               else{
                   //auto oldsize = st.size();
                   //st.insert(word[i]);
                   if(st.find(word[i]) != st.end()){
                       flag = 1;
                       break;
                   }
                       st.insert(word[i]);  
                       mp.insert({pattern[i], word[i]});
               }
                  
            }
            if(flag == 0)
                ans.push_back(word);
        }
        return ans;
    }
};