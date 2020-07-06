class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(int i =0; s[i] != '\0'; i++){
            if(st.empty()){
                if(s[i] == '{' || s[i] == '[' || s[i] == '(')
                    st.push(s[i]);
                else return false;
            }
            
            else{
                if(s[i] == '{' || s[i] == '[' || s[i] == '(')
                    st.push(s[i]);
                else if((st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']') || (st.top() == '(' && s[i] == ')'))  
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};