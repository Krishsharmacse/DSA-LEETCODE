class Solution {
public:
    string getindex(string s){
        unordered_map<char,int>mp;
        string sb="";
        for(int i =0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                mp.insert({s[i],i});
               
            }
             sb+=to_string(mp[s[i]])+" ";

            
        }
        return sb;

    }
    bool isIsomorphic(string s, string t) {
           if (s.length() != t.length()) {
            return false;
        }
        return getindex(s)==getindex(t);
    }
};