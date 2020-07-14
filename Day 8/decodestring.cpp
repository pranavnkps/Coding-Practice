class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string temp = "", intermediate = "", ans, num,temp1;
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); ++i){
        //for(char ch : s){  
            if(st.empty() && isalpha(s[i])){
                ans = s[i] + ans;
                continue;
            }
            if(s[i] == ']'){
                st.push(s[i]);
            }
            else if(isalpha(s[i]))
                st.push(s[i]);
            else if(s[i] == '['){
                intermediate = "";
                while(st.top() != ']'){
                    intermediate += st.top();
                    st.pop();
                }
                //temp = intermediate + temp;
                st.pop(); // pops ]
                num = "";
                while(s[i+1] >= '0' && s[i+1] <= '9'){
                    i++;
                    num = s[i] + num;
                }
                temp1 = "";
                for(int j = 0 ; j < stoi(num); ++j){
                    temp1 += intermediate; 
                }
                intermediate = temp1;
                if(st.empty()){
                    ans = intermediate + ans;
                }
                else{
                    reverse(intermediate.begin(), intermediate.end());
                    for(char ch : intermediate)
                    st.push(ch);
                }
                
            }
            
        }
        return ans;
    }//"3[a]2[b4[F]c]"
};