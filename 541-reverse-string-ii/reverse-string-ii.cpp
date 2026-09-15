class Solution {
public:
    string reverseStr(string s, int k) {
        string result = "";
        stack<char> st;
        int n = s.length();
        
        for (int i = 0; i < n; i += 2 * k) {
          
            int first_k_end = min(i + k, n);
            for (int j = i; j < first_k_end; j++) {
                st.push(s[j]);
            }
            
           
            while (!st.empty()) {
                result += st.top(); 
                st.pop();
            }
            
           
            int second_k_end = min(i + 2 * k, n);
            for (int j = first_k_end; j < second_k_end; j++) {
                result += s[j];
            }
        }
        
        return result;
    }
};