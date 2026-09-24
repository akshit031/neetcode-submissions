class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        int i = 0;
        
        while (i < n) {
            char curr = s[i];
            if (curr == '(' || curr == '{' || curr == '[') {
                st.push(curr);
            } 
            else {
                if (st.empty()) return false;
                char top = st.top();
                if ((curr == ')' && top != '(') || 
                    (curr == '}' && top != '{') || 
                    (curr == ']' && top != '[')) {
                    return false;
                }
                st.pop();
            }
            i++;
        }
        return st.empty();
    }
};
