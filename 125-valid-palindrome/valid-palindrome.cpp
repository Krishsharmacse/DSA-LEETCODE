class Solution {
public:
    bool isPalindrome(string s) {
    string l="";
        for( char c : s){
            if(isalnum(c)){
                l+=tolower(c);
            }
        }
        int left=0;
        int right=l.size()-1;
        while(left<right){
            if(l[left]!=l[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};