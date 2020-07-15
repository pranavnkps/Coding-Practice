class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int count = 0;
        for(string word : words){
            bool flag = false;
            int pos = 0;
            for(char ch : word){
                auto temp = S.find(ch,pos);
                if(temp == string::npos){
                    flag = true;
                    break;
                }
                temp++;
                pos = temp;
            }
            if(flag == false)
                count++;
        }
        return count;
    }
};